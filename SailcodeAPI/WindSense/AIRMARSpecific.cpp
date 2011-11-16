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
 * For this function to work properly, it must be called
 * within a loop. If this were the only line to be executed
 * in the main loop, it would work as expected.
 *
 * @NOTE The Serial port given to this function must have
 * already had the baud rate set
 */
int WindSense::debug(HardwareSerial &debugPortIn) {
	HardwareSerial* debugPort = &debugPortIn;

	while(debugPort->available()) {
		if (grabChar(debugPort->read())) {
			debugDump(*debugPort);
		}
	}

	return 1;
}

/** Dumps a lot of info to the computers serial line
 *
 * Would have been incorporated directly into the debug
 * function, but it just takes up too much space. In the
 * event the flash image for the arduino becomes too large
 * be sure to get rid of this function.
 *
 * @NOTE Resets the Internal NMEA Index counters
 */
int WindSense::debugDump(HardwareSerial &debugPortIn) {
	HardwareSerial* debugPort = &debugPortIn;

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
	debugPort->print("The minutes lattitude are ");
	debugPort->println(GPS_GPGLL.minuteLatitude);
	debugPort->print("The degrees lattitude are ");
	debugPort->println(GPS_GPGLL.degreeLatitude);
	debugPort->print("Lattitude Direction is ");
	debugPort->println(GPS_GPGLL.latitudeDirection);

	debugPort->print("The minutes longitude are ");
	debugPort->println(GPS_GPGLL.minuteLongitude);
	debugPort->print("The degrees longitude are ");
	debugPort->println(GPS_GPGLL.degreeLongitude);
	debugPort->print("longitude Direction is ");
	debugPort->println(GPS_GPGLL.longitudeDirection);

	debugPort->print("Wind Speed is ");
	debugPort->println(WIND_WIMWV.windSpeed);
	debugPort->print("Units for the speed ");
	debugPort->println(WIND_WIMWV.windSpeedUnits);
	debugPort->print("The angle is ");
	debugPort->println(WIND_WIMWV.windAngle);
	debugPort->print("The reference for that angle ");
	debugPort->println(WIND_WIMWV.reference);

	debugPort->print("Speed over ground ");
	debugPort->println(SPEED_GPVTG.speedoverGround);
	debugPort->print("Units ");
	debugPort->println(SPEED_GPVTG.speedUnits);
	debugPort->print("Course over ground ");
	debugPort->println(SPEED_GPVTG.courseoverGround);
	debugPort->print("Units ");
	debugPort->println(SPEED_GPVTG.unitCourseMeasurement);

	resetInternalNMEA();
	return 1;
}