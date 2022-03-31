#include <avr/io.h>
#include <util/delay.h>
#ifndef _LCD16x2_H_
#define _LCD16x2_H_

#define RW PD5
#define RS PD6
#define EN PD7
#define LCD_SIG_PORT    PORTD
#define LCD_DATA_PORT   PORTC

void LCD_command(char);
void LCD_char(const unsigned char);
void LCD_string(const char*);
void LCD_init();

#endif
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
	LCD_command(0x38);
	LCD_command(0x0C);
	LCD_command(0x01);
}
int main()
{

	LCD_init();

	LCD_command(0x80);
	LCD_string("Hello DA2`");
	LCD_command(0xC0);
	LCD_string("AAAAAA");

	while (1)
	{
		
	}
	return 0;
}