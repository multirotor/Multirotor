

AUTOMAKE_OPTIONS  = subdir-objects


#AM_LDFLAGS = -T../src/STM32F411RE_FLASH.ld


bin_PROGRAMS = flight_ctrl


flight_ctrl_LDFLAGS = -T../src/STM32F411RE_FLASH.ld -L/usr/local/arm-none-eabi/lib -lopencm3_stm32f4 -DSTM32F4

flight_ctrl_SOURCES = src/main.cpp src/startup_stm32f411xe.s 

#LDFLAGS = -L/usr/local/arm-none-eabi/lib -lopencm3_stm32f4

