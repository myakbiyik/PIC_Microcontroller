/*
 * File:   main.c
 * Author: MYA
 *
 * Created on 11 subat 2022 Cuma, 02:35
 */


#include <xc.h>

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON        // Watchdog Timer (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

void main(void) 
{
    TRISB = 0x00;       //Choose PORTB pins as digital output.
    
    while(1)
    {

    for(int i=0; i<3000; i++)
        
    PORTB = 0x01;       //Enable R0 pin.
    
    for(int i=0; i<3000; i++)
            
    PORTB = 0x00;      //Disable R0 pin.

        
    }
}
