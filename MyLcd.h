#pragma once

#include "LcdShiftReg.h"
#include "DeviceLib/Lcd.h"

class MyLcd : public Lcd
{
private:
	LcdShiftReg m_lcdShiftReg;
	
private:
	void execute(uint8_t data, bool RS);

	virtual void execute(const Command &cmd, bool RS, uint16_t delay_us) override;
};
