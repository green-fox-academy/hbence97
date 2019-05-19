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

UART_HandleTypeDef uart_handle;

int main(void) {

	HAL_Init();
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	BSP_LED_Init(LED1);

	// Initializing UART communication

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

	while (1) {
		char received[100];
		memset(received, '\0', 100);
		HAL_UART_Receive(&uart_handle, (uint8_t*) received, 100, 1000);
		if (strcmp(received, "ON") == 0) {
			BSP_LED_On(LED1);
		} else if (strcmp(received, "OFF") == 0) {
			BSP_LED_Off(LED1);
		} else if (strcmp(received, "") == 0) {
		} else {
			for (int i = 0; i < 6; i++) {
				BSP_LED_Toggle(LED1);
				HAL_Delay(250);
			}
		}

	}

	return 0;
}

UART_PUTCHAR {
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
