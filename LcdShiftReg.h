#pragma once

#include "DeviceLib/ShiftRegister.h"

class LcdShiftReg : public ShiftRegister
{
	public:
	LcdShiftReg();

	private:
	void setPin(volatile uint8_t *port, uint8_t pin, bool value) const;

	virtual void setSerialPin(bool value) override;
	virtual void setShiftPin(bool value) override;
	virtual void setStoragePin(bool value) override;
};