################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/screensaver/subdir.mk
-include Core/Src/LCD_Driver/subdir.mk
-include Core/Src/ImgControl/subdir.mk
-include Core/Src/AppMain/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
GrafikTest.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
GrafikTest.list \

OBJCOPY_BIN += \
GrafikTest.bin \


# All Target
all: GrafikTest.elf secondary-outputs

# Tool invocations
GrafikTest.elf: $(OBJS) $(USER_OBJS) C:\Users\Marcel-Laptop\Documents\Git_Repos\4.UI_controller\03.Software\2.\ GrafikTest\STM32F303K8TX_FLASH.ld
	arm-none-eabi-g++ -o "GrafikTest.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Marcel-Laptop\Documents\Git_Repos\4.UI_controller\03.Software\2. GrafikTest\STM32F303K8TX_FLASH.ld" -Wl,-Map="GrafikTest.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

GrafikTest.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "GrafikTest.list"
	@echo 'Finished building: $@'
	@echo ' '

GrafikTest.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "GrafikTest.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
