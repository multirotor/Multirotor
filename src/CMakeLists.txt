cmake_minimum_required (VERSION 2.6)

enable_language(ASM)

include(CMakeForceCompiler)

set(CMAKE_SYSTEM_NAME Generic)

# must be set before "project"
CMAKE_FORCE_C_COMPILER(arm-none-eabi-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(arm-none-eabi-g++ GNU)

# to compile any assembler parts of the startup script
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)


project (blinkled)

set(CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m4 -Wall -mfloat-abi=hard -mfpu=fpv4-sp-d16 -g" CACHE INTERNAL "c compiler flags")
set(CMAKE_ASM_FLAGS "-mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -g" CACHE INTERNAL "asm compiler flags")


#add_definitions(-DSTM32F411xE)

# needed by libopencm3
add_definitions(-DSTM32F4)



include_directories("${PROJECT_SOURCE_DIR}/../include/")
include_directories("${PROJECT_SOURCE_DIR}/../CMSIS/Include")
include_directories("/usr/local/arm-none-eabi/include")


add_executable(blinkled startup_stm32f411xe.s main.c)

target_link_libraries(blinkled /usr/local/arm-none-eabi/lib/libopencm3_stm32f4.a)

set(CMAKE_EXE_LINKER_FLAGS "-T ${PROJECT_SOURCE_DIR}/../include/STM32F411RE_FLASH.ld -Wl,--gc-sections -mfloat-abi=hard ")

