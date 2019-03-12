#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

volatile int counter = 0;
GPIO_InitTypeDef push_button;


void init_push_button(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	push_button.Pin = GPIO_PIN_9;
	push_button.Pull = GPIO_NOPULL;
	push_button.Speed = GPIO_SPEED_FAST;
	push_button.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOF, &push_button);
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

int main(void)
{
	HAL_Init();

	BSP_LED_Init(LED_GREEN);

	init_push_button();

	while (1) {

	}
}

void EXTI9_5_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	counter++;

	if (counter % 5 == 0) {
		BSP_LED_Toggle(LED_GREEN);
	}
}
