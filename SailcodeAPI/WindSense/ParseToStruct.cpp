/** Contains all of the parsing functions
 * parseToStruct.cpp
 * 
 * Due to the large number of functions used to parse
 * char* instanced into proper types in the structs
 * declared in the header file, this has been created.
 *
 * It simply contains all of the functions to update
 * the values in the structs.
 *
 *  Created on: 2011-11-14
 *      Author: allgood38
 */
#include "WindSense.h"

int WindSense::parseInternalNMEA(char* input) {

	if (strcmp(input,"GPGLL")) {
		//	updateGPS_GPGLL
		updateGPS_GPGLL();
	} else if (strcmp(input, "WIMWV")) {
		// Update Something else
		updateWIND_WIMWV();
	}
	return 1;
}

/** Update the GPS Data Struct by parsing
 *
 * Given that the format of the lattitude and longitude
 * are given in a form which exceeds the accuracy of our
 * Arduino, we need to break it into minutes and degrees
 * into separate integers.
 *
 * @out	[GPS_GPGLL] All data fields
 */
int WindSense::updateGPS_GPGLL() {
	char minutesLattitude[4];
	char degreesLattitude[4];

	for (int i = 0; i < 3 && stringArray[1][0] != '\0'; i++) {
		minutesLattitude[i] = stringArray[1][i];
		// Offset of 5, given the format of string
		degreesLattitude[i] = stringArray[1][i+5];
	}

	GPS_GPGLL.minuteLatitude = atoi(minutesLattitude);
	GPS_GPGLL.degreeLatitude = atoi(degreesLattitude);

	GPS_GPGLL.minuteLongitude = atoi(minutesLattitude);
	GPS_GPGLL.degreeLongitude = atoi(degreesLattitude);

	GPS_GPGLL.latitudeDirection = stringArray[2][0];
	GPS_GPGLL.longitudeDirection = stringArray[4][0];

	return 1;
}

/** Update the Wind Data Struct by Parsing
 *
 * Simply converts the strings into the correct types.
 * Since there is trouble with the standard strtod
 * function, the Arduino Built-in function is used
 *
 * @note Use of Arduino Functions
 * @out [WIND_WIMWV] All Data Fields
 */
int WindSense::updateWIND_WIMWV() {
	WIND_WIMWV.windAngle      = strtod(stringArray[1],'\0');
	WIND_WIMWV.reference      = stringArray[2][0];
	WIND_WIMWV.windSpeed      = strtod(stringArray[3],'\0');
	WIND_WIMWV.windSpeedUnits = stringArray[4][0];
	WIND_WIMWV.valid          = stringArray[5][0];

	return 1;
}

