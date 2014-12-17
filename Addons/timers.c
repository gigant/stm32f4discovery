
#include "stm32f4xx_tim.h"

void TimersInit(void)
{
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
        
        TIM_TimeBaseInitTypeDef base_timer;
        TIM_TimeBaseStructInit(&base_timer);
 
        base_timer.TIM_Prescaler = 8 - 1;   // делитель частоты
        base_timer.TIM_Period = 1000;  // период
        base_timer.TIM_CounterMode = TIM_CounterMode_Up; // счЄт вверх
        TIM_TimeBaseInit(TIM9, &base_timer);
 
        TIM_OCInitTypeDef oc_init;
        TIM_OCStructInit(&oc_init);
        oc_init.TIM_OCMode = TIM_OCMode_PWM1;   // работаем в режиме Ў»ћ ( PWM )
        oc_init.TIM_OutputState = TIM_OutputState_Enable;
        oc_init.TIM_Pulse = 500;   // частота шим
        oc_init.TIM_OCPolarity = TIM_OCPolarity_High;  // положительна€ пол€рность
 
        TIM_OC1Init(TIM9,&oc_init);   /// заносим данные в первый канал - порт D12
        TIM_OC1PreloadConfig(TIM9, TIM_OCPreload_Enable);
        
        TIM_ARRPreloadConfig(TIM9,ENABLE);
        TIM_Cmd(TIM9,ENABLE);   // запускаем счЄт
  return; 
}