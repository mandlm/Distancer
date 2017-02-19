#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

#include "DeviceLib/ShiftRegister.h"

void setupStatusLedPin()
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
	setupStatusLedPin();

	while (true)
	{
		flashStatusLed();
		_delay_ms(400);
	}
}
