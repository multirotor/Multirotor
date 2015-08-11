/*
 * pwmout.cpp
 *
 *  Created on: 10 aug. 2015
 *      Author: Jonathan Waldsjö
 */
#include "pwmout.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>


PwmOut::PwmOut(uint32_t timer, enum tim_oc_id channel, uint32_t port, uint16_t gpio_pin, uint32_t frequency, uint16_t duty_cycle_ms)
{
	// Enable clock of timer
	switch(timer)
	{
	case TIM3:
		rcc_periph_clock_enable(RCC_TIM3);
		break;
	case TIM4:
		rcc_periph_clock_enable(RCC_TIM4);
		break;
	case TIM5:
		rcc_periph_clock_enable(RCC_TIM5);
		break;
	default:
		// TODO Handle errors more gracefully
		return;
	}

	this->timer = timer;
	this->duty_cycle_ms = duty_cycle_ms;
	this->channel = channel;

	// Timer is No Divider, Alignment Edge, Count Upwards
	timer_set_mode(timer, TIM_CR1_CKD_CK_INT,
		       TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);

	timer_continuous_mode(timer);
	timer_set_period(timer, (1000000 / frequency));
	timer_set_prescaler(timer, (rcc_apb2_frequency/1000000));

	timer_set_clock_division(timer, 0);
	timer_set_master_mode(timer, TIM_CR2_MMS_UPDATE);
	timer_enable_preload(timer);

	timer_set_oc_value(timer, channel, duty_cycle_ms);
	timer_set_oc_mode(timer, channel, TIM_OCM_PWM1);
	timer_enable_oc_preload(timer, channel);
	timer_set_oc_polarity_high(timer, channel);
	timer_enable_oc_output(timer, channel);


	// Enable port clock
	switch(port)
	{
	case GPIOA:
		rcc_periph_clock_enable(RCC_GPIOA);
		break;
	case GPIOB:
		rcc_periph_clock_enable(RCC_GPIOB);
		break;
	default:
		// TODO Handle errors more gracefully
		return;
	}

	gpio_mode_setup(port, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
	gpio_set_af(port, GPIO_MODE_AF, gpio_pin);

    timer_enable_counter(timer);
}

void PwmOut::set(uint16_t duty_cycle_ms)
{
	this->duty_cycle_ms = duty_cycle_ms;
	timer_set_oc_value(this->timer, this->channel, duty_cycle_ms);
}

uint16_t PwmOut::get() const
{
	return this->duty_cycle_ms;
}



