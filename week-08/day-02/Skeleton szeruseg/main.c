#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* create the configuration structs */
UART_HandleTypeDef uart_handle;			//typedef
GPIO_InitTypeDef user_button_handle;	// -||-
TIM_HandleTypeDef timer_handle;			//-||-

#define UART_PUTCHAR int __io_putchar(int ch) 	//printf miatt

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_uart(void)	//UART inicializálás,(printf miatt)
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

void init_user_button(void)		//user button inicializálás
{
	__HAL_RCC_GPIOI_CLK_ENABLE(); /* enable the GPIOI clock */

	user_button_handle.Pin = GPIO_PIN_11; /* the pin is the 11 */
	/* We know from the board's datasheet that a resistor is already installed externally for this button
	 (so it's not floating), we don't want to use the internal pull feature */
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST; /* port speed to fast */
	/* Here is the trick: our mode is interrupt on rising edge */
	user_button_handle.Mode = GPIO_MODE_IT_RISING;	//interupt modban

	HAL_GPIO_Init(GPIOI, &user_button_handle);

	/* we don't need to explicitly call the HAL_NVIC_SetPriorityGrouping function,
	 * because the grouping defaults to NVIC_PRIORITYGROUP_2:
	 * HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
	 */

	/* assign the intermediate priority to our interrupt line */
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);

	/* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_timer(void)
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	HAL_TIM_Base_DeInit(&timer_handle);
	__HAL_TIM_SET_COUNTER(&timer_handle, 0);
	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 54000 - 1; /* 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms */  //mekkora egy ugrás a timer értékben... a prescaler oszt
	timer_handle.Init.Period = 12000 - 1; /* 6000 x 0.5 ms = 6 second period */  // meddig (hány lépcsõ van)  a period szoroz
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_Base_Init(&timer_handle);


	/* assign the highest priority to our interrupt line */
	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);  // a középsõ a fontos, a másik legyen mindig nulla  (minél kisebb a aszán annál nagyobb a prioritása)

	/* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

int main(void)
{
	HAL_Init();  // ez a kettõ mindig az elején
	SystemClock_Config();  // timerhez, szinén elõl

	BSP_LED_Init(LED_GREEN);

	init_uart();
	init_user_button();
	init_timer();

	/* starting the timer */
	HAL_TIM_Base_Start_IT(&timer_handle);

	while (1) {
		/* we can leave this empty */

		/* or even block the CPU forever: */
		//HAL_Delay(1000);
	}
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	/* yeey! this is the interrupt routine! */
	BSP_LED_Toggle(LED_GREEN);

	printf("Button interrupt\n");
}

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		printf("ENTRY point of the timer callback (in every 6 seconds)\n\n");
		/* Simulationg a very long process inside the interrupt service routine.
		 * It is to be avoided to write such a long callback in real life. */

		int start_timestamp = __HAL_TIM_GET_COUNTER(htim);
        for (int i = 0; i < 48826291; i++); /* 48826291 execution of this loop takes exactly 3000 ms */
		int end_timestamp = __HAL_TIM_GET_COUNTER(htim);

		int time_diff = (end_timestamp - start_timestamp) / 2;

		printf("EXIT point of the timer callback (after %d ms)\n\n", time_diff);
	}
}

UART_PUTCHAR
{
	HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
	return ch;
}

static void Error_Handler(void) // ez mindig ugyanaz
{
}

static void SystemClock_Config(void)  //  -||-
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
