################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/adc/adc_app.c 

OBJS += \
./APP/adc/adc_app.o 

C_DEPS += \
./APP/adc/adc_app.d 


# Each subdirectory must supply rules for building sources it contributes
APP/adc/%.o APP/adc/%.su APP/adc/%.cyclo: ../APP/adc/%.c APP/adc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g1 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I"D:/work/YB103-Fixture/YB103/Service/GPIO" -I"D:/work/YB103-Fixture/YB103/User/UserTimer" -I"D:/work/YB103-Fixture/YB103/APP" -I"D:/work/YB103-Fixture/YB103/APP/adc" -I"D:/work/YB103-Fixture/YB103/APP/can" -I"D:/work/YB103-Fixture/YB103/APP/config" -I"D:/work/YB103-Fixture/YB103/APP/key" -I"D:/work/YB103-Fixture/YB103/APP/key/inc" -I"D:/work/YB103-Fixture/YB103/APP/lcd12864" -I"D:/work/YB103-Fixture/YB103/APP/lin" -I"D:/work/YB103-Fixture/YB103/Service/Service_CanComm" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP-2f-adc

clean-APP-2f-adc:
	-$(RM) ./APP/adc/adc_app.cyclo ./APP/adc/adc_app.d ./APP/adc/adc_app.o ./APP/adc/adc_app.su

.PHONY: clean-APP-2f-adc

