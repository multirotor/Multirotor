/*
 * uart_handler.h
 *
 *  Created on: Jun 1, 2015
 *      Author: martin
 */

#ifndef INCLUDE_UART_HANDLER_H_
#define INCLUDE_UART_HANDLER_H_

#include <stdint.h>

class UARTWrapper
{


public:

	void setup();
	void get_rx_data(uint16_t* rx_word_buffer);
	void send_tx_word(uint16_t* word_to_tx);


private:

	void receive_word(void);
	void send_word(void);


};


#endif /* INCLUDE_UART_HANDLER_H_ */
