#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

#define UART_PUTCHAR int __io_putchar(int ch)

UART_HandleTypeDef UartHandle;

/* the timer's config structure */
TIM_HandleTypeDef TimHandle;

uint16_t tim_val = 0;		/* variable to store the actual value of the timer's register (CNT) */
uint16_t seconds = 0;		/* variable to store the value of ellapsed seconds */

static void Error_Handler(void);
static void SystemClock_Config(void);

int main(void)
{
	HAL_Init();

	SystemClock_Config();

	__HAL_RCC_USART1_CLK_ENABLE();
	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;
	BSP_COM_Init(COM1,&UartHandle);
	BSP_LED_Init(LED_GREEN);

	__HAL_RCC_TIM2_CLK_ENABLE();

	TimHandle.Instance = TIM2;
	TimHandle.Init.Prescaler = 10800 / 5 - 1;
	TimHandle.Init.Period = 2000 - 1;
	TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&TimHandle);

	HAL_TIM_Base_Start(&TimHandle);

	while(1){
		if (tim_val == 0) {
			printf("%d ms\r\n", HAL_GetTick());
		}
		if (tim_val == 1000) {
			printf("%d ms\r\n",HAL_GetTick());
			BSP_LED_Off(LED_GREEN);
			seconds++;
		}
		if (seconds == 10) {
			printf("10 seconds ellapsed.\r\n");
			seconds = 0;
		}
	}
}

static void Error_Handler(void)
{}


static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
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
    HAL_UART_Transmit(&UartHandle, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}
