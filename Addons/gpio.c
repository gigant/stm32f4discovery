/* конфигурация портов ввода/вывода*/

/*
порт A  
порт B
порт C
pc13 - направление правое колесо
pc15 - ШИМ левое колесо
порт D
pd12 - зеленый светодиод
порт E
pe5 - ШИМ правое колесо
порт H
ph1 - направление левого колеса
порт I

*/
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "gpio.h"

int gpio_init (void)
{
  /* структура для инициализации порта */
  GPIO_InitTypeDef  GPIO_InitStructure;
 
  /* включаем тактирующие импульсы на портах C,D,E,H */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
  
  /*конфигурирование GPIOA*/
  
  /*конфигурирование GPIOB*/
  
  /*конфигурирование GPIOC*/
  /*GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
  GPIO_PinAFConfig (GPIOC, GPIO_PinSource13, GPIO_AF_TIM4);
  GPIO_PinAFConfig (GPIOC, GPIO_PinSource15, GPIO_AF_TIM4);*/
  
  /*конфигурирование GPIOD*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  /*конфигурирование GPIOE*/
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  
  GPIO_PinAFConfig (GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);  // к PE5 подключен TIM9_CH1
  /*конфигурирование GPIOH*/
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOH, &GPIO_InitStructure);
  /*конфигурирование GPIOI*/

  return 0;  
}
