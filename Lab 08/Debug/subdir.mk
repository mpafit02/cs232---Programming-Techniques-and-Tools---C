################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lab8_example1.c \
../lab8_example2.c \
../lab8_example3.c 

OBJS += \
./lab8_example1.o \
./lab8_example2.o \
./lab8_example3.o 

C_DEPS += \
./lab8_example1.d \
./lab8_example2.d \
./lab8_example3.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


