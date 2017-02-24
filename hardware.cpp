#include "hardware.h"
#include "avr/io.h"

void delay_ms(double delay)
{
	// prescaler: 1024
	TCCR0B = (1 << CS02) | (1 << CS00);
	TCNT0 = 0;

	while (TCNT0 <= delay)
	{
		if (TCNT0 >= 49)
		{
			delay -= 50;
			TCNT0 = 0;
		}
	}
}

void delay_us(double delay)
{
	// prescaler: 1
	TCCR0B = (1 << CS00);
	TCNT0 = 0;

	while (TCNT0 <= delay)
	{
		if (TCNT0 >= 50)
		{
			delay -= 50;
			TCNT0 = 0;
		}
	}
}
