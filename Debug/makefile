################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/KPD/subdir.mk
-include HAL/CLCD/subdir.mk
-include HAL/CAR/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Node1.lss \

FLASH_IMAGE += \
Node1.hex \

EEPROM_IMAGE += \
Node1.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Node1.elf secondary-outputs

# Tool invocations
Node1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Node1.map -mmcu=atmega32 -o "Node1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Node1.lss: Node1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Node1.elf  >"Node1.lss"
	@echo 'Finished building: $@'
	@echo ' '

Node1.hex: Node1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Node1.elf  "Node1.hex"
	@echo 'Finished building: $@'
	@echo ' '

Node1.eep: Node1.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Node1.elf  "Node1.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Node1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Node1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Node1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
