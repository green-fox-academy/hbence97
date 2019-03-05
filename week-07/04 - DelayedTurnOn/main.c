#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void)
{
    HAL_Init();

    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

    BSP_LED_Init(LED1);
    int counter = 0;

    while(1){
    	int pushing = 0;
    while (BSP_PB_GetState(BUTTON_KEY)) {
    	pushing++;
    	if (pushing == 1)
    		counter++;
    	while(counter >= 5){
    		BSP_LED_On(LED1);
    		}
    	}
   	}
}
