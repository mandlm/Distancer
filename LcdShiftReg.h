#pragma once

#include "DeviceLib/ShiftRegister.h"

class LcdShiftReg : public ShiftRegister
{
public:
	LcdShiftReg();

private:
	void setPin(volatile uint8_t *port, uint8_t pin) const;
	void clearPin(volatile uint8_t *port, uint8_t pin) const;

	virtual void setSerialPin(bool value) override;

	virtual void pulseShiftPin() override;
	virtual void pulseStoragePin() override;
};