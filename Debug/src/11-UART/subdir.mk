################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/11-UART/ComunicacionAsincronica.cpp \
../src/11-UART/swm.cpp \
../src/11-UART/uart.cpp 

CPP_DEPS += \
./src/11-UART/ComunicacionAsincronica.d \
./src/11-UART/swm.d \
./src/11-UART/uart.d 

OBJS += \
./src/11-UART/ComunicacionAsincronica.o \
./src/11-UART/swm.o \
./src/11-UART/uart.o 


# Each subdirectory must supply rules for building sources it contributes
src/11-UART/%.o: ../src/11-UART/%.cpp src/11-UART/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"D:\Desktop\Proyecto Info 2\AccessIO\src" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\02bis-intext" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\01-pin\out" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\02-gpio" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\03-callback" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\aplicacion" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\firmware" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\06-timer" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\07-timers" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\01-pin\in" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos\09A-barrido" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos\09A-barrido\barrido-interfaz" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos\09B-segmentos" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos\09B-segmentos\segmentos-interfaz" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos\09C-display" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\08-teclado" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\04-EntradasDigitales" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\05-SalidasDigitales" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\10-LCD" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\11-UART" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-11-2d-UART

clean-src-2f-11-2d-UART:
	-$(RM) ./src/11-UART/ComunicacionAsincronica.d ./src/11-UART/ComunicacionAsincronica.o ./src/11-UART/swm.d ./src/11-UART/swm.o ./src/11-UART/uart.d ./src/11-UART/uart.o

.PHONY: clean-src-2f-11-2d-UART

