/* Author: whe024
 * Partner(s) Name: Wentao He
 * Lab Section: A21
 * Assignment: Lab #4  Exercise #1
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {INIT, START, INCR, DECR, RESET} state;
unsigned char tmpA, tmpC;

void Tick()
{ 
        tmpA = PINA;
        tmpC = PORTC;
        switch (state){
		case INIT :
			PORTC = 0x07;
		break;
		case START :
		
		break;
		case INCR :
			if(tmpA && (tmpC < 9) ){
				PORTC = ++tmpC;
			}
		break;
		case DECR :
			if( tmpA && (tmpC > 0) ){
				PORTC = --tmpC;
			}
		break;
		case RESET :
			PORTC = 0x00;
		break;
		default:
		
		break;
	}
	
	switch (state){
		case INIT :
			state = START;
		break;
		case START :
			if( (PINA & 0x01) == 0x01 && (PINA | 0x01) == 0x01 ){
				state = INCR;
			}
			else if( (PINA & 0x02) == 0x02 && (PINA | 0x02) == 0x02 ){
				state = DECR;
			}
			else if( (PINA & 0x03) == 0x03 ){
				state = RESET;
			}
		break;
		case INCR :
			if( ( (PINA & 0x03) > 0x01))  {
				state = RESET;
			}
		break;
		case DECR :
			if( PINA && ( (PINA & 0x03) != 0x02) ){
				state = RESET;
			}
		break;
		case RESET :
			state = START;
		break;
		default:
		
		break;
	}   
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; 
    DDRC = 0xFF;
    /* Insert your solution below */
    PORTB = 0x01;
    while (1) {
	while (1) {
          Tick();
      }
    }
    return 1;
}

