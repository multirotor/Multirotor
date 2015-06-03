

AUTOMAKE_OPTIONS  = subdir-objects

bin_PROGRAMS = flight_ctrl

#AM_LDFLAGS = -li2c_wrapper -T../src/STM32F411RE_FLASH.ld

flight_ctrl_SOURCES = src/main.cpp src/clock.cpp src/uart_handler.cpp src/startup_stm32f411xe.s 

flight_ctrl_LDFLAGS = -T../src/STM32F411RE_FLASH.ld
flight_ctrl_LDADD = -li2c_wrapper

