#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void) {
	HAL_Init();

	BSP_LED_Init(LED1);

	int counter = 0;

	while (1) {
		if (BSP_PB_GetState(BUTTON_KEY)) {
			counter++;
			/* If button is pressed do something */
			if(counter >= 5){
				BSP_LED_On(LED1);
			}
		}
	}
}
