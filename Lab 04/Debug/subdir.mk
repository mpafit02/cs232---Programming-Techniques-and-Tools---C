################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../palindrome.c \
../parameter.c \
../sample1.c \
../sample2.c \
../stringlib.c 

OBJS += \
./palindrome.o \
./parameter.o \
./sample1.o \
./sample2.o \
./stringlib.o 

C_DEPS += \
./palindrome.d \
./parameter.d \
./sample1.d \
./sample2.d \
./stringlib.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


