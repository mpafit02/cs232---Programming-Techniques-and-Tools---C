################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Part\ 03/sedcmp.c 

OBJS += \
./Part\ 03/sedcmp.o 

C_DEPS += \
./Part\ 03/sedcmp.d 


# Each subdirectory must supply rules for building sources it contributes
Part\ 03/sedcmp.o: ../Part\ 03/sedcmp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Part 03/sedcmp.d" -MT"Part\ 03/sedcmp.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


