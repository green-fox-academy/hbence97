#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void)
{
	HAL_Init();

	BSP_LED_Init(LED1);

	int counter = 0;

	while(1)
	counter++;
	while(counter >= 5)
			BSP_LED_On(LED1);
			HAL_Delay(75);
			BSP_LED_Off(LED1);
			HAL_Delay(75);
			while(counter >= 5){
				BSP_LED_On(LED1);
				HAL_Delay(500);
				BSP_LED_Off(LED1);
				HAL_Delay(500);
				while(counter >= 5){
					BSP_LED_On(LED1);
					HAL_Delay(250);
					BSP_LED_Off(LED1);
					HAL_Delay(250);
					while(counter >= 5){
						BSP_LED_On(LED1);
						HAL_Delay(125);
						BSP_LED_Off(LED1);
						HAL_Delay(125);
					}
				}
			}

	}
