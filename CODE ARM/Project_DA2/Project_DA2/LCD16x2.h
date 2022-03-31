#ifndef _LCD16x2_H_
#define _LCD16x2_H_
#define F_CPU 16000000ul //tan so thach anh

#define RW PD5
#define RS PD6
#define EN PD7
#define LCD_SIG_PORT PORTD
#define LCD_DATA_PORT PORTC

void LCD_command(char);
void LCD_char(const unsigned char);
void LCD_string(const char *);
void LCD_init();
void LCD_clear();
void LCD_gotoxy(unsigned char, unsigned char);

#endif