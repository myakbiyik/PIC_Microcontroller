#include <xc.h>

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

void main(void) 
{
    TRISA = (2 << 0);           //Make RA1 pin as output.
    TRISB |= (1 << 1);          //Make RB1 pin as input.
    
    
    while(1)
    {
        if(RB1 == 1)
        {
            //Pushed to the Button
            
            PORTA = (2 << 1);
        }
        else
        {
            //Don't pushed to the Button
            
            PORTA = (2 << 0);
        }
    }
    
    
}
