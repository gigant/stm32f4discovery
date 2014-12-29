/* конфигурация портов ввода/вывода*/

/*
порт A  
порт B
pb9 - ШИМ левое колесо
порт C
pc13 - направление правое колесо

порт D
pd12 - зеленый светодиод
порт E
pe1 - направление левого колеса
pe5 - ШИМ правое колесо
порт H
порт I

*/
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "gpio.h"

int gpio_init (void)
{
  /* структура для инициализации порта */
  GPIO_InitTypeDef  GPIO_InitStructure;
 
  /* включаем тактирующие импульсы на портах A,C,D,E */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
  
  /*конфигурирование GPIOA*/
  //конфигурирование PA0 как вход с пользовательской кнопки
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  /*конфигурирование GPIOB*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  GPIO_PinAFConfig (GPIOB, GPIO_PinSource9, GPIO_AF_TIM11);  // к PB9 подключен TIM11_CH1
  /*конфигурирование GPIOC*/
  
  /*конфигурирование GPIOD*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  /*конфигурирование GPIOE*/
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  
  GPIO_PinAFConfig (GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);  // к PE5 подключен TIM9_CH1
  /*конфигурирование GPIOH*/
  /*конфигурирование GPIOI*/

  return 0;  
}
