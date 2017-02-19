#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

#include "LcdShiftReg.h"

void setupStatusLed()
{
	DDRB |= (1 << PB0);
}

void flashStatusLed()
{
	PORTB |= (1 << PB0);
	_delay_ms(100);
	PORTB &= ~(1 << PB0);
}

int main()
{
	setupStatusLed();

	LcdShiftReg lcdShiftReg;

	while (true)
	{
		flashStatusLed();
		_delay_ms(400);

		lcdShiftReg.set(1);
		_delay_ms(100);
		lcdShiftReg.set(0);
		_delay_ms(400);

		lcdShiftReg.set(1 << 1);
		_delay_ms(100);
		lcdShiftReg.set(0);
		_delay_ms(400);

		lcdShiftReg.set(1 << 7);
		_delay_ms(100);
		lcdShiftReg.set(0);
		_delay_ms(400);
	}
}
