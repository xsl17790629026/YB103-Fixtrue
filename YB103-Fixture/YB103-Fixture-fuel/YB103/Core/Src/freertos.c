/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usart.h"
#include "UserTimer.h"
#include "can.h"
#include "adc_app.h"
// #include "key_app.h"
#include "key.h"
#include "lcd.h"
#include "config.h"
#include "dbc_can_core.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
osThreadId canreceivefunctionHandle;
osThreadId heartbeattaskHandle;
osThreadId task0Handle;
osThreadId task1Handle;
osThreadId task2Handle;
osThreadId task3Handle;
osThreadId CanTransmitHandle;
osThreadId LinTransmitHandle;
/* USER CODE END Variables */
osThreadId defaultTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void CanReceiveFunction(void const * argument);
void heartbeat_task(void const * argument);
void task0_task(void const * argument);
void task1_task(void const * argument);
void task2_task(void const * argument);
void task3_task(void const * argument);
void Lin_Flow_task(void const *pvParameters);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* Hook prototypes */
void vApplicationTickHook(void);
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);
void vApplicationMallocFailedHook(void);

/* USER CODE BEGIN 3 */
__weak void vApplicationTickHook( void )
{
   /* This function will be called by each tick interrupt if
   configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h. User code can be
   added here, but the tick hook is called from an interrupt context, so
   code must not attempt to block, and only the interrupt safe FreeRTOS API
   functions can be used (those that end in FromISR()). */
}
/* USER CODE END 3 */

/* USER CODE BEGIN 4 */
__weak void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
   /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
__weak void vApplicationMallocFailedHook(void)
{
   /* vApplicationMallocFailedHook() will only be called if
   configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
   function that will get called if a call to pvPortMalloc() fails.
   pvPortMalloc() is called internally by the kernel whenever a task, queue,
   timer or semaphore is created. It is also called by various parts of the
   demo application. If heap_1.c or heap_2.c are used, then the size of the
   heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
   FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
   to query the size of free heap space that remains (although it does not
   provide information on how the remaining heap might be fragmented). */
}
/* USER CODE END 5 */

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  osThreadDef(heartbeattask, heartbeat_task, osPriorityIdle, 0, 128);
  heartbeattaskHandle = osThreadCreate(osThread(heartbeattask), NULL);

  osThreadDef(task0task, task0_task, osPriorityIdle, 0, 128);
  task0Handle = osThreadCreate(osThread(task0task), NULL);
  
  osThreadDef(task1task, task1_task, osPriorityIdle, 0, 128);
  task1Handle = osThreadCreate(osThread(task1task), NULL);
  
  osThreadDef(task2task, task2_task, osPriorityIdle, 0, 128);
  task2Handle = osThreadCreate(osThread(task2task), NULL);
  
  osThreadDef(task3task, task3_task, osPriorityIdle, 0, 128);
  task3Handle = osThreadCreate(osThread(task3task), NULL);
  
  osThreadDef(cantransmittask, CanTransmitFunction, osPriorityIdle, 0, 128);
  CanTransmitHandle = osThreadCreate(osThread(cantransmittask), NULL);

  #if SPS250_LIN
  osThreadDef(lintransmittask, Lin_Flow_task, osPriorityIdle, 0, 128);
  LinTransmitHandle = osThreadCreate(osThread(lintransmittask), NULL);
  #endif
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void heartbeat_task(void const * argument)
{
  /* USER CODE BEGIN heartbeat_task */
    UserTimer_Initial();
    printf("heartbeat_task\r\n");
  /* Infinite loop */
  for(;;)
  {
      UserTimer_Handler();
  }
  /* USER CODE END heartbeat_task */
}

/* USER CODE BEGIN Header_can_task */
/**
* @brief Function implementing the cantask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_can_task */
void task0_task(void const * argument)
{
    (void)*argument;
    for(;;)
    {
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

/* USER CODE BEGIN Header_gpio_task */
/**
* @brief Function implementing the gpiotask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_gpio_task */
void task1_task(void const * argument)
{
    (void)*argument;
    for(;;)
    {
			//printf("task1\r\n");
        ADC_SamplingProcess();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

/* USER CODE BEGIN Header_button_task */
/**
* @brief Function implementing the buttontask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_button_task */
void task2_task(void const * argument)
{
    (void)*argument;
    for(;;)
    {
			//printf("task2\r\n");
        // Key_Rotary_CheckProcess();
        Key_CheckProcess();
        if (key_menu_cnt != GetMenuIndex() || 
            key_item_cnt != GetItemIndex() || 
            key_value_cnt != GetItemValue(GetMenuIndex(), GetItemIndex(), 0)) {
            SaveItemValue(key_menu_cnt,key_item_cnt,key_value_cnt);
        }   
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

/* USER CODE BEGIN Header_menu_task */
/**
* @brief Function implementing the menutask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_menu_task */
extern uint8_t Can_Send_Sts;

void task3_task(void const * argument)
{
    (void)*argument;
    static uint8_t s_menu = MENU_UNDEFINE;
    static uint8_t s_item = ITEM_DEFAULT;
    static uint16_t s_value = VALUE_DEFAULT;
    static uint8_t Last_CAN_SendSts = E_CANSEND_OPEN;
    uint8_t v_menu = 0;
    uint8_t v_item = 0;
    int16_t v_value = 0;
    
    for(;;)
    {
			//printf("task3\r\n");
        v_menu = GetMenuIndex();
        v_item = GetItemIndex();
        v_value = GetItemValue(v_menu, v_item, 0);
        if(Can_Send_Sts == E_CANSEND_OPEN)
        {
            if(Last_CAN_SendSts != Can_Send_Sts)
            {
                Last_CAN_SendSts = Can_Send_Sts;
            }
            if (v_menu != s_menu || v_item != s_item || v_value != s_value) {
                if (LCD_Menu_Display(v_menu, v_item, v_value) == DISPLAY_SUCCESS) {
                    s_menu = v_menu;
                    s_item = v_item;
                    s_value = v_value;
                }
            }
        }
        else
        {
            if(Last_CAN_SendSts != Can_Send_Sts)
            {
                Last_CAN_SendSts = Can_Send_Sts;
                LCD_Show_CANSendClose();
                s_menu = 0xFF;
                s_item = 0xFF;
                s_value = 0xFFFF;
            }
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}


/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
QueueHandle_t ReceiveQueue;

void CanReceiveFunction(void const * argument)
{
    CanMsg_t RxMessageObject;
    
    ReceiveQueue = xQueueCreate(4,sizeof(CanMsg_t));
    if(ReceiveQueue == NULL)
    {
        printf("receive function create xQueue failed.\r\n");
        while(1);
    }
    printf("CanReceiveFunction\r\n");
    for(;;)
    {
        if(pdTRUE == xQueueReceive(ReceiveQueue,&RxMessageObject,0)){
        }
//    	printf("\r\nid:0x%x\r\ndata:0x",RxMessageObject.MsgID);
//    	for(i = 0;i<RxMessageObject.MsgLen;++i)
//    	{
//    		printf("%x ",RxMessageObject.Msg[i]);
//    	}
//    	printf("\r\n");
    }
    
}
/* USER CODE END Application */

