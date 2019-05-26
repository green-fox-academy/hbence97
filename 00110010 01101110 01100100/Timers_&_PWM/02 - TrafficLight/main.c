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

void SystemClock_Config();
void Error_Handler();

GPIO_InitTypeDef red_light_handle;
GPIO_InitTypeDef yellow_light_handle;
GPIO_InitTypeDef green_light_handle;

TIM_HandleTypeDef timer_handle;

uint16_t timer_value= 0;

void init_leds()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	green_light_handle.Pin = GPIO_PIN_8;
	green_light_handle.Mode = GPIO_MODE_OUTPUT_PP;
	green_light_handle.Pull = GPIO_NOPULL;
	green_light_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &green_light_handle);

	yellow_light_handle.Pin = GPIO_PIN_9;
	yellow_light_handle.Mode = GPIO_MODE_OUTPUT_PP;
	yellow_light_handle.Pull = GPIO_NOPULL;
	yellow_light_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &yellow_light_handle);

	red_light_handle.Pin = GPIO_PIN_10;
	red_light_handle.Mode = GPIO_MODE_OUTPUT_PP;
	red_light_handle.Pull = GPIO_NOPULL;
	red_light_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &red_light_handle);
}

void init_timer(void) {
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	HAL_TIM_Base_DeInit(&timer_handle);
	__HAL_TIM_SET_COUNTER(&timer_handle, 0);
	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 129600 - 1;			//NAGYJÁBÓL STIMMEL AZ IDÕ
	timer_handle.Init.Period = 12000 - 1;				//NAGYJÁBÓL STIMMEL AZ IDÕ
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_Base_Init(&timer_handle);

}

int main(void) {
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);
	init_timer();
	init_leds();

	HAL_TIM_Base_Start(&timer_handle);

	/* starting the timer */
	//HAL_TIM_Base_Start_IT(&timer_handle);
	while (1) {
		timer_value = __HAL_TIM_GET_COUNTER(&timer_handle);
		if (timer_value  > 0 && timer_value <= 7000) {
			HAL_GPIO_WritePin(GPIOF, green_light_handle.Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOF, yellow_light_handle.Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, red_light_handle.Pin,GPIO_PIN_RESET);
		}
		if (timer_value > 7000 && timer_value <= 9000) {
			HAL_GPIO_WritePin(GPIOF, green_light_handle.Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, yellow_light_handle.Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOF, red_light_handle.Pin,GPIO_PIN_RESET);
		}
		if (timer_value > 9000 && timer_value <= 12000){
			HAL_GPIO_WritePin(GPIOF, green_light_handle.Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, yellow_light_handle.Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, red_light_handle.Pin, GPIO_PIN_SET);
		}
		if (timer_value == 12000) {
			timer_value = 0;
		}
	}
}

void TIM2_IRQHandler(void) {
	HAL_TIM_IRQHandler(&timer_handle);
}

/*void HAL_TIM_PeriodEllapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM2) {
		seconds = __HAL_TIM_GET_COUNTER(&timer_handle);
		if (seconds == 0) {
			BSP_LED_On(LED_GREEN);
		}
		if (seconds == 5000) {
			BSP_LED_Off(LED_GREEN);
		}
	}
}*/

void Error_Handler(void) {
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
