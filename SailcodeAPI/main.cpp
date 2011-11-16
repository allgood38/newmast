#include <WProgram.h>
#include <arduino.h>
#include "WindSense/WindSense.h"

/** For now, the only purpose of this file is testing
 *
 * Currently checking out the state of the WindSense
 * Library and adding support for parsing NMEA values
 * into appropriate types.
 *
 */
// Variables
WindSense airman;

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
	airman.debug(Serial);
}

