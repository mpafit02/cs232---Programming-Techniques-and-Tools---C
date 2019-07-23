################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Josephus/Josephus.c \
../Josephus/Queue.c 

O_SRCS += \
../Josephus/Josephus.o \
../Josephus/Queue.o 

OBJS += \
./Josephus/Josephus.o \
./Josephus/Queue.o 

C_DEPS += \
./Josephus/Josephus.d \
./Josephus/Queue.d 


# Each subdirectory must supply rules for building sources it contributes
Josephus/%.o: ../Josephus/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


