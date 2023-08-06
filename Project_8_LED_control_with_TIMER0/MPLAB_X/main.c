#include <xc.h>

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)
#define _XTAL_FREQ 4000000      // Crystal Osilator frequency

int sayac = 0;

void main(void) 
{
    OPTION_REG = 0x07;          // Prescaler 256 | Prescaler for TMR0
    TMR0 = 236;                 // TMR0 starter and first item. 
    
    TRISB = 0x00;               // B Portu output olarak ayarland?
    PORTB = 0x00;               // B Portunun tüm ç?k??lar? lojik 0 a çekildi
    
    while(1)
    {
        if(TMR0 == 0)           // 5 ms
        {
            TMR0 = 236;         // TMR0 has started and first item. 
            sayac += 1;
        }
        
        if(sayac == 200)
        {
            RB0= RB0 ^ 1;       // Toggle
            sayac = 0;
        }
    }    
}