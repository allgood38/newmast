#include "LED13.h" 

/** Setup the Pin Constant, but note that it is stored in a byte. */
const byte LED_PIN = 13;

int test_var = 2;

/** This function is the constructor for the class, so it isn't actually
 * able to return everything.
 */
LED13::LED13() {
	pinMode(LED_PIN, OUTPUT);
}

LED13::~LED13() {
	// There is nothing to destruct
}

void LED13::on() {
	digitalWrite(LED_PIN, HIGH);
}

void LED13::off() {
	digitalWrite(LED_PIN, LOW);
}

void LED13::blink(int time) {
	on();
	delay(time/2);
	off();
	delay(time/2);
}
