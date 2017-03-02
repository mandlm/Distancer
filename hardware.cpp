#include "hardware.h"
#include "avr/io.h"

void delay_us(uint16_t delay)
{
	TCCR1B = (1 << CS10);
	TCNT1 = 0;

	while (true)
	{
		if (TCNT1 >= delay)
		{
			return;
		}
	}
}

