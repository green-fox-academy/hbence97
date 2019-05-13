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

int main(void) {
	HAL_Init();

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	LEDS.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &LEDS);
	int counter = 0;
	while (1) {
		counter++;
		if (counter >= 16) {
			counter = 0;
		}
		if ((counter & (1)) == (1)) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);

		}
		if ((counter & (1 << 1)) == (1 << 1)) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);

		}
		if ((counter & (1 << 2)) == (1 << 2)) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);

		}
		if ((counter & (1 << 3)) == (1 << 3)) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
		}
	}
}
