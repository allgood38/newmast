################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
FLASH_IMAGE += \
Blink.hex \

SIZEDUMMY += \
sizedummy \
<<<<<<< HEAD


# All Target
all: Blink.elf secondary-outputs

# Tool invocations
Blink.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -s -Os -Wl,--gc-sections -o"Blink.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lm -Wl,-Map,Blink.map,--cref -L../../ArduinoCore/Release/ -mmcu=atmega328p
	@echo 'Finished building target: $@'
	@echo ' '

Blink.hex: Blink.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Blink.elf  "Blink.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Blink.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Blink.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ELFS)$(FLASH_IMAGE)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) Blink.elf
	-@echo ' '

secondary-outputs: $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
=======


# All Target
all: Blink.elf secondary-outputs

# Tool invocations
Blink.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -s -Os -Wl,--gc-sections -o"Blink.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lm -Wl,-Map,Blink.map,--cref -L../../ArduinoCore/Release/ -mmcu=atmega2560
	@echo 'Finished building target: $@'
	@echo ' '

Blink.hex: Blink.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Blink.elf  "Blink.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Blink.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 Blink.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ELFS)$(FLASH_IMAGE)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) Blink.elf
	-@echo ' '

secondary-outputs: $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
>>>>>>> 88a386f26258b2a9c5b70d6068c0fe89070e8088
