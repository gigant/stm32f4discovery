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

#include "drivers/gpio.h"
#include "drivers/timers.h"
#include "wheels.h"

#include "stm32f4xx_tim.h"
//int pulse=0;

void wheel_set_speed(int,int);

int wheels_init(void)
{
  gpio_init();
  TimersInit();
  wheel_set_speed(0,0);
  
  
  return 0;
};

void wheel_set_speed(int speed_left,int speed_right)
{
  
  return;
}


void wheel_faster(void)
{
        
       // pulse +=6;
        TimersInit();
   
};