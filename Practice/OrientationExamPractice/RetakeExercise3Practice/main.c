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

static void SystemClock_Config(void);
static void Error_Handler(void);

#define UART_PUTCHAR int __io_putchar(int ch)

typedef enum {
	ON, OFF
} state_t;

UART_HandleTypeDef uart_handle;

GPIO_InitTypeDef user_button_handle;
GPIO_InitTypeDef spark_button_handle;
GPIO_InitTypeDef valve_button_handle;
GPIO_InitTypeDef external_LED_gpio_handle;

TIM_HandleTypeDef timer_handle;

volatile state_t valve_state = OFF;
volatile state_t fire_state = OFF;
volatile state_t charger_state = OFF;

uint32_t last_debounce_time = 0;
const uint8_t debounce_delay = 250;

volatile uint8_t gas_amount = 20;

void init_led() {
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	external_LED_gpio_handle.Pin = GPIO_PIN_15;
	external_LED_gpio_handle.Mode = GPIO_MODE_OUTPUT_PP;
	external_LED_gpio_handle.Pull = GPIO_NOPULL;
	external_LED_gpio_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &external_LED_gpio_handle);
}

void init_uart()
// Initializing UART communication
{
	__HAL_RCC_USART1_CLK_ENABLE()
	;
	// Enable clock for the USART1
	uart_handle.Instance = USART1;
	// set USART1 register
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	// set 8 bit word length
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
	// initializing COM1 line for USB UART emulation line (Hercules)
}

void init_user_button() {
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Mode = GPIO_MODE_IT_RISING_FALLING;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOI, &user_button_handle);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
}

void init_valve_button() {
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	valve_button_handle.Pin = GPIO_PIN_0;
	valve_button_handle.Mode = GPIO_MODE_IT_RISING_FALLING;
	valve_button_handle.Pull = GPIO_NOPULL;
	valve_button_handle.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOA, &valve_button_handle);

	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 7, 0);
}

void init_spark_button() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	spark_button_handle.Pin = GPIO_PIN_9;
	spark_button_handle.Mode = GPIO_MODE_IT_RISING;
	spark_button_handle.Pull = GPIO_NOPULL;
	spark_button_handle.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &spark_button_handle);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 6, 0);
}

void init_timer() {
	SystemClock_Config();
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	// set the clock for the timer (TIM2)
	HAL_TIM_Base_DeInit(&timer_handle);
	// de-initialize the TIM_Base, because of safety reasons.
	// if it's already initialized, this step de-initialize it
	timer_handle.Instance = TIM2;
	// set structure for the TIM2 timer
	timer_handle.Init.Prescaler = 54000 - 1;// 1 / (clock value / prescaler value) = prescaler time unit
											// 1 / (108000000 / 54000) = 0,0005 = 0,5 ms

	timer_handle.Init.Period = 2000 - 1;// period time = prescaler time unit * period value
										// period time = 0,5 ms (0,0005 s) * (2000 - 1) = 1 s

	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle);
	// initialize the timer

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}
int main(void) {
	HAL_Init();
	SystemClock_Config();

	init_led();
	init_spark_button();
	init_valve_button();
	init_user_button();
	init_uart();

	while (1) {
		if (fire_state == ON) {
			HAL_GPIO_WritePin(GPIOA, external_LED_gpio_handle.Pin,
					GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOA, external_LED_gpio_handle.Pin,
					GPIO_PIN_RESET);
		}

	}
}
void EXTI0_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(valve_button_handle.Pin);
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);
}

void EXTI9_5_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(spark_button_handle.Pin);
}

void TIM2_IRQHandler()
// the name of the function must come from the startup/startup_stm32f746xx.s file
{
	HAL_TIM_IRQHandler(&timer_handle);
	// set timer_handle structure for the TIM2 handler
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	uint32_t current_time = HAL_GetTick();
	if (current_time < last_debounce_time + debounce_delay) {
		// Do nothing (this is not a real button press)
		return;
	}

	if (GPIO_Pin == valve_button_handle.Pin) {
		if (charger_state == ON) {
			return;
		}

		if (valve_state == ON) {
			printf("Valve turned off\r\n");
			valve_state = OFF;
			fire_state = OFF;
			HAL_TIM_Base_Stop_IT(&timer_handle);
		} else {
			printf("Valve turned on\r\n");
			valve_state = ON;
			__HAL_TIM_SET_COUNTER(&timer_handle, 0);
			HAL_TIM_Base_Start_IT(&timer_handle);
		}
	} else if (GPIO_Pin == spark_button_handle.Pin) {
		printf("Spark ignited\r\n");

		if (charger_state == OFF && valve_state == ON && gas_amount > 0) {
			fire_state = ON;
			printf("Fire is LIIIIIT\r\n");
		}
	} else if (GPIO_Pin == user_button_handle.Pin) {
		if (charger_state == OFF) {
			printf("Charger turned on\r\n");
			charger_state = ON;
			__HAL_TIM_SET_COUNTER(&timer_handle, 0);
			HAL_TIM_Base_Start_IT(&timer_handle);
		} else {
			printf("Charger turned off\r\n");
			charger_state = OFF;
			HAL_TIM_Base_Stop_IT(&timer_handle);
		}
	}

	last_debounce_time = current_time;
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == timer_handle.Instance) {
		if (valve_state == ON) {
			printf("Valve is open, gas amount: %d\r\n", gas_amount);

			if (gas_amount > 0) {
				gas_amount--;
			} else {
				fire_state = OFF;
				printf("Ran out of gas!\r\n");
			}
		}

		if (charger_state == ON) {
			printf("Charging, gas amount: %d\r\n", gas_amount);

			if (gas_amount < 17) {
				gas_amount += 4;
			} else {
				gas_amount = 20;
			}
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

UART_PUTCHAR
// after this point the UART_PUTCHAR is equal
// with the int __io_putchar(int ch) (see it above)
{
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
	// after this code line the bulit in printf command is equal with the
	// HAL_UART_Transmit command
}
