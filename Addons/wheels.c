/** колеса приводятся в движение с помощью моторов
два мотора управляются с помощью микросхемы L298N
по два контакта на мотор ШИМ и направление
Левое колесо - 
    ph1 - направление
    pc15 - ШИМ
правое колесо 
    pc13 - ШИМ
    pe5 - направление
*/

#include "gpio.h"
#include "timers.h"
#include "wheels.h"

#include "stm32f4xx_tim.h"
extern int pulse=0;
int wheels_init(void)
{
  gpio_init();
  TimersInit();
  
  return 0;
};

void wheel_faster(void)
{
        
        pulse +=6;
        TimersInit();
   
};