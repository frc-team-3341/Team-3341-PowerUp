################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/Catcher.cpp \
../src/Subsystems/DriveTrain.cpp \
../src/Subsystems/Lift.cpp 

OBJS += \
./src/Subsystems/Catcher.o \
./src/Subsystems/DriveTrain.o \
./src/Subsystems/Lift.o 

CPP_DEPS += \
./src/Subsystems/Catcher.d \
./src/Subsystems/DriveTrain.d \
./src/Subsystems/Lift.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\ankbh/wpilib/cpp/current/include" -I"C:\Users\Temp\ankbhatia\Team-3341-PowerUp\src" -I"C:\Users\ankbh/wpilib/user/cpp/include" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


