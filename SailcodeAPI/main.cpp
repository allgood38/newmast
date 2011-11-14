#include <WProgram.h>
#include <arduino.h>
#include "WindSense/WindSense.h"

/*

 */
// Variables
WindSense airman;
// Prototypes
void dump();

int main(void) {
    init();

    setup();

    for (;;)
        loop();

    return 0;
}

void setup() {
    // Initialise the digital pin as an output.
    // Pin 13 has an LED connected on most Arduino boards:
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    Serial.println("Ready and awaiting input");
}

void loop() {
	while(Serial.available()) {
		if (airman.grabChar(Serial.read())) {
			dump();
		}
	}
}

void dump() {
	// Information about what is in the partSentence Buffer
	Serial.println("NMEA Detected");
	Serial.println(airman.partSentence);
	Serial.print("Valid?...");
	Serial.println(airman.validateInternalNMEA());

	// Separating the NMEA into sub-strings
	airman.splitInternalNMEA();
	for (int i = 0; i < airman.stringArrayIdx; i++) {
		Serial.print("String ");
		Serial.print(i);
		Serial.print(" ");
		Serial.println(airman.stringArray[i]);
	}

	airman.parseInternalNMEA(airman.stringArray[0]);

	// Dump the degrees and minutes to see if it worked
	Serial.print("The degrees lattitude are ");
	Serial.println(airman.GPS_GPGLL.degreeLatitude);
	Serial.print("The minutes lattitude are ");
	Serial.println(airman.GPS_GPGLL.minuteLatitude);

	// Reseting the internal variables
	airman.resetInternalNMEA();
}
