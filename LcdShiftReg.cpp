#include "LcdShiftReg.h"

#include <avr/io.h>

LcdShiftReg::LcdShiftReg()
{
	DDRA |= (1 << PA0) | (1 << PA1) | (1 << PA2);
}

void LcdShiftReg::setPin(volatile uint8_t *port, uint8_t pin, bool value) const
{
	if (value == true)
	{
		*port |= (1 << pin);
	}
	else
	{
		*port &= ~(1 << pin);
	}
}

void LcdShiftReg::setSerialPin(bool value)
{
	setPin(&PORTA, PA2, value);
}

void LcdShiftReg::setShiftPin(bool value)
{
	setPin(&PORTA, PA0, value);
}

void LcdShiftReg::setStoragePin(bool value)
{
	setPin(&PORTA, PA1, value);
}
