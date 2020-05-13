################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm476DISCO-joystick.c \
../src/stm476DISCO-leds.c 

OBJS += \
./src/main.o \
./src/stm476DISCO-joystick.o \
./src/stm476DISCO-leds.o 

C_DEPS += \
./src/main.d \
./src/stm476DISCO-joystick.d \
./src/stm476DISCO-leds.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32L4 -DSTM32L476VGTx -DSTM32L476G_DISCO -DDEBUG -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


