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
#define UART_PUTCHAR int __io_putchar(int ch)

UART_HandleTypeDef UartHandle;
GPIO_InitTypeDef user_button_handle;

int counter = 0;

void LEDS_init(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE(); /* enable the GPIOI clock */

	user_button_handle.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8; /* the pin is the 11 */
	/* We know from the board's datasheet that a resistor is already installed externally for this button
	 (so it's not floating), we don't want to use the internal pull feature */
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST; /* port speed to fast */
	/* Here is the trick: our mode is interrupt on rising edge */
	user_button_handle.Mode = GPIO_MODE_OUTPUT_PP;

	HAL_GPIO_Init(GPIOF, &user_button_handle);

	/* we don't need to explicitly call the HAL_NVIC_SetPriorityGrouping function,
	 * because the grouping defaults to NVIC_PRIORITYGROUP_2:
	 * HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
	 */
}

void init_user_button(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE(); /* enable the GPIOI clock */

	user_button_handle.Pin = GPIO_PIN_0; /* the pin is the 11 */
	/* We know from the board's datasheet that a resistor is already installed externally for this button
	 (so it's not floating), we don't want to use the internal pull feature */
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST; /* port speed to fast */
	/* Here is the trick: our mode is interrupt on rising edge */
	user_button_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOA, &user_button_handle);

	/* we don't need to explicitly call the HAL_NVIC_SetPriorityGrouping function,
	 * because the grouping defaults to NVIC_PRIORITYGROUP_2:
	 * HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
	 */

	/* assign the intermediate priority to our interrupt line */
	HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0);

	/* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

int main(void)
{
	HAL_Init();
	LEDS_init();
	init_user_button();
	BSP_LED_Init(LED_GREEN);

	while(1){
	}

	return 0;
}

void EXTI0_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	/* yeey! this is the interrupt routine! */

	counter++;

	if(counter > 3) {
		counter = 1;
	}

	if(counter == 1){
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_SET);
	} else if(counter == 2){
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_SET);
	} else if(counter == 3){
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_RESET);
	}
}

/*void init_uart(void)
{
	__HAL_RCC_USART1_CLK_ENABLE();
	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &UartHandle);
}
*/

UART_PUTCHAR
{
    HAL_UART_Transmit(&UartHandle, (uint8_t*) &ch, 1, 0xFFFF);
    return ch;
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
	__HAL_RCC_PWR_CLK_ENABLE();
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
