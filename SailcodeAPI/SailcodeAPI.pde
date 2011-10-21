#include <WindSense.h>

WindSense sense;

// A NMEA String for testing
char nm[] = {"askdjfhalkjha$GPGSV,2,1,08,01,40,083,46,02,17,308,41,12,07,344,39,14,22,228,45*75asdf"};
int nmIdx = 0;

void setup() {
	Serial.begin(9600);
	Serial3.begin(4800);
	delay(100);
}

void loop() {

	while(Serial3.available() && !sense.grabChar(Serial3.read())) {
	}

	sense.debug();
	delay(100);
}

char test_feed() {
	nmIdx = (nmIdx + 1) % sizeof(nm);
	return nm[nmIdx];
}
