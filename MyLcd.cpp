#include "MyLcd.h"
#include "Hardware.h"

void MyLcd::execute(const Command &cmd, bool RS, double delay)
{
	static const uint8_t eMask = 0b00000010;
	static const uint8_t rsMask = 0b01000000;
	//static const double pulseLength = 0.5;

	{
		uint8_t output = (cmd.data & 0xf0) >> 2;
		if (RS)
		{
			output |= rsMask;
		}

		m_lcdShiftReg.set(output | eMask);
		//delay_us(pulseLength);
		m_lcdShiftReg.set(output);
	}

	{
		uint8_t output = (cmd.data & 0x0f) << 2;
		if (RS)
		{
			output |= rsMask;
		}

		m_lcdShiftReg.set(output | eMask);
		//delay_us(pulseLength);
		m_lcdShiftReg.set(output);
	}

	delay_ms(delay);
}



