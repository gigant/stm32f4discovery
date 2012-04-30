 #include "stm32f4xx.h"
#include "motion_sensor.h"
#include "LCD.h"
#include "led.h"

int main(void)
{ 
  ledInit ();
  ledOff(LEDALL);
  //—труктура дл€ инициализации датчика движени€
  LIS302DL_InitTypeDef  LIS302DL_InitStruct;
  
  
  
  
  
  //конфигурирование портов, инициализаци€ контроллера
  
   /* Set configuration of LIS302DL*/
  LIS302DL_InitStruct.Power_Mode = LIS302DL_LOWPOWERMODE_ACTIVE;
  LIS302DL_InitStruct.Output_DataRate = LIS302DL_DATARATE_100;
  LIS302DL_InitStruct.Axes_Enable = LIS302DL_X_ENABLE | LIS302DL_Y_ENABLE | LIS302DL_Z_ENABLE;
  LIS302DL_InitStruct.Full_Scale = LIS302DL_FULLSCALE_2_3;
  LIS302DL_InitStruct.Self_Test = LIS302DL_SELFTEST_NORMAL;
    
  InitMotionSensor(&LIS302DL_InitStruct);
  
 // uint8_t pBuf;
 
  //lcd3310_init_pins();
  //lcd3310_init();
  //lcd3310_send_byte(DC_DATA,0xFF);
  while (1)
  {
    /*MotionSensorRead (&pBuf,0x29,1);
    if (pBuf > 0xDF) { GPIOD->BSRRL = GPIO_Pin_12;} //on led4
    if (pBuf <0xD0) {GPIOD->BSRRH =GPIO_Pin_12;} //off led4*/
      
   // delay_ns(100000);    
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
