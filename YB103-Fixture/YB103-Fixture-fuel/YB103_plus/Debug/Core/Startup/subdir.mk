################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f105rbtx.s 

OBJS += \
./Core/Startup/startup_stm32f105rbtx.o 

S_DEPS += \
./Core/Startup/startup_stm32f105rbtx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -I../Core/Inc -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/User/UserTimer" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/adc" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/can" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/config" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/key" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/key/inc" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/lcd12864" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/APP/lin" -I"D:/work/YB103-Fixture/YB103-Fixture-fuel/YB103_plus/Service/Service_CanComm" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f105rbtx.d ./Core/Startup/startup_stm32f105rbtx.o

.PHONY: clean-Core-2f-Startup

