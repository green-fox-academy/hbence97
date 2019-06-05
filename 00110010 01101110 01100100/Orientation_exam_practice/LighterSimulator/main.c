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
#include <stdio.h>

#define UART_PUTCHAR int __io_putchar(int ch)

void SystemClock_Config();
void Error_Handler();

typedef enum {
	ON,
	OFF
} state_t;

typedef enum {
	ON_SPARK,
	OFF_SPARK
} spark_state_t;

typedef enum {
	ON_VALVE,
	OFF_VALVE
} valve_state_t;

typedef enum {
	ON_CHARGE,
	OFF_CHARGE
} charging_t;

volatile state_t state = OFF;
volatile valve_state_t valve_state = OFF_VALVE;
volatile spark_state_t spark_state = OFF_SPARK;
volatile charging_t charge_state = OFF_CHARGE;
uint8_t gas_amount = 20;
uint32_t charging_period = 50000; //5 sec

uint32_t time_until_empty = 200000;

// GPIO Typedefs
GPIO_InitTypeDef valve_button_handle;
GPIO_InitTypeDef spark_button_handle;
GPIO_InitTypeDef led_handle;
GPIO_InitTypeDef user_button_handle;

// UART Typedef
UART_HandleTypeDef uart_handle;

// Timer Typedef
TIM_HandleTypeDef timer_handle;

void init_uart()
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

void init_valve_button()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	valve_button_handle.Pin = GPIO_PIN_0;
	valve_button_handle.Mode = GPIO_MODE_IT_RISING;
	valve_button_handle.Pull = GPIO_NOPULL;
	valve_button_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &valve_button_handle);

	HAL_NVIC_SetPriority(EXTI0_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void init_spark_button()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	spark_button_handle.Pin = GPIO_PIN_9;
	spark_button_handle.Mode = GPIO_MODE_IT_RISING;
	spark_button_handle.Pull = GPIO_NOPULL;
	spark_button_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &spark_button_handle);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 4, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void init_user_button()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Mode = GPIO_MODE_IT_RISING;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOI, &user_button_handle);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_led()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	led_handle.Pin = GPIO_PIN_15;
	led_handle.Mode = GPIO_MODE_OUTPUT_PP;
	led_handle.Pull = GPIO_NOPULL;
	led_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &led_handle);
}

void init_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 10800 - 1; // 0.1 ms * 5000ms
	timer_handle.Init.Period = 50000 - 1; // 5 sec
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_uart();
	init_valve_button();
	init_spark_button();
	init_user_button();
	init_led();
	init_timer();

	while(1) {

	}
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);
}

void EXTI9_5_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(spark_button_handle.Pin);
}

void EXTI0_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(valve_button_handle.Pin);
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == user_button_handle.Pin && gas_amount == 0 && state == OFF){
		__HAL_TIM_SET_AUTORELOAD(&timer_handle, 2500);
		HAL_TIM_Base_Start_IT(&timer_handle); // elinditja a timert interruptban
		// Töltés
	} else if (GPIO_Pin == valve_button_handle.Pin){
		gas_amount--;
		// Csak a valve button nyomása
	} else if (GPIO_Pin == spark_button_handle.Pin && valve_button_handle.Pin && gas_amount > 0 && state == ON) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // ezzel gyujtom fel
		gas_amount--;
		// Burning
	} else if (gas_amount == 0){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
		// Hogyha nincs gáz akkor LED off
	}
}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == timer_handle.Instance) {
		if (valve_state == ON_VALVE){
			valve_state = OFF_VALVE;
			__HAL_TIM_SET_AUTORELOAD(&timer_handle, time_until_empty);
		}
		if (charge_state == ON_CHARGE) {
			__HAL_TIM_SET_AUTORELOAD(&timer_handle, charging_period);
		}
		if (time_until_empty == 0){
			state = OFF;
		}
	}
}

void Error_Handler(void)
{
}

void SystemClock_Config(void) {
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
