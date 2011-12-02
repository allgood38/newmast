/** @mainpage
 *
 * @section intro Introduction
 * This is a complete rewrite of the original sailcode, the idea is to break
 * the main functions of the boat into reusable libraries. Each library is a
 * class with a bunch of member functions and some data structs.
 *
 * There should be a library for the Wind Sensor and compass, the Polulu, any
 * ethernet communications and maybe the sailing logic.
 */

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
    Serial.begin(19200);
    Serial.println("Ready and awaiting input");
    Serial3.begin(4800);

    airman.senSerial = &Serial3;
}

void loop() {

	//Serial.println("Regular Output");
	//serialAlias->println("Alias Output");
	airman.debug(Serial);

}

