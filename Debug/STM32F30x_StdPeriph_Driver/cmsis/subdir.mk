################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F30x_StdPeriph_Driver/cmsis/system_stm32f30x.c 

OBJS += \
./STM32F30x_StdPeriph_Driver/cmsis/system_stm32f30x.o 

C_DEPS += \
./STM32F30x_StdPeriph_Driver/cmsis/system_stm32f30x.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F30x_StdPeriph_Driver/cmsis/%.o: ../STM32F30x_StdPeriph_Driver/cmsis/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F30X -DUSE_STDPERIPH_DRIVER -I"M:\git\m-rm\STM32F30x_StdPeriph_Driver\cmsis\Include" -I"M:\git\m-rm\STM32F30x_StdPeriph_Driver\inc" -I"M:\git\m-rm\include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


