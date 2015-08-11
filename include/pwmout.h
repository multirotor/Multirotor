/*
 * pwmout.h
 *
 *  Created on: 10 aug. 2015
 *      Author: Jonathan Waldsjö
 */
#include <libopencm3/stm32/timer.h>

#ifndef INCLUDE_PWMOUT_H_
#define INCLUDE_PWMOUT_H_

class PwmOut {
private:
	uint16_t duty_cycle_ms;
	uint32_t timer;
	enum tim_oc_id channel;

public:
	PwmOut(uint32_t timer, enum tim_oc_id channel, uint32_t port, uint16_t gpio_pin, uint32_t frequency, uint16_t duty_cycle_ms);
	~PwmOut();

	// Set a value to the channel
	void set(uint16_t value);

	// Get the last set value from channel
	uint16_t get() const;
};

#endif /* INCLUDE_PWMOUT_H_ */
