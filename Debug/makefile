################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Lib/subdir.mk
-include Dave/Generated/src/UART001/subdir.mk
-include Dave/Generated/src/SYSTM001/subdir.mk
-include Dave/Generated/src/NVIC002/subdir.mk
-include Dave/Generated/src/IO004/subdir.mk
-include Dave/Generated/src/DAVESupport/subdir.mk
-include Dave/Generated/src/CLK002/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
CeilingLamp.hex \

SECONDARY_LIST += \
CeilingLamp.lst \

SECONDARY_SIZE += \
CeilingLamp.siz \


# All Target
all: CeilingLamp.elf secondary-outputs

# Tool invocations
CeilingLamp.elf: $(OBJS) ../CeilingLamp.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM-GCC C Linker'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -T"../CeilingLamp.ld" -nostartfiles -L"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Lib" -L"C:\DAVE-3.1.10\eclipse\/../Examples/Lib" -L"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI" -Wl,-Map,"CeilingLamp.map" -mcpu=cortex-m0 -mthumb -g3 -gdwarf-2 -o "CeilingLamp.elf" "@makefile.rsp" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CeilingLamp.hex: CeilingLamp.elf
	@echo 'Invoking: ARM-GCC Create Flash Image'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-objcopy" -O ihex "CeilingLamp.elf"  "CeilingLamp.hex"
	@echo 'Finished building: $@'
	@echo ' '

CeilingLamp.lst: CeilingLamp.elf
	@echo 'Invoking: ARM-GCC Create Listing'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-objdump" -h -S "CeilingLamp.elf" > "CeilingLamp.lst"
	@echo 'Finished building: $@'
	@echo ' '

CeilingLamp.siz: CeilingLamp.elf
	@echo 'Invoking: ARM-GCC Print Size'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-size"  --format=berkeley CeilingLamp.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(SECONDARY_FLASH)$(S_DEPS)$(ARM_GCC_FOR_XMC_LINKER_OUTPUT_TYPE_OUTPUTS)$(SECONDARY_LIST) CeilingLamp.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
