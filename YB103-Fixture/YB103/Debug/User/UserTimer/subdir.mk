################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/UserTimer/UserTimer.c \
../User/UserTimer/UserTimer_App.c 

OBJS += \
./User/UserTimer/UserTimer.o \
./User/UserTimer/UserTimer_App.o 

C_DEPS += \
./User/UserTimer/UserTimer.d \
./User/UserTimer/UserTimer_App.d 


# Each subdirectory must supply rules for building sources it contributes
User/UserTimer/%.o User/UserTimer/%.su User/UserTimer/%.cyclo: ../User/UserTimer/%.c User/UserTimer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g1 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I"D:/work/YB103-Fixture/YB103/Service/GPIO" -I"D:/work/YB103-Fixture/YB103/User/UserTimer" -I"D:/work/YB103-Fixture/YB103/APP" -I"D:/work/YB103-Fixture/YB103/APP/adc" -I"D:/work/YB103-Fixture/YB103/APP/can" -I"D:/work/YB103-Fixture/YB103/APP/config" -I"D:/work/YB103-Fixture/YB103/APP/key" -I"D:/work/YB103-Fixture/YB103/APP/key/inc" -I"D:/work/YB103-Fixture/YB103/APP/lcd12864" -I"D:/work/YB103-Fixture/YB103/APP/lin" -I"D:/work/YB103-Fixture/YB103/Service/Service_CanComm" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-User-2f-UserTimer

clean-User-2f-UserTimer:
	-$(RM) ./User/UserTimer/UserTimer.cyclo ./User/UserTimer/UserTimer.d ./User/UserTimer/UserTimer.o ./User/UserTimer/UserTimer.su ./User/UserTimer/UserTimer_App.cyclo ./User/UserTimer/UserTimer_App.d ./User/UserTimer/UserTimer_App.o ./User/UserTimer/UserTimer_App.su

.PHONY: clean-User-2f-UserTimer

