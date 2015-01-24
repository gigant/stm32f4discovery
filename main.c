 #include "stm32f4xx.h"
 #include "wheels.h"
 #include "drivers/mpu6050.h"
 #include "drivers/hal_mpu6050.h"

#define RedLed GPIO_Pin_14
#define GreenLed GPIO_Pin_12

int main(void)
{
  int init_err =0; 
  int i=0;
  init_err = wheels_init();
  
  MPU6050_I2C_Init();
  MPU6050_Initialize();
  
  if( MPU6050_TestConnection() == TRUE)
     {
          i=1;   // connection success
     }else
          {
             // connection failed
          }
  
  if (!init_err) GPIO_SetBits (GPIOD, GreenLed);
                 else GPIO_SetBits (GPIOD, RedLed);
  
  while (1)
  {
    if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==Bit_SET) wheel_faster();
    for (i = 0; i < 100000; i++);
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
