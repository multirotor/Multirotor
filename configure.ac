
AC_PREREQ([2.69])
AC_INIT([flight_ctrl], [0.1], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])



MACHINE="-DSTM32F4"

CXXFLAGS="$CXXFLAGS -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -g -I/usr/local/arm-none-eabi/include -I../include -I/usr/local/include $MACHINE -nostdlib -fno-exceptions -fno-rtti"

CFLAGS="$CFLAGS -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -g -I/usr/local/arm-none-eabi/include -I../include -I/usr/local/include $MACHINE -nostdlib"

LDFLAGS="$LDFLAGS -L/usr/local/arm-none-eabi/lib -L/usr/local/lib -mfloat-abi=hard -mfpu=fpv4-sp-d16"

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_AS


# Checks for libraries.
AC_SEARCH_LIBS([rcc_periph_clock_enable], [opencm3_stm32f4], [], [
		  AC_MSG_ERROR([unable to find the opencm lib])
		  ])



# Checks for header files.
AC_CHECK_HEADERS([libopencm3/stm32/rcc.h i2c_wrapper.h])


AC_CONFIG_FILES([
		 Makefile
		 ])

AC_OUTPUT
