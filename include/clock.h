/*
 * clock.h
 *
 *  Created on: Jun 1, 2015
 *      Author: martin
 */

#ifndef INCLUDE_CLOCK_H_
#define INCLUDE_CLOCK_H_

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>


class Clock_Manager
{


public:

	void setup(const clock_scale_t *clock);

private:


};




#endif /* INCLUDE_CLOCK_H_ */
