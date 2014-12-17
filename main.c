 #include "stm32f4xx.h"
 #include "Addons\wheels.h"

#define RedLed GPIO_Pin_14
#define GreenLed GPIO_Pin_12

int main(void)
{
  int init_err =0; 
  
  init_err = wheels_init();
  
  
  if (!init_err) GPIO_SetBits (GPIOD, GreenLed);
                 else GPIO_SetBits (GPIOD, RedLed);
  
  while (1)
  {
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
