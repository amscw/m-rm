#include <stdio.h>
#include <stdlib.h>

/**
 * PA3/TIM2_CH4 - "RM_ON"
 */
#define TIM2_DIVISION_FACTOR	(36000)
#define TIM2_TICKS_PER_PERIOD	(1000)
#define TIM2_TICKS_PER_PULSE	(100)

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

extern "C" {
#include "stm32f30x_conf.h"
}


int main(int argc, char* argv[])
{
	static GPIO_InitTypeDef GPIO_InitStructure;
	static TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	static TIM_OCInitTypeDef TIM_OCInitStructure;

	// At this stage the system clock should have already been configured
	// at high speed.
	SystemCoreClockUpdate();

	// Pin configurations
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// Go out SYSCLK
	RCC_MCOConfig(RCC_MCOSource_SYSCLK);

	// Assign TIM2_CH4 alternate function to PA3
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);

	// TIM2 setup time base
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);

	TIM_TimeBaseStructure.TIM_Prescaler = TIM2_DIVISION_FACTOR - 1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = TIM2_TICKS_PER_PERIOD - 1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	// Configure TIM2 in PWM mode
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	TIM_OCInitStructure.TIM_Pulse = TIM2_TICKS_PER_PULSE - 1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC4Init(TIM2, &TIM_OCInitStructure);

	// fire
	TIM_Cmd(TIM2, ENABLE);
	TIM_CtrlPWMOutputs(TIM2, ENABLE);

  // Infinite loop
  while (1)
    {
       // Add your code here.
    }
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */

extern "C" {

void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

}

#endif // USE_FULL_ASSERT

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
