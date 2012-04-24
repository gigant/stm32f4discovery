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
  
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; //включить альтернативную функцию
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;//подтянуть к земле
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//частота 50 МГц
  
  GPIO_InitStructure.GPIO_Pin = LIS302DL_SPI_SCK_PIN; // Пин 5
  GPIO_Init(LIS302DL_SPI_SCK_GPIO_PORT, &GPIO_InitStructure); // инициализация
  
  GPIO_InitStructure.GPIO_Pin =  LIS302DL_SPI_MOSI_PIN; // пин 7 
  GPIO_Init(LIS302DL_SPI_MOSI_GPIO_PORT, &GPIO_InitStructure); //инициализация MOSI

  GPIO_InitStructure.GPIO_Pin = LIS302DL_SPI_MISO_PIN; //пин 6
  GPIO_Init(LIS302DL_SPI_MISO_GPIO_PORT, &GPIO_InitStructure);//инициализация MISO
  
  /* Заполнение структуры SPI*/
  
  SPI_I2S_DeInit(LIS302DL_SPI); //деинициализация SPI 
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; // на прием и передачу
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b; //По 8 бит
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low; // Хер знает что такое полярность часов low
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;// фаза какая-то
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;//
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;//
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;//
  SPI_InitStructure.SPI_CRCPolynomial = 7;//
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;//
  SPI_Init(LIS302DL_SPI, &SPI_InitStructure);// инициализация
  
  // Таа-даа!!!     включаем SPI
  SPI_Cmd(LIS302DL_SPI, ENABLE);
  
  //Теперь инициализация чип селекта
  
  GPIO_InitStructure.GPIO_Pin = LIS302DL_SPI_CS_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(LIS302DL_SPI_CS_GPIO_PORT, &GPIO_InitStructure);
  
  /*Выставляем чип селект */
  GPIO_SetBits(LIS302DL_SPI_CS_GPIO_PORT, LIS302DL_SPI_CS_PIN);
  
  // Конфигурация пинов для INT2
  GPIO_InitStructure.GPIO_Pin = LIS302DL_SPI_INT1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  GPIO_Init(LIS302DL_SPI_INT1_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = LIS302DL_SPI_INT2_PIN;
  GPIO_Init(LIS302DL_SPI_INT2_GPIO_PORT, &GPIO_InitStructure);
  
 ////Можно передохнуть ноги сконфигурированы////////////////////////////
  
  uint8_t ctrl = 0x00;
  
  /* Configure MEMS: data rate, power mode, full scale, self test and axes */
  ctrl = (uint8_t) (LIS302DL_InitStruct->Output_DataRate | LIS302DL_InitStruct->Power_Mode | \
                    LIS302DL_InitStruct->Full_Scale | LIS302DL_InitStruct->Self_Test | \
                    LIS302DL_InitStruct->Axes_Enable);
  
  /* Записать сконфигурированый байт в CTRL_REG1 регистр */
  LIS302DL_Write(&ctrl, LIS302DL_CTRL_REG1_ADDR, 1);
  
  
  //конфигурация закончена
  
  
return 0;
}