################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Servo/Servo.cpp 

OBJS += \
./Servo/Servo.o 

CPP_DEPS += \
./Servo/Servo.d 


# Each subdirectory must supply rules for building sources it contributes
Servo/%.o: ../Servo/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/Users/allgood38/git/Arduino-Blink-Eclipse-Project/ArduinoCore" -w -Os -ffunction-sections -fdata-sections -fno-exceptions -DARDUINO=22 -g -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


