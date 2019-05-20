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

GPIO_InitTypeDef LEDS;
GPIO_InitTypeDef push_button_handle;

void init_push_button()
{
    /* enable the GPIOI clock */
	__HAL_RCC_GPIOB_CLK_ENABLE();

	push_button_handle.Pin = GPIO_PIN_4;
    /* the user button has a built-in resistor: */
	push_button_handle.Pull = GPIO_NOPULL;
	push_button_handle.Speed = GPIO_SPEED_FAST;
    /* here is the trick: our mode is interrupt on rising edge */
	push_button_handle.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOI, &push_button_handle);
	/* we don't need to explicitly call the HAL_NVIC_SetPriorityGrouping() function,
	   because the grouping defaults to NVIC_PRIORITYGROUP_2:
	   HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
	*/

	/* assign a priority to our interrupt line */
	HAL_NVIC_SetPriority(EXTI4_IRQn, 2, 0);

    /* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);

}

void init_gpio_led()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();
	LEDS.Pin = GPIO_PIN_9;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_FAST;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOF, &LEDS);
}

int main(void)
{
	HAL_Init();

	init_gpio_led();
	//HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9); IGY CSAK VILÁGÍT

	init_push_button();

	while(1){
        /* we can leave this empty or even block the CPU forever with HAL_Delay(1000) */
	}
}

void EXTI9_5_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    /* this is the place for the user code */
		HAL_GPIO_TogglePin(GPIOF,LEDS.Pin);
}
