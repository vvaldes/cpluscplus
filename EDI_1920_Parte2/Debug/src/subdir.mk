################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/algoritmos.cpp \
../src/bar.cpp \
../src/barrio.cpp \
../src/via.cpp 

OBJS += \
./src/algoritmos.o \
./src/bar.o \
./src/barrio.o \
./src/via.o 

CPP_DEPS += \
./src/algoritmos.d \
./src/bar.d \
./src/barrio.d \
./src/via.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


