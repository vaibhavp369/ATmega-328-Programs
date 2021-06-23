/*
 * Fast_PWM_Duty_Cycle_Control.c
 *
 * Created: 18/05/2021 9:25:42 PM
 * Author : vaibhav
 */ 

/*
About : Program is about Duty cycle control using ouput compare register.

*/

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#define LED		6

void ddr_init()
{
	DDRD |= (1<<LED);
	PORTD &= ~(1<<LED);
}

void led_on()
{
	PORTD |= (1<<LED);
}

void led_off()
{
	PORTD &=~(1<<LED);
}

void timer_init()
{
	OCR0A = 127; // 50% duty cycle
	TCCR0A |= ( (1<<WGM01) | (1<<WGM00) | (1<<COM0A1)); // Non-inverting and Fast PWM
	TCCR0A &=~( (1<<COM0A0) | (1<<COM0B0) | (1<<COM0B1));
	
	TCCR0B |= ( (1<<CS02) | (1<<CS00) ); 
	TCCR0B &=~( (1<<CS01) );
	
	
}

int main(void)
{
	ddr_init();
	timer_init();
	
    while (1) 
    {
		OCR0A++;
		_delay_ms(200);
		
    }
}

