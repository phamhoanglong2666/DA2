#define F_CPU 160000000ul
#include <avr/io.h>

#define led 1
#define button 0
int main(void)
{
    /* Replace with your application code */
	// Set input-output
	DDRD &= ~(1 << button); //input D0
	DDRD |= (1 << led);  //oupit D1
	//button = input_pullup
	PORTD |= (1 << button);
	//led = output
	PORTD |= (1 << led);
    while (1) 
    {
		//kiem tra button
		if ((PIND & (1 << button)) == 0)
		{
			PORTD ^= (1 << led);
		}
    }
}

