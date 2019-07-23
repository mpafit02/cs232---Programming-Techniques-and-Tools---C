################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Part\ 02/pagerank.c 

OBJS += \
./Part\ 02/pagerank.o 

C_DEPS += \
./Part\ 02/pagerank.d 


# Each subdirectory must supply rules for building sources it contributes
Part\ 02/pagerank.o: ../Part\ 02/pagerank.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Part 02/pagerank.d" -MT"Part\ 02/pagerank.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


