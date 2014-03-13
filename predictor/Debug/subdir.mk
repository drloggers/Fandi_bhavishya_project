################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../cbp_inst.o \
../main.o \
../op_state.o \
../predictor.o \
../tread.o 

CC_SRCS += \
../cbp_inst.cc \
../chooser_predictor.cc \
../global_predictor.cc \
../local_predictor.cc \
../main.cc \
../op_state.cc \
../path_history.cc \
../predictor.cc \
../tread.cc 

OBJS += \
./cbp_inst.o \
./chooser_predictor.o \
./global_predictor.o \
./local_predictor.o \
./main.o \
./op_state.o \
./path_history.o \
./predictor.o \
./tread.o 

CC_DEPS += \
./cbp_inst.d \
./chooser_predictor.d \
./global_predictor.d \
./local_predictor.d \
./main.d \
./op_state.d \
./path_history.d \
./predictor.d \
./tread.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


