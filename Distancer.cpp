#include "Hardware.h"
#include "MyLcd.h"

#include <avr/io.h>

extern "C" void __cxa_pure_virtual(void)
{
	
}

int main()
{
	MyLcd lcd;
	delay_ms(40);
	lcd.initDisplay();
	
	uint16_t counter = 0;

	while (true)
	{
		lcd.clear();
		lcd.output(counter++);
		lcd.output('s');

		delay_ms(1000);
	}
}
