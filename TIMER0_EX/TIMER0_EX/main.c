/*
 * TIMER0_EX.c
 *
 * Created: 4/6/2019 11:39:37 AM
 * Author : Faruk
 */ 

#include <avr/io.h>

int main(void)
{
	uint8_t overFlowCounter=0;
	DDRB = 0b11111111; //Set Port B as output
	TCNT0=0b00000000; //Set the value of timer0 counter to zero
	TCCR0B=0b00000101; //Set the clock divider at 1/1024.
	TCCR0A=0b00000000; //Set the compare mode as normal
	PORTB=0b00000000;

    /* Replace with your application code */
    while (1)
    {
		while ((TIFR0 & 0x01) == 0); //Check the flag status
		overFlowCounter++;
		TIFR0=0x01; //According to the datasheet, it clears the flag value. Be careful! We don't use 0x00. 
		TCNT0=0x00; //Set the counter value to zero, again! For the next cycle.
		if(overFlowCounter>30){ //
			PORTB^=0b11111111;
			overFlowCounter=0;
		}
    }
}

