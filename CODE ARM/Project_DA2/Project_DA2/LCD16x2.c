#include "LCD16x2.h"
#include <avr/io.h>
#include <util/delay.h>

void LCD_command(char cmd)
{
    LCD_SIG_PORT &= ~(1 << RW);
    LCD_SIG_PORT &= ~(1 << RS);
    LCD_DATA_PORT = cmd;
    LCD_SIG_PORT |= (1 << EN);
    _delay_ms(1);
    LCD_SIG_PORT &= ~(1 << EN);
    _delay_ms(3);
}

void LCD_char(const unsigned char data)
{
    LCD_SIG_PORT &= ~(1 << RW);
    LCD_SIG_PORT |= (1 << RS);
    LCD_DATA_PORT = data;
    LCD_SIG_PORT |= (1 << EN);
    _delay_ms(1);
    LCD_SIG_PORT &= ~(1 << EN);
    _delay_ms(1);
}

void LCD_string(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        LCD_char(str[i]);
    }
}

void LCD_init()
{
    // set GPIO LCD
    DDRC = 0xFF;
    DDRD = 0xFF;
    LCD_SIG_PORT |= (1 << RW) | (1 << RS) | (1 << EN);

    // Init LCD
    LCD_command(0x38); //giao tiep 8 bit
	//LCD_command(0x02); //di chuyen con tro ve dau man hinh
    LCD_command(0x0C); //bat hien thi va tat con tro
    LCD_command(0x01); //xoa toan bo noi dung tren man LCD
	//_delay_us(2);
}

void LCD_clear()
{
    LCD_command(0x01);
}

void LCD_gotoxy(unsigned char x, unsigned char y)
{
    unsigned char temp;
    if (!y)
        temp = (0x80 + x);
    else
        temp = (0xc0 + x);

    _delay_us(1000);
    LCD_command(temp);
    _delay_us(50);
}