#include "Hardware.h"
#include "MyLcd.h"

extern "C" void __cxa_pure_virtual(void)
{
	
}

int main()
{
	MyLcd lcd;
	delay_us(40e3);
	lcd.initDisplay();
	
	uint16_t counter = 0;

	while (true)
	{
		lcd.clear();		
		
		lcd.output(counter / 60);
		lcd.output("m " );
		lcd.output(counter % 60);
		lcd.output("s");

		++counter;
		
		for (uint8_t i = 0; i < 20; ++i)
		{
			delay_us(50e3);
		}
	}
}
