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
#include <string.h>

#define UART_PUTCHAR int __io_putchar(int ch)

GPIO_InitTypeDef user_button_handle;
GPIO_InitTypeDef red_led_handle;
GPIO_InitTypeDef blue_led_handle;
GPIO_InitTypeDef warmer_button_handle;
GPIO_InitTypeDef colder_button_handle;

UART_HandleTypeDef uart_handle;

typedef enum {
	OFF = 0,
	On = 1
} faucet_state_t;

typedef enum {
	ICE_COLD = 0,
	COLD = 1,
	LUKE_WARM = 2,
	WARM = 3,
	HOT = 4
} temperature_t;

volatile faucet_state_t state = OFF;
volatile temperature_t temperature = LUKE_WARM;

void init_user_button()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Mode = GPIO_MODE_IT_RISING;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOI, &user_button_handle);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_warmer_button()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	warmer_button_handle.Pin = GPIO_PIN_9;
	warmer_button_handle.Mode = GPIO_MODE_IT_RISING;
	warmer_button_handle.Pull = GPIO_NOPULL;
	warmer_button_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &warmer_button_handle);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 6, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void init_colder_button()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	colder_button_handle.Pin = GPIO_PIN_0;
	colder_button_handle.Mode = GPIO_MODE_IT_RISING;
	colder_button_handle.Pull = GPIO_NOPULL;
	colder_button_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &colder_button_handle);

	HAL_NVIC_SetPriority(EXTI0_IRQn, 7, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}


int main(void) {

	while (1)
	{

	}
}
