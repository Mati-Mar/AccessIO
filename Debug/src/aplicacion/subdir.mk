################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/aplicacion/inicializarInfotronic.cpp \
../src/aplicacion/main.cpp \
../src/aplicacion/secuencia.cpp 

CPP_DEPS += \
./src/aplicacion/inicializarInfotronic.d \
./src/aplicacion/main.d \
./src/aplicacion/secuencia.d 

OBJS += \
./src/aplicacion/inicializarInfotronic.o \
./src/aplicacion/main.o \
./src/aplicacion/secuencia.o 


# Each subdirectory must supply rules for building sources it contributes
src/aplicacion/%.o: ../src/aplicacion/%.cpp src/aplicacion/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"D:\Desktop\Proyecto Info 2\AccessIO\src" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\02bis-intext" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\01-pin\out" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\02-gpio" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\03-callback" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\aplicacion" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\firmware" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\06-timer" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\07-timers" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\01-pin\in" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos\09A-barrido" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos\09A-barrido\barrido-interfaz" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos\09B-segmentos" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos\09B-segmentos\segmentos-interfaz" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\09-display_de_segmentos\09C-display" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\08-teclado" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\04-EntradasDigitales" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\05-SalidasDigitales" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\10-LCD" -I"D:\Desktop\Proyecto Info 2\AccessIO\src\12-USART" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-aplicacion

clean-src-2f-aplicacion:
	-$(RM) ./src/aplicacion/inicializarInfotronic.d ./src/aplicacion/inicializarInfotronic.o ./src/aplicacion/main.d ./src/aplicacion/main.o ./src/aplicacion/secuencia.d ./src/aplicacion/secuencia.o

.PHONY: clean-src-2f-aplicacion

