/*
 * UARTWrapper.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: martin
 */

#include "uart_wrapper.h"

#include <libopencm3/stm32/usart.h>


uint16_t rx_word;
uint16_t tx_word;



void UARTWrapper::setup(void)
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

void UARTWrapper::receive_word(void)
{
	rx_word = usart_recv_blocking(USART2);
}

void UARTWrapper::send_word(void)
{
	usart_send_blocking(USART2, tx_word);
}


void UARTWrapper::get_rx_data(uint16_t* rx_word_buffer)
{
	receive_word();

	*rx_word_buffer = rx_word;
}

void UARTWrapper::send_tx_word(uint16_t* word_to_tx)
{
	tx_word = *word_to_tx;

	send_word();
}
