#include "MyLcd.h"
#include "Hardware.h"

void MyLcd::execute(uint8_t data, bool RS)
{
	static const uint8_t eMask = 0b00000010;
	static const uint8_t rsMask = 0b01000000;

	if (RS)
	{
		data |= rsMask;
	}

	m_lcdShiftReg.set(data | eMask);
	m_lcdShiftReg.set(data);
}

void MyLcd::execute(const Command &cmd, bool RS, uint16_t delay)
{
	execute((cmd.data & 0xf0) >> 2, RS);
	execute((cmd.data & 0x0f) << 2, RS);
	delay_us(delay);
}



