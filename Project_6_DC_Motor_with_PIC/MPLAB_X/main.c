#include <xc.h>

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define __XTAL_FREQ 4000000

void main(void) {
    
    TRISB = 0x00;             // Set PORTB pins as output.
    TRISA = 0x1F;             // Set PORTA pins as input.

    PORTA=0;
    PORTB=0;
    
    while(1)
    {
        
        if (RA2 == 1)
        {
            RB7 = 1;
        }
        else
        {
            RB7 = 0;
        }
    }    
    
    return;
}
