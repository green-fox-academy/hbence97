/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef User_button_handle;

void init_user_button()
{
    /* enable the GPIOI clock */
	__HAL_RCC_GPIOI_CLK_ENABLE();

	User_button_handle.Pin = GPIO_PIN_11;
    /* the user button has a built-in resistor: */
	User_button_handle.Pull = GPIO_NOPULL;
	User_button_handle.Speed = GPIO_SPEED_FAST;
    /* here is the trick: our mode is interrupt on rising edge */
	User_button_handle.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOI, &User_button_handle);
	/* we don't need to explicitly call the HAL_NVIC_SetPriorityGrouping() function,
	   because the grouping defaults to NVIC_PRIORITYGROUP_2:
	   HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
	*/

	/* assign a priority to our interrupt line */
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);

    /* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

int main(void)
{
	HAL_Init();

	//SystemClock_Config(); Ez ide szerintem nem kell!!

	BSP_LED_Init(LED_GREEN);
	init_user_button();

	while(1){
        /* we can leave this empty or even block the CPU forever with HAL_Delay(1000) */
	}
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    /* this is the place for the user code */
	BSP_LED_Toggle(LED_GREEN);
}

