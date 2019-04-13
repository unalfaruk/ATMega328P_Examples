/*
 * TIMER1_EX.c
 *
 * Created: 4/6/2019 9:58:17 PM
 * Author : Faruk
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
	DDRB=0xFF; //Set the PORTB as output
	//Set the timer1 value to ZERO
	TCNT1=0x00;
	TCCR1B=0b00000101; //Set the clock divider to CLK/1024
	TCCR1A=0x00;
	//TCCR1B=(1<<CS10) | (1<<CS12); //Alternative method for the previous code line
	OCR1A=0x1E83; //When the timer equals to this value, it shows that 1 sec passed.
	TIMSK1=(1<<OCIE1A);
	PORTB=0x00;
	
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR (TIMER1_COMPA_vect){
	PORTB ^= 0xFF;
	TCNT1=0x00;
}

