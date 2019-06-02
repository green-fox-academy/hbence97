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
void SystemClock_Config(void);
void Error_Handler(void);
typedef enum {
    OPEN, SECURING, SECURED, OPENING
} state_t;

volatile state_t state = OPEN;

#define UART_PUTCHAR int __io_putchar(int ch)
GPIO_InitTypeDef led_handle;
GPIO_InitTypeDef user_button_handle;
TIM_HandleTypeDef timer_handle;
UART_HandleTypeDef uart_handle;

void init_user_button()
{
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
void init_led()
{
    __HAL_RCC_GPIOI_CLK_ENABLE()
    ;
    led_handle.Pin = GPIO_PIN_1;
    led_handle.Mode = GPIO_MODE_OUTPUT_PP;
    led_handle.Pull = GPIO_NOPULL;
    led_handle.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOI, &led_handle);
}
void init_uart()
{
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
void init_timer()
{
    __HAL_RCC_TIM2_CLK_ENABLE()
    ;
    HAL_TIM_Base_DeInit(&timer_handle);
    timer_handle.Instance = TIM2;
    timer_handle.Init.Prescaler = 10800 - 1; // 1 / (108000000 / 10800) = 0.0001 = 0.1 ms
    timer_handle.Init.Period = 5000 - 1;
    timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
    HAL_TIM_Base_Init(&timer_handle);
    HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

uint8_t valid = 1;
uint8_t valid1 = 1;
uint8_t valid2 = 1;

volatile uint8_t counter = 0;
volatile uint8_t counter2 = 0;

int main()
{
    HAL_Init();
    SystemClock_Config();
    init_user_button();
    init_led();
    init_uart();
    init_timer();

    //HAL_TIM_Base_Start_IT(&timer_handle);

    while (1) {

        if (valid2) {
            if (state == OPEN) {
                printf("OPEN\n");
                init_timer();
                HAL_TIM_Base_Start_IT(&timer_handle);
                valid2 = 0;
            }
        }
        if (valid) {
            if (state == SECURING) {
            	//itt

                HAL_TIM_Base_Stop_IT(&timer_handle);
                timer_handle.Init.Period = 2500 - 1;
                HAL_TIM_Base_Init(&timer_handle);

                HAL_TIM_Base_Start_IT(&timer_handle);
            }
            valid = 0;
        }
        if (state == SECURED) {
            HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);
        }

        if (valid1) {
            if (state == OPENING) {

                HAL_TIM_Base_Stop_IT(&timer_handle);
                timer_handle.Init.Period = 2500 - 1;
                HAL_TIM_Base_Init(&timer_handle);

                HAL_TIM_Base_Start_IT(&timer_handle);
            }
            valid1 = 0;
        }
    }
}
void TIM2_IRQHandler()
{
    HAL_TIM_IRQHandler(&timer_handle);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == timer_handle.Instance) {
        if (state == OPEN) {
            HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
        }
        if (state == SECURING) {
            HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
            counter++;
            if (counter == 10) {
                state = SECURED;
                printf("SECURED\n");
                counter = 0;
            }
        }
        if (state == OPENING) {
            HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
            counter2++;
            if (counter2 == 12) {
                state = OPEN;
                valid2 = 1;
                counter2 = 0;
            }
            //itt
        }
    }
}
void EXTI15_10_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (state == OPEN) {
        state = SECURING;
        printf("SECURING\n");
    }
    if (state == SECURED) {
        state = OPENING;
        printf("OPENING\n");
    }
}
void Error_Handler(void)
{
}
void SystemClock_Config(void)
{
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
{
    HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
    return ch;
}
