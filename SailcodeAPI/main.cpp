/** @mainpage
 *
 * @section intro Introduction
 * This is a complete rewrite of the original sailcode, the idea is to break
 * the main functions of the boat into reusable libraries. Each library is a
 * class with a bunch of member functions and some data structs.
 *
 * There should be a library for the Wind Sensor and compass, the Polulu, any
 * ethernet communications and maybe the sailing logic.
 * 	senSerial->println("$PAMTC,EN,RMC,0,10");
 */

#include <WProgram.h>
#include <arduino.h>

#include <Servo/Servo.h>
#include <SD/SD.h>

#include "WindSense/WindSense.h"
#include "Debugging/Debugging.h"

/** For now, the only purpose of this file is testing
 *
 * Currently checking out the state of the WindSense
 * Library and adding support for parsing NMEA values
 * into appropriate types.
 *
 */
// Variables
WindSense airman;
Debugging panic;

Servo myservo;

char debugString[50] = {'\0'};

int main(void) {
    init();

    setup();

    for (;;)
        loop();

    return 0;
}

void setup() {
	Serial.begin(19200);
	airman.attach(Serial);

	myservo.attach(6);
	panic.attach(Serial);
    panic.println("Ready for action");
}

void loop() {
	airman.pollAllValues();
	itoa(airman.stupidDebug(),debugString,10);
	panic.println(debugString);
}

