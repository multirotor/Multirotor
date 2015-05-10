/*
*
* Copyright (C) Patryk Jaworski <regalis@regalis.com.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
*/
//#include <stm32f4xx.h>
// Board LED is bit 5 of port A.
#define LED_PIN 5
//#define LED_ON() GPIOA->BSRRL |= (1 << 5)
//#define LED_OFF() GPIOA->BSRRH |= (1 << 5)
#define LED_TOGGLE() GPIOA->ODR ^= (1 << 5)


#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

//Quick hack, approximately 1ms delay
void ms_delay(int ms) {
   while (ms-- > 0) {
      volatile int x=5971;
      while (x-- > 0)
         __asm("nop");
   }
}
int main() {

	int i = 0;

	rcc_periph_clock_enable(RCC_GPIOA);

	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);

	while(1)
	{	
		/* Using API function gpio_toggle(): */
		gpio_toggle(GPIOA, GPIO5);	/* LED on/off */
		for (i = 0; i < 1000000; i++) {	/* Wait a bit. */
			__asm__("nop");
		}
	}
	// Enable GPIOA clock.
	// RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	// Configure GPIOA pin 5 as output.
        //GPIOA->MODER |= (1 << (LED_PIN << 1));
	// Configure GPIOA pin 5 in max speed.
	//GPIOA->OSPEEDR |= (3 << (LED_PIN << 1));
	// Turn on the LED.
	//LED_ON();
  // Blink LED.
//TEST
//  while(1) {
//    ms_delay(200);
	//LED_TOGGLE();
//  }


}
