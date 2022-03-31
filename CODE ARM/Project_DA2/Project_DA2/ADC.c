#include "ADC.h"
#include <avr/io.h>
#include <util/delay.h>

void ADC_init()
{
    DDRA &= ~(1 << 0);
    ADCSRA = 0x87; // Enable CD & 125kHz
    ADMUX = ADC_VREF;
}
 
unsigned int ADC_read(char channel)
{
    ADMUX |= channel;
    ADCSRA |= (1 << ADSC); // Start ADC Conversion
    while ((ADCSRA & (1 << ADIF)) == 0)
        ;
    ADCSRA |= (1 << ADIF);
    // _delay_ms(1);
    return ADCW;
}