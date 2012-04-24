/*Драйвер для работы с  датчиком движения LIS302DL работает по SPI*/

/*
  PA7 - SPI1_MOSI
  PA5 - SPI1_SCK
  PE0 - MEMS_INT1
  PE1 - MEMS_INT2
  PE3 - CS_I2C/SPI
  PA6 - SPI1_MISO
*/
#include "stm32f4xx.h"
#include "motion_sensor.h"


int InitMotionSensor (void)
{

  //Определяем структуру для  конфигурации выводов
  GPIO_InitTypeDef GPIO_InitStructure;
  SPI_InitTypeDef  SPI_InitStructure;
  
  //SPI висит на APB2 шине. Включаем тактирование
  RCC_APB2PeriphClockCmd(LIS302DL_SPI_CLK, ENABLE);
  
  //На самом деле это всё один регистр SCK, MOSI и MISO GPIO тактирование 
  //так расписано чтобы не забыть если вдруг что поменяется
  RCC_AHB1PeriphClockCmd(LIS302DL_SPI_SCK_GPIO_CLK | LIS302DL_SPI_MISO_GPIO_CLK | LIS302DL_SPI_MOSI_GPIO_CLK, ENABLE);

  //CS Контакт выбора кристала висит на Е подаем на него тактирование
  RCC_AHB1PeriphClockCmd(LIS302DL_SPI_CS_GPIO_CLK, ENABLE);
  
  // Тактирование  INT1, INT2 они висят тоже на Е
  RCC_AHB1PeriphClockCmd(LIS302DL_SPI_INT1_GPIO_CLK, ENABLE);

  //Конфигурирование альтернативной функции порта
  
  GPIO_PinAFConfig(LIS302DL_SPI_SCK_GPIO_PORT, LIS302DL_SPI_SCK_SOURCE, LIS302DL_SPI_SCK_AF); // порт А пин 5 SPI1
  GPIO_PinAFConfig(LIS302DL_SPI_MISO_GPIO_PORT, LIS302DL_SPI_MISO_SOURCE, LIS302DL_SPI_MISO_AF); // порт А пин 6 SPI1
  GPIO_PinAFConfig(LIS302DL_SPI_MOSI_GPIO_PORT, LIS302DL_SPI_MOSI_SOURCE, LIS302DL_SPI_MOSI_AF); // порт А пин 7 SPI1
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  
return 0;
}