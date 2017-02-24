#pragma once

#include "LcdShiftReg.h"
#include "DeviceLib/Lcd.h"

class MyLcd : public Lcd
{
private:
	LcdShiftReg m_lcdShiftReg;
	
private:
	virtual void execute(const Command &cmd, bool RS, double delay) override;
};
