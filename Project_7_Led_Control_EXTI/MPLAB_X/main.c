#include <xc.h>

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

void __interrupt() KESME(void)
{
    GIE = 0;
    if(INTF == 1)
    {
        PORTB |= (1 << 7);
        __delay_ms(1000);
    }
    INTF = 0;
    GIE = 1;
}

void main(void) 
{
    TRISB &= ~(1 << 7);        // RB7 Output
    INTCON |= (1 << 4);        // INTE = 1 External Interrupt Enabled
    INTCON |= (1 << 7);        // GIE = 1 Global Interrupt Enabled
    OPTION_REG |= (1 << 6);    // Rising Edge Interrupt
    
    while(1)
    {
        PORTB &= ~(1 << 7);     // Led sürekli olarak sönük       
    }
    
    return;
}
