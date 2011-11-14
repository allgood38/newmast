################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../WindSense/WindSense.cpp 

OBJS += \
./WindSense/WindSense.o 

CPP_DEPS += \
./WindSense/WindSense.d 


# Each subdirectory must supply rules for building sources it contributes
WindSense/%.o: ../WindSense/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/allgood38/git/newmast/ArduinoCore" -w -Os -ffunction-sections -fdata-sections -fno-exceptions -DARDUINO=22 -g -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


