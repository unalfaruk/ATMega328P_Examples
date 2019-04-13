/*
 * TIMER0_EX_INT.c
 *
 * Created: 4/6/2019 9:02:21 PM
 * Author : Faruk
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


uint8_t overFlowCounter=0;
uint8_t * ptrOverFlowCounter=&overFlowCounter;
void updateLEDStatus();
int main(void)
{
	
	DDRB = 0b11111111; //Set Port B as output
	TCNT0=0b00000000; //Set the timer counter as zero
	TCCR0B=0b00000101; //Set the clock divider at 1/1024 Clock_Timer=7KHz
	TCCR0A=0b00000000; //Set the compare output mode as normal
	TIMSK0=0b00000001; //Set the interrupt status enable
	PORTB=0b00000000;
	sei();  

	/* Replace with your application code */
	while (1)
	{
		updateLEDStatus();
		/*if(*ptrOverFlowCounter>30){
			PORTB^=0b11111111;
			*ptrOverFlowCounter=0;
		}*/
	}
}

ISR (TIMER0_OVF_vect)  // timer0 overflow interrupt
{
	overFlowCounter++;
}

void updateLEDStatus(){
	
	/*if(*ptrOverFlowCounter>30){
		PORTB^=0b11111111;
		*ptrOverFlowCounter=0;
	}*/
	
	if(overFlowCounter>30){
		PORTB^=0b11111111;
		overFlowCounter=0;
	}
}

