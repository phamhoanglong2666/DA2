#ifndef _ADC_H_
#define _ADC_H_

// #define ADC_VREF 0x00  //Lấy điện áp AREF để so sánh
// #define ADC_VREF 0xE0 // Vref = 2.56V, ADLAR=1
// #define ADC_VREF 0xC0 // Vref = 2.56V, ADLAR=0
#define ADC_VREF 0x40 // Vref = Avcc, ADLAR=0

void ADC_init();
unsigned int ADC_read(char);

#endif