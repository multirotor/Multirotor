CC=gcc-arm-none-eabi/bin/arm-none-eabi-gcc.exe
CFLAGS=-Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -mthumb-interwork -c -Os -g
CFLAGSLD= -mcpu=cortex-m4 -mlittle-endian -mthumb -mthumb-interwork
LDFLAGS=-TInc/STM32F411RE_FLASH.ld -Wl,--gc-sections
INCLUDE=-IInc -ICMSIS/Include
DEFINES=-DSTM32F411xE
EXEC=build\blinkled.elf

all: build\system.o build\main.o build\startup_stm32f411xe.o
	$(CC) $(CFLAGSLD) $(DEFINES) $(LDFLAGS) build\main.o build\startup_stm32f411xe.o build\system.o -o ${EXEC}

build\main.o: src\main.c
	$(CC) $(CFLAGS) $(INCLUDE) $(DEFINES) src\main.c -o build\main.o

build\system.o: src\system.c
	mkdir build 
	$(CC) $(CFLAGS) $(INCLUDE) $(DEFINES) src\system.c -o build\system.o

build\startup_stm32f411xe.o: src\startup_stm32f411xe.s
	$(CC) $(CFLAGS) $(INCLUDE) $(DEFINES) src\startup_stm32f411xe.s -o build\startup_stm32f411xe.o

clean:

	