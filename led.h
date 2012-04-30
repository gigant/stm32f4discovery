#include "stm32f4xx.h"

#define LED3 GPIO_Pin_13
#define LED4 GPIO_Pin_12
#define LED5 GPIO_Pin_14
#define LED6 GPIO_Pin_15
#define LEDALL GPIO_Pin_13|GPIO_Pin_12|GPIO_Pin_14|GPIO_Pin_15

void ledInit (void);
void ledOn (uint16_t led);
void ledOff (uint16_t led);
void ledInvert (uint16_t led);