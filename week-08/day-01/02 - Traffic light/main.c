#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

UART_HandleTypeDef UartHandle;
GPIO_InitTypeDef LEDS;

/* the timer's config structure */
TIM_HandleTypeDef TimHandle;

uint16_t tim_val = 0; /* variable to store the actual value of the timer's register (CNT) */
uint16_t seconds = 0; /* variable to store the value of ellapsed seconds */

static void Error_Handler(void);
static void SystemClock_Config(void);


int main(void)
{
	HAL_Init();

	/* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
	SystemClock_Config();
	__HAL_RCC_GPIOF_CLK_ENABLE();

	LEDS.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8;// setting up 3pins at once w | (A1, A2, A3)
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;	// configure as output, push pull mode
	LEDS.Pull = GPIO_NOPULL;				// we use external resistor so no
	LEDS.Speed = GPIO_SPEED_HIGH;						// high speed output

	__HAL_RCC_USART1_CLK_ENABLE();

	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &UartHandle);
	BSP_LED_Init(LED_GREEN);

	/* we need to enable the TIM2 */
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	TimHandle.Instance = TIM2;
	TimHandle.Init.Prescaler = 54000 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.2ms */
	TimHandle.Init.Period = 24000 - 1; /* 120000 x 0.1 ms = 12000 ms (12 second period */
	TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_Base_Init(&TimHandle);

	/* starting the timer */
	HAL_TIM_Base_Start(&TimHandle);

	HAL_GPIO_Init(GPIOF, &LEDS);

	while (1)
	{
		tim_val = __HAL_TIM_GET_COUNTER(&TimHandle);

		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, tim_val < 9000);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, (tim_val > 9000 && tim_val < 13000) || tim_val > 20000);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, tim_val > 13000 && tim_val < 24000);
	}
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct ={ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct ={ 0 };

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

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK)
	{
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
	{
		Error_Handler();
	}
}
