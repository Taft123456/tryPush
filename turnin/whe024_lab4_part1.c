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

enum States {B0_LED_ON, B1_LED_ON} state;

void Tick()
{ 
 	switch(state){
		case B0_LED_ON : 
			PORTB = 0x01;
		break;
		case B1_LED_ON :
			PORTB = 0x02;
		break;
		default :
		
		break;
	}
	switch(state){
                case B0_LED_ON :
                        if((PINA & 0x01) == 0X01)
                        {
                         state = B1_LED_ON;
                        }
                        break;
                case B1_LED_ON :
                        if((PINA & 0x01) == 0X01)
                        {
                         state = B0_LED_ON;
                        }
                        break;
                        default :

                        break;
        }   
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; 
    DDRB = 0xFF;
    /* Insert your solution below */
    PORTB = 0x01;
    while (1) {
	while (1) {
          Tick();
      }
    }
    return 1;
}

