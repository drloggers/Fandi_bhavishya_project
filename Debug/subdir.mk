################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../branch_record.cpp 

CC_SRCS += \
../Local_predictor.cc \
../global_predictor.cc \
../main.cc \
../predictor.cc 

OBJS += \
./Local_predictor.o \
./branch_record.o \
./global_predictor.o \
./main.o \
./predictor.o 

CC_DEPS += \
./Local_predictor.d \
./global_predictor.d \
./main.d \
./predictor.d 

CPP_DEPS += \
./branch_record.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


