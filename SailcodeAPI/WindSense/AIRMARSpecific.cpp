/** Stuff related purely to out wind sensor set-up
 *
 * Things like the initialisation after instantiation of the
 * object, and some debugging function stuff.
 */
#include "WindSense.h"

/** Waits for NMEA, tells you everything
 *
 * This function takes a serial port to use for debugging
 * the functions and listens for an NMEA sentence. Then it
 * runs through them with the  validation, splitting and
 * parsing functions. It spits out output the entire way.
 *
 * @note The Serial port given to this function must have
 * already had the baud rate set
 */
int WindSense::debug(HardwareSerial &debugPortIn) {
	debugPort = &debugPortIn;
	while (!debugPort->available()) {
		// DO Nothing
	}
	while (!grabChar(debugPort->read())) {
		// DO Nothing
		debugPort->println("Got a char");
	}

	// Information about what is in the partSentence Buffer
	debugPort->println("NMEA Detected");
	debugPort->println(partSentence);
	debugPort->print("Valid?...");
	debugPort->println(validateInternalNMEA());

	// Separating the NMEA into sub-strings
	splitInternalNMEA();
	for (int i = 0; i < stringArrayIdx; i++) {
		debugPort->print("String ");
		debugPort->print(i);
		debugPort->print(" ");
		debugPort->println(stringArray[i]);
	}

	parseInternalNMEA(stringArray[0]);

	// Dump the degrees and minutes to see if it worked
	Serial.print("The minutes lattitude are ");
	Serial.println(GPS_GPGLL.minuteLatitude);
	Serial.print("The degrees lattitude are ");
	Serial.println(GPS_GPGLL.degreeLatitude);
	Serial.print("Lattitude Direction is ");
	Serial.println(GPS_GPGLL.latitudeDirection);

	Serial.print("The minutes longitude are ");
	Serial.println(GPS_GPGLL.minuteLongitude);
	Serial.print("The degrees longitude are ");
	Serial.println(GPS_GPGLL.degreeLongitude);
	Serial.print("longitude Direction is ");
	Serial.println(GPS_GPGLL.longitudeDirection);

	Serial.print("Wind Speed is ");
	Serial.println(WIND_WIMWV.windSpeed);
	Serial.print("Units for the speed ");
	Serial.println(WIND_WIMWV.windSpeedUnits);
	Serial.print("The angle is ");
	Serial.println(WIND_WIMWV.windAngle);
	Serial.print("The reference for that angle ");
	Serial.println(WIND_WIMWV.reference);

	Serial.print("Speed over ground ");
	Serial.println(SPEED_GPVTG.speedoverGround);
	Serial.print("Units ");
	Serial.println(SPEED_GPVTG.speedUnits);
	Serial.print("Course over ground ");
	Serial.println(SPEED_GPVTG.courseoverGround);
	Serial.print("Units ");
	Serial.println(SPEED_GPVTG.unitCourseMeasurement);

	resetInternalNMEA();

	delay(1000);
	return 1;
}
