#include "LCD16x2.h"
#include "ADC.h"
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>

#define sysmbol 0xdf
#define LED PORTD
#define ON 1 << 1
#define OFF 0

void display_temp(char *);
void LED_init();

int main()
{
  char temperature[10];
  float temp;

  LCD_init();
  ADC_init();
  LED_init();

  LCD_clear();
  LCD_command(0x80);

  while (1)
  {
    temp = (ADC_read(0) * 0.488);

    if (temp >= 50)
      LED = ON;
    else  
      LED = OFF;

    sprintf(temperature, "%d %cC", (int)temp, sysmbol);

    LCD_gotoxy(0, 0);
    display_temp(temperature);
    _delay_ms(30);

    LCD_clear();
  }
  return 0;
}

void LED_init()
{
  DDRD |= ON;
}

void display_temp(char *str)
{
  LCD_string("Nhiet do: ");
  LCD_string(str);
}