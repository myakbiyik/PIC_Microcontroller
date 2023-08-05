#include <xc.h>

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

int segment[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                   0x6D, 0x7C, 0x07, 0x7F, 0x6F};   //Seven segment display number configuration.

void main(void) 
{
    TRISB = 0x00;             // Set PORTB pins as output.
    TRISA = 0x1F;             // Set PORTA pins as input.
    int i=0;
        
    while(1)
    {
        
        if (RA3 == 1)
        {
            PORTB = segment[i];           // 0 0 1 1 1 1 1 1 -> 0
            __delay_ms(500);
            i++;
        }
        
        if (i==10)
        {
            i=0;
        }
        }
    
    return;
}
