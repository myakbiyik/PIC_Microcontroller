#include <xc.h>

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

unsigned char segment[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                   0x6D, 0x7C, 0x07, 0x7F, 0x6F}; //Seven segment display number configuration.
int time=0;
unsigned char i=0;
unsigned char k=0;

void scanningFunc();

void main(void) 
{
    TRISB = 0x00;       // Set PORTB pins as output.
    TRISA = 0x00;       // Set PORTA pins as output.
        
    while(1)
    {
        for(k=0; k<=9; k++)
        {                         
            for(i=0; i<=9; i++)
            {
                scanningFunc();
            }
        }
        
        i=0;
        k=0;
    
    return;
    }
}


/*We can make two displays work together by switching
 *them on and off for 1 ms each. The human eye cannot 
 *notice this 1 ms gap and will perceive both displays as one. */ 
void scanningFunc()
{
    int m = 0;
    
    for(m=0; m<=2000; m++)
    {
        if(m%2 == 0)
        {
            RA0 = 1;
            PORTB = segment[i];
            RA1 = 0;
        }
        else
        {    
            RA1 = 1;
            PORTB = segment[k];
            RA0 = 0;
        }
    }   
}