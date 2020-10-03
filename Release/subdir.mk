################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP.c \
../DIO.c \
../Keypad.c \
../Lcd.c \
../Led.c \
../Seg.c \
../Switch.c 

OBJS += \
./APP.o \
./DIO.o \
./Keypad.o \
./Lcd.o \
./Led.o \
./Seg.o \
./Switch.o 

C_DEPS += \
./APP.d \
./DIO.d \
./Keypad.d \
./Lcd.d \
./Led.d \
./Seg.d \
./Switch.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


