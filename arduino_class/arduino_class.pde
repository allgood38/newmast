#include "LED13.h"

LED13 led; //!< initialises an instance of the class

void setup() {
	led.test_var = 4;
}

void loop() {
	led.blink(100);
}
