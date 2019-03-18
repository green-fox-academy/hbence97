#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* create the configuration structs */
UART_HandleTypeDef uart_handle;

TIM_HandleTypeDef timer_handle;

#define UART_PUTCHAR int __io_putchar(int ch)

#define TIM_HIGHER
//#define EXTI_HIGHER

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_uart(void)
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



void init_timer(void)
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	HAL_TIM_Base_DeInit(&timer_handle);
	__HAL_TIM_SET_COUNTER(&timer_handle, 0);
	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 108000 - 1; /* 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms */
	timer_handle.Init.Period = 1000 - 1; /* 6000 x 0.5 ms = 6 second period */
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_Base_Init(&timer_handle);


	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
	/* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);

	init_uart();
	init_timer();

	/* starting the timer */
	HAL_TIM_Base_Start_IT(&timer_handle);

	while (1) {
		/* we can leave this empty */

		/* or even block the CPU forever: */
		//HAL_Delay(1000);
	}
}

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		BSP_LED_Toggle(LED_GREEN);

	}
}

UART_PUTCHAR
{
	HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
	return ch;
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
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
