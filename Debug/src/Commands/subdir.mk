################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/AcquireCrate.cpp \
../src/Commands/ReleaseCrate.cpp \
../src/Commands/StopCatcher.cpp \
../src/Commands/TankDrive.cpp 

OBJS += \
./src/Commands/AcquireCrate.o \
./src/Commands/ReleaseCrate.o \
./src/Commands/StopCatcher.o \
./src/Commands/TankDrive.o 

CPP_DEPS += \
./src/Commands/AcquireCrate.d \
./src/Commands/ReleaseCrate.d \
./src/Commands/StopCatcher.d \
./src/Commands/TankDrive.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/%.o: ../src/Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\Diya/wpilib/cpp/current/include" -I"C:\Users\Diya\git\Team-3341-PowerUp\src" -I"C:\Users\Diya/wpilib/user/cpp/include" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


