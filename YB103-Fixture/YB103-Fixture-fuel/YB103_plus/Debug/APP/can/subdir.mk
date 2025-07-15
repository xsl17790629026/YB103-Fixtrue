################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/can/APP_CAN_CanMsgPar.c \
../APP/can/dbc_can_core.c 

OBJS += \
./APP/can/APP_CAN_CanMsgPar.o \
./APP/can/dbc_can_core.o 

C_DEPS += \
./APP/can/APP_CAN_CanMsgPar.d \
./APP/can/dbc_can_core.d 


# Each subdirectory must supply rules for building sources it contributes
APP/can/%.o APP/can/%.su APP/can/%.cyclo: ../APP/can/%.c APP/can/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g1 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/Service/GPIO" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/User/UserTimer" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/adc" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/can" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/config" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/key" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/key/inc" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/lcd12864" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/lin" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/Service/Service_CanComm" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP-2f-can

clean-APP-2f-can:
	-$(RM) ./APP/can/APP_CAN_CanMsgPar.cyclo ./APP/can/APP_CAN_CanMsgPar.d ./APP/can/APP_CAN_CanMsgPar.o ./APP/can/APP_CAN_CanMsgPar.su ./APP/can/dbc_can_core.cyclo ./APP/can/dbc_can_core.d ./APP/can/dbc_can_core.o ./APP/can/dbc_can_core.su

.PHONY: clean-APP-2f-can

