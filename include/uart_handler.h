/*
 * uart_handler.h
 *
 *  Created on: Jun 1, 2015
 *      Author: martin
 */

#ifndef INCLUDE_UART_HANDLER_H_
#define INCLUDE_UART_HANDLER_H_

#include <stdint.h>

class Uart_Handler
{

	uint16_t rx_data;

public:

	void setup();
	uint16_t get_rx_data();
	void receive();

private:





};


#endif /* INCLUDE_UART_HANDLER_H_ */
