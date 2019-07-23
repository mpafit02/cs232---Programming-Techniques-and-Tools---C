################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Calculator.c \
../Division.c \
../EvenOrOdd.c \
../FahrenheitToCelsius.c \
../NegativeSum.c \
../SumOfIntegers.c 

OBJS += \
./Calculator.o \
./Division.o \
./EvenOrOdd.o \
./FahrenheitToCelsius.o \
./NegativeSum.o \
./SumOfIntegers.o 

C_DEPS += \
./Calculator.d \
./Division.d \
./EvenOrOdd.d \
./FahrenheitToCelsius.d \
./NegativeSum.d \
./SumOfIntegers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


