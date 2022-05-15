################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../source/dsp_cortex_m4.s 

OBJS += \
./source/dsp_cortex_m4.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -I"C:\Users\ehsan\Documents\MCUXpressoIDE_11.4.1_6260\workspace\mkv_asm_lib\source" -I"C:\Users\ehsan\Documents\MCUXpressoIDE_11.4.1_6260\workspace\mkv_asm_lib" -g3 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


