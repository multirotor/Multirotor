/*
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


#define MPU9150_WHO_AM_I           0x75   // R

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/usart.h>


#include "clock.h"
#include "uart_wrapper.h"
#include "I2CWrapper.h"


Clock_Manager Clk_Mgr;
UARTWrapper Uart_Mgr;
I2CWrapper i2c_mpu9150(I2C1);


/* for USB a USB clock of 48MHz is needed */
const clock_scale_t hsi_8mhz_3v3 = {
		16, 													//.pllm
		336, 													//.plln
		4, 														//.pllp
		7, 														//.pllq
		FLASH_ACR_ICE | FLASH_ACR_DCE |	FLASH_ACR_LATENCY_3WS, 	//.flash_config
		RCC_CFGR_HPRE_DIV_NONE, 								//.hpre
		RCC_CFGR_PPRE_DIV_4, 									//.ppre1
		RCC_CFGR_PPRE_DIV_2, 									//.ppre2
		1, 														//.power_save
		(uint32_t)21000000, 									//.apb1_frequency
		(uint32_t)42000000, 									//.apb2_frequency
};


void gpio_setup(void)
{
	/* gpio setup for blink LED */
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);

	/* Setup GPIO pins for USART2 transmit. */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2 | GPIO3);

	/* Setup USART2 TX pin as alternate function. */
	gpio_set_af(GPIOA, GPIO_AF7, GPIO2 | GPIO3);

}



int main() {

	uint8_t byte_read = 0;

	Clk_Mgr.setup(&hsi_8mhz_3v3);
	Uart_Mgr.setup();
	i2c_mpu9150.setup();
	gpio_setup();


	while(1)
	{	
		uint16_t result = 0;

		uint16_t uart_rx_byte = 0;
		
		/* wait for user to put in a character and write it back to uart */
		Uart_Mgr.get_rx_data(&uart_rx_byte);
		Uart_Mgr.send_tx_word(&uart_rx_byte);


		/* toggle led */
		gpio_toggle(GPIOA, GPIO5);	/* LED on/off */

		/* read WHO AM I register
		 * should return 0x68
		 */
		result = i2c_mpu9150.readBytes(0x68, MPU9150_WHO_AM_I, &byte_read);

		usart_send_blocking(USART2, byte_read);

	}


}
