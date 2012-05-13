#ifndef __LCD_H__
#define __LCD_H__


void lcd3310_init_pins(void);

void lcd3310_init(void);

void lcd3310_send_byte(uint8_t byte, uint8_t dc);

void lcd3310_print_char(uint8_t simbol);
void lcd3310_clear(void);
void Delay(__IO uint32_t nTime);
void lcd3310_print_hex(uint32_t data);

uint8_t point (uint8_t x, uint8_t y);

#define DC_DATA 1
#define DC_CMD 0


#define sck_port GPIOB
#define sck_port_clock RCC_AHB1Periph_GPIOB
#define sck_pin GPIO_Pin_13


#define sdin_port GPIOB
#define sdin_port_clock RCC_AHB1Periph_GPIOB
#define sdin_pin GPIO_Pin_15


#define dc_port GPIOB
#define dc_port_clock RCC_AHB1Periph_GPIOB
#define dc_pin GPIO_Pin_11


#define sce_port GPIOE
#define sce_port_clock RCC_AHB1Periph_GPIOE
#define sce_pin GPIO_Pin_15


#define res_port GPIOE
#define res_port_clock RCC_AHB1Periph_GPIOE
#define res_pin GPIO_Pin_13


#define dc_up dc_port->BSRRL = dc_pin
#define dc_down dc_port->BSRRH = dc_pin


#define sck_up sck_port->BSRRL = sck_pin
#define sck_down sck_port->BSRRH = sck_pin

#define sdin_up sdin_port->BSRRL = sdin_pin
#define sdin_down sdin_port->BSRRH = sdin_pin

#define sce_up sce_port->BSRRL = sce_pin
#define sce_down sce_port->BSRRH = sce_pin

#define res_up res_port->BSRRL = res_pin
#define res_down res_port->BSRRH = res_pin



#define	LCD_NOKIA1100_SET_X_ADDRESS_LOWER_4BITS 0x00
#define	LCD_NOKIA1100_SET_X_ADDRESS_UPPER_3BITS 0x10
#define	LCD_NOKIA1100_SET_Y_ADDRESS 0xB0
#define	LCD_NOKIA1100_SET_START_ROW_ADDRESS_6BITS 0x40
#define	LCD_NOKIA1100_DIPLAY_OFF 0xAE
#define	LCD_NOKIA1100_DIPLAY_ON 0xAF
#define	LCD_NOKIA1100_PIXELS_ALL_OFF 0xA4
#define	LCD_NOKIA1100_PIXELS_ALL_ON 0xA5
#define	LCD_NOKIA1100_DISPLAY_INVERSE_ON 0xA7
#define	LCD_NOKIA1100_DISPLAY_INVERSE_OFF 0xA6
#define	LCD_NOKIA1100_CHARGE_PUMP_ON 0x2F
#define	LCD_NOKIA1100_CHARGE_PUMP_OFF 0x28



#endif