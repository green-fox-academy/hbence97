#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef LEDS;

int main(void)
{
    HAL_Init();


    __HAL_RCC_GPIOF_CLK_ENABLE();

    LEDS.Pin = GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_6;

    HAL_GPIO_Init(GPIOF, &LEDS);


    for	(unsigned int i = 0; i < 16; i++){
        		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, ((((i / 2) / 2) /2)%2));
        		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, (((i / 2) / 2) %2));
        		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, ((i / 2)%2));
        		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, (i % 2));
        		HAL_Delay(600);
    }
}
