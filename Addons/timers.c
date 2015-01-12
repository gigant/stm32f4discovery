
#include "stm32f4xx_tim.h"
extern int pulse;

void TimersInit(void)
{
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
        
        TIM_TimeBaseInitTypeDef base_timer;
        TIM_TimeBaseStructInit(&base_timer);
 
        base_timer.TIM_Prescaler = 8-1;   // делитель частоты
        base_timer.TIM_Period = 1000;  // период
        base_timer.TIM_CounterMode = TIM_CounterMode_Up; // счЄт вверх
        TIM_TimeBaseInit(TIM9, &base_timer);
 
        TIM_OCInitTypeDef oc_init;
        TIM_OCStructInit(&oc_init);
        oc_init.TIM_OCMode = TIM_OCMode_PWM1;   // работаем в режиме Ў»ћ ( PWM )
        oc_init.TIM_OutputState = TIM_OutputState_Enable;
        oc_init.TIM_Pulse = pulse;   //pulse частота шим
        oc_init.TIM_OCPolarity = TIM_OCPolarity_High;  // положительна€ пол€рность
 
        TIM_OC1Init(TIM9,&oc_init);   /// заносим данные в первый канал - порт D12
        TIM_OC1PreloadConfig(TIM9, TIM_OCPreload_Enable);
        
        TIM_ARRPreloadConfig(TIM9,ENABLE);
        TIM_Cmd(TIM9,ENABLE);   // запускаем счЄт
        
        //////////////////////////////////////////////////////////////////////////
        
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);
        
        TIM_TimeBaseInitTypeDef base_timer2;
        TIM_TimeBaseStructInit(&base_timer2);
 
        base_timer.TIM_Prescaler = 8 - 1;   // делитель частоты
        base_timer.TIM_Period = 1000;  // период
        base_timer.TIM_CounterMode = TIM_CounterMode_Up; // счЄт вверх
        TIM_TimeBaseInit(TIM11, &base_timer2);
 
 
        oc_init.TIM_OCMode = TIM_OCMode_PWM1;   // работаем в режиме Ў»ћ ( PWM )
        oc_init.TIM_OutputState = TIM_OutputState_Enable;
        oc_init.TIM_Pulse = pulse;   // частота шим
        oc_init.TIM_OCPolarity = TIM_OCPolarity_High;  // положительна€ пол€рность
 
        TIM_OC1Init(TIM11,&oc_init);   /// заносим данные в первый канал - порт D12
        TIM_OC1PreloadConfig(TIM11, TIM_OCPreload_Enable);
        
        TIM_ARRPreloadConfig(TIM11,ENABLE);
        TIM_Cmd(TIM11,ENABLE);   // запускаем счЄт
        //////////////////////////////////////////////////////////////////////
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM4, ENABLE);
        
        TIM_TimeBaseInitTypeDef base_timer3;
        TIM_TimeBaseStructInit(&base_timer3);
 
        base_timer.TIM_Prescaler = 8 - 1;   // делитель частоты
        base_timer.TIM_Period = 1000;  // период
        base_timer.TIM_CounterMode = TIM_CounterMode_Up; // счЄт вверх
        TIM_TimeBaseInit(TIM4, &base_timer3);
 
 
        oc_init.TIM_OCMode = TIM_OCMode_PWM1;   // работаем в режиме Ў»ћ ( PWM )
        oc_init.TIM_OutputState = TIM_OutputState_Enable;
        oc_init.TIM_Pulse = pulse;   // частота шим
        oc_init.TIM_OCPolarity = TIM_OCPolarity_High;  // положительна€ пол€рность
 
        TIM_OC1Init(TIM4,&oc_init);   /// заносим данные в первый канал
        TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
        
        TIM_ARRPreloadConfig(TIM4,ENABLE);
        TIM_Cmd(TIM4,ENABLE);   // запускаем счЄт
        
  return; 
}