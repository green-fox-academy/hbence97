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

void SystemClock_Config(void);

GPIO_InitTypeDef user_button_handle;
GPIO_InitTypeDef red_led_handle;
GPIO_InitTypeDef blue_led_handle;
GPIO_InitTypeDef warmer_button_handle;
GPIO_InitTypeDef colder_button_handle;

TIM_HandleTypeDef water_saving_timer_handle;

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

volatile faucet_state_t faucet_state = OFF;
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

void init_uart_handle()
{
	__HAL_RCC_USART1_CLK_ENABLE();

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

void init_led_pins()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();

	blue_led_handle.Pin = GPIO_PIN_4;
	blue_led_handle.Pull = GPIO_NOPULL;
	blue_led_handle.Mode = GPIO_MODE_AF_PP;
	blue_led_handle.Speed = GPIO_SPEED_HIGH;
	blue_led_handle.Alternate = GPIO_AF2_TIM3;

	HAL_GPIO_Init(GPIOB, &blue_led_handle);

	__HAL_RCC_GPIOA_CLK_ENABLE();

	red_led_handle.Pin = GPIO_PIN_15;
	red_led_handle.Pull = GPIO_NOPULL;
	red_led_handle.Mode = GPIO_MODE_AF_PP;
	red_led_handle.Speed = GPIO_SPEED_HIGH;
	red_led_handle.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &red_led_handle);
}

void init_water_saving_timer()
{
	__HAL_RCC_TIM4_CLK_ENABLE();

	water_saving_timer_handle.Instance = TIM4;
	water_saving_timer_handle.Init.Prescaler = 10800 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
	water_saving_timer_handle.Init.Period = 50000 - 1; /* 50000 x 0.1 ms = 5 second period */
	water_saving_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	water_saving_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&water_saving_timer_handle);

	HAL_NVIC_EnableIRQ(TIM4_IRQn);
	HAL_NVIC_SetPriority(TIM4_IRQn, 8, 0);
}
int main(void) {

	HAL_Init();

	init_user_button();
	init_colder_button();
	init_warmer_button();
	init_led_pins();
	init_uart_handle();
	init_water_saving_timer();

	while (1)
	{

	}
}

void EXTI0_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(colder_button_handle.Pin);
}

void EXTI9_5_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(warmer_button_handle.Pin);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);
}

void TIM4_IRQHandler()
{
	HAL_TIM_IRQHandler(&water_saving_timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == water_saving_timer_handle.Instance){
		faucet_state = OFF;
		HAL_TIM_Base_Stop_IT(&water_saving_timer_handle);
		printf("The faucet is closed.\r\n");
	}
}

void Error_Handler(void)
{
}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

UART_PUTCHAR
{
    HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}
