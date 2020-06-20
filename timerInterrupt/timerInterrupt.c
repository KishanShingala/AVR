#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include<util/delay.h>

int main()
 { 
   unsigned char c = 0x55;
   DDRA = 0xFF;
   DDRD = 0XFF;
   DDRB = 0x01;
   PORTC = 0xFF;
   DDRC = 0x00;
   PORTB=0X01;
   
   TCNT0 = -200;
   TCCR0 = 0x01; 
    
   TCNT1H = (0xD8F0)>>8;
   TCNT1L = (0xD8F0)&0xFF;
   
   TCCR1A = 0x00;
   TCCR1B = 0x05;
   
   TIMSK = (1<<TOIE1) | (1<<TOIE0);
   sei(); 
    

    while (1){
      PORTD = PINC;
   }
   return 0;
 }
 
 ISR(TIMER0_OVF_vect){
    TCNT0 = -200;
    PORTB ^= 0X01;  
 }
 ISR(TIMER1_OVF_vect){
    TCNT1H = (0xD8F0)>>8;
   TCNT1L = (0xD8F0)&0xFF;
    PORTA++;  
 }
 
