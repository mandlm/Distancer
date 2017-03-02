#include "LcdShiftReg.h"

#include <avr/io.h>

LcdShiftReg::LcdShiftReg()
{
	DDRA |= (1 << PA0) | (1 << PA1) | (1 << PA2);
}

void LcdShiftReg::setPin(volatile uint8_t *port, uint8_t pin) const
{
	*port |= (1 << pin);
}

void LcdShiftReg::clearPin(volatile uint8_t *port, uint8_t pin) const
{
	*port &= ~(1 << pin);
}

void LcdShiftReg::setSerialPin(bool value)
{
	if (value == true)
	{
		setPin(&PORTA, PA2);		
	}
	else
	{
		clearPin(&PORTA, PA2);
	}
}

void LcdShiftReg::pulseShiftPin()
{
	clearPin(&PORTA, PA0);
	setPin(&PORTA, PA0);
	clearPin(&PORTA, PA0);
}

void LcdShiftReg::pulseStoragePin()
{
	clearPin(&PORTA, PA1);
	setPin(&PORTA, PA1);
	clearPin(&PORTA, PA1);
}

