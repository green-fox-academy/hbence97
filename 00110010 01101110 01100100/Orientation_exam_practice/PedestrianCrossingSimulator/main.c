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

static void SystemClock_Config(void);
static void Error_Handler(void);

#define UART_PUTCHAR int __io_putchar(int ch)

typedef enum {
	GREEN, RED
} state_t;

volatile state_t light_state = RED;

const uint32_t red_light_period = 70000;
const uint32_t green_light_period = 40000;
const uint32_t red_light_period_after_button = 20000;

//GPIO Typedefs
GPIO_InitTypeDef green_led_handle;
GPIO_InitTypeDef red_led_handle;
GPIO_InitTypeDef user_button_handle;

//UART Typedef
UART_HandleTypeDef uart_handle;

//Timer Typedef
TIM_HandleTypeDef timer_handle;

void init_leds() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	green_led_handle.Pin = GPIO_PIN_9;
	green_led_handle.Mode = GPIO_MODE_OUTPUT_PP;
	green_led_handle.Pull = GPIO_NOPULL;
	green_led_handle.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &green_led_handle);

	red_led_handle.Pin = GPIO_PIN_10;
	red_led_handle.Mode = GPIO_MODE_OUTPUT_PP;
	red_led_handle.Pull = GPIO_NOPULL;
	red_led_handle.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &red_led_handle);
}

void init_user_button() {
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;
	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Mode = GPIO_MODE_IT_RISING;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOI, &user_button_handle);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_uart() {
	__HAL_RCC_USART1_CLK_ENABLE()
	;
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

void init_timer() {
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	HAL_TIM_Base_DeInit(&timer_handle);
	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 10800 - 1; // 1 / (108000000 / 10800) = 0.0001 = 0.1 ms
	timer_handle.Init.Period = red_light_period - 1; // 0.1 ms (0.0001 s) * (70000 - 1) = 7 s
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&timer_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

int main(void) {
	HAL_Init();
	SystemClock_Config();

	init_leds();
	init_user_button();
	init_uart();
	init_timer();

	while (1) {
		if (light_state == RED) {
			HAL_GPIO_WritePin(GPIOF, red_led_handle.Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOF, green_led_handle.Pin, GPIO_PIN_RESET);
		} else {
			HAL_GPIO_WritePin(GPIOF, red_led_handle.Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, green_led_handle.Pin, GPIO_PIN_SET);
		}
	}
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == timer_handle.Instance) {
		if (light_state == RED) {
			light_state = GREEN;
			printf("Changed to green, you can cross the road!\r\n");

			// Set the period of the timer
			__HAL_TIM_SET_AUTORELOAD(&timer_handle, green_light_period);
		} else {
			light_state = RED;
			printf("Changed to red, please wait 7 seconds!\r\n");

			// Set the period of the timer
			__HAL_TIM_SET_AUTORELOAD(&timer_handle, red_light_period);
		}
	}
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == user_button_handle.Pin && light_state == RED) {
		// Calculate the time remaining from the red light
		uint32_t remaining_red_time = red_light_period
				- __HAL_TIM_GET_COUNTER(&timer_handle);

		if (remaining_red_time > red_light_period_after_button) {
			// If there is more than 2 seconds remaining from the red light, set the counter to (period - 2 seconds)
			__HAL_TIM_SET_COUNTER(&timer_handle, red_light_period - red_light_period_after_button);
			printf("Button pressed, wait 2 seconds!\r\n");
		}
	}
}

static void Error_Handler(void) {
}

static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

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
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

UART_PUTCHAR {
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
