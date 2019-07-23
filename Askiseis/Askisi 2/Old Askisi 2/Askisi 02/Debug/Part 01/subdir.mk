################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Part\ 01/fcompare.c 

OBJS += \
./Part\ 01/fcompare.o 

C_DEPS += \
./Part\ 01/fcompare.d 


# Each subdirectory must supply rules for building sources it contributes
Part\ 01/fcompare.o: ../Part\ 01/fcompare.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Part 01/fcompare.d" -MT"Part\ 01/fcompare.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


