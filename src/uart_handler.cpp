/*
 * uart_handler.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: martin
 */

#include "uart_handler.h"

#include <libopencm3/stm32/usart.h>

void Uart_Handler::setup(void)
{
	/* Setup USART2 parameters. */
	usart_set_baudrate(USART2, 115200);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX_RX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART2);
}

void Uart_Handler::receive(void)
{

	rx_data = usart_recv_blocking(USART2);


}

uint16_t Uart_Handler::get_rx_data(void)
{

	receive();

	return rx_data;

}
