#include <xc.h>

#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

void main(void) {
    
    TRISB = 0x00;       //Choose  PORTB pins as an output.
    PORTB = 0x00;       //Disable the PORTB pins.
    
    int i;
    
    while(1)
    {
        for (i=0; i<=7; i++)
        {
            PORTB = (1 << i);       //Enable PORTB pins in a sequential order.
            __delay_ms(50);         //50ms DELAY.
        }
       
        for (i=6; i>=1; i--)        //Enable PORTB pins in a sequential order.
        {
            PORTB = (1 << i);       
            __delay_ms(50);         //50ms DELAY.
        }
    }
}
