################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../fun_struct.c \
../fun_struct_sol.c \
../readShuffleLines.c \
../shape.c \
../sortTable.c \
../sortTable_sol.c \
../sparseMatrix.c \
../sparseMatrix1.c 

OBJS += \
./fun_struct.o \
./fun_struct_sol.o \
./readShuffleLines.o \
./shape.o \
./sortTable.o \
./sortTable_sol.o \
./sparseMatrix.o \
./sparseMatrix1.o 

C_DEPS += \
./fun_struct.d \
./fun_struct_sol.d \
./readShuffleLines.d \
./shape.d \
./sortTable.d \
./sortTable_sol.d \
./sparseMatrix.d \
./sparseMatrix1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


