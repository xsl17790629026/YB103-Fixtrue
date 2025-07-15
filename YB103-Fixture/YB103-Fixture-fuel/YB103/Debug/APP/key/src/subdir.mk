################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/key/src/key.c 

OBJS += \
./APP/key/src/key.o 

C_DEPS += \
./APP/key/src/key.d 


# Each subdirectory must supply rules for building sources it contributes
APP/key/src/%.o APP/key/src/%.su APP/key/src/%.cyclo: ../APP/key/src/%.c APP/key/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g1 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/Service/GPIO" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/User/UserTimer" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/APP" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/APP/adc" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/APP/can" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/APP/config" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/APP/key" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/APP/key/inc" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/APP/lcd12864" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/APP/lin" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103/Service/Service_CanComm" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP-2f-key-2f-src

clean-APP-2f-key-2f-src:
	-$(RM) ./APP/key/src/key.cyclo ./APP/key/src/key.d ./APP/key/src/key.o ./APP/key/src/key.su

.PHONY: clean-APP-2f-key-2f-src

