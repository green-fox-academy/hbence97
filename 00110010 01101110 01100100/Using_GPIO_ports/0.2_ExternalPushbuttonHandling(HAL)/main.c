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

GPIO_InitTypeDef push_button;

int main(void)
{
	HAL_Init();

	BSP_LED_Init(LED1);

	__HAL_RCC_GPIOF_CLK_ENABLE();

	push_button.Pin = GPIO_PIN_10;
	push_button.Mode = GPIO_MODE_OUTPUT_PP;
	push_button.Pull = GPIO_NOPULL;
	push_button.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &push_button);

	while(1) {
		if (HAL_GPIO_ReadPin(GPIOF, push_button.Pin)){
			BSP_LED_On(LED1);
		}
	}
}
