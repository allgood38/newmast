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
	Serial.print("The minutes lattitude are ");
	Serial.println(airman.GPS_GPGLL.minuteLatitude);
	Serial.print("The degrees lattitude are ");
	Serial.println(airman.GPS_GPGLL.degreeLatitude);
	Serial.print("Lattitude Direction is ");
	Serial.println(airman.GPS_GPGLL.latitudeDirection);

	Serial.print("The minutes longitude are ");
	Serial.println(airman.GPS_GPGLL.minuteLongitude);
	Serial.print("The degrees longitude are ");
	Serial.println(airman.GPS_GPGLL.degreeLongitude);
	Serial.print("longitude Direction is ");
	Serial.println(airman.GPS_GPGLL.longitudeDirection);

	Serial.print("Wind Speed is ");
	Serial.println(airman.WIND_WIMWV.windSpeed);
	Serial.print("Units for the speed ");
	Serial.println(airman.WIND_WIMWV.windSpeedUnits);
	Serial.print("The angle is ");
	Serial.println(airman.WIND_WIMWV.windAngle);
	Serial.print("The reference for that angle ");
	Serial.println(airman.WIND_WIMWV.reference);
	
	Serial.print("Speed over ground ");
	Serial.println(airman.SPEED_GPVTG.speedoverGround);
	Serial.print("Units ");
	Serial.println(airman.SPEED_GPVTG.speedUnits);
	Serial.print("Course over ground ");
	Serial.println(airman.SPEED_GPVTG.courseoverGround);
	Serial.print("Units ");
	Serial.println(airman.SPEED_GPVTG.unitCourseMeasurement);

	// Reseting the internal variables
	airman.resetInternalNMEA();
}
