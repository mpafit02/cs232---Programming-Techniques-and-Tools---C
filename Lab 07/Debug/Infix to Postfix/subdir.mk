################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Infix\ to\ Postfix/Stack.c \
../Infix\ to\ Postfix/infixTOpostfix.c 

O_SRCS += \
../Infix\ to\ Postfix/Stack.o \
../Infix\ to\ Postfix/infixTOpostfix.o 

OBJS += \
./Infix\ to\ Postfix/Stack.o \
./Infix\ to\ Postfix/infixTOpostfix.o 

C_DEPS += \
./Infix\ to\ Postfix/Stack.d \
./Infix\ to\ Postfix/infixTOpostfix.d 


# Each subdirectory must supply rules for building sources it contributes
Infix\ to\ Postfix/Stack.o: ../Infix\ to\ Postfix/Stack.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Infix to Postfix/Stack.d" -MT"Infix\ to\ Postfix/Stack.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Infix\ to\ Postfix/infixTOpostfix.o: ../Infix\ to\ Postfix/infixTOpostfix.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Infix to Postfix/infixTOpostfix.d" -MT"Infix\ to\ Postfix/infixTOpostfix.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


