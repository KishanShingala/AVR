#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include "lcd.h"
void usart_init(){
   UBRRL =0X33;
   UCSRC = (1<<UCSZ0) | (1<<UCSZ1) |(1<<URSEL);
   UCSRB =(1<<TXEN)|(1<<RXEN)|(1<<RXCIE);   
}

void usart_send(char c){
   while(!(UCSRA & (1<<UDRE)));
   UDR = c;
}
ISR (USART_RXC_vect){
    char rec = UDR;
    lcd_data(rec);
}
int main()
 { 
    char i = 0;
    usart_init();
    sei();
    lcd_init();
    DDRC = 0x01;
    PORTC = 0X01;
    
   while (1){
   PORTC^=0X01;
    _delay_ms(5000);
   }
   return 0;
 }
 

