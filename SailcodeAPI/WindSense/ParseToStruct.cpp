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

	if (strcmp(input,"GPGLL") == 0) {
		//	updateGPS_GPGLL
		updateGPS_GPGLL();
	} else if (strcmp(input, "WIMWV") == 0) {
		// Update Something else
		updateWIND_WIMWV();
	} else if (strcmp(input, "GPVTG") == 0) {
		updateSPEED_GPVTG();
	} else {
		// TODO Handle parse without valid
		// NMEA label
	}

	return 1;
}

/** Update the GPS Data Struct by parsing
 *
 * Given that the format of the latitude and longitude
 * are given in a form which exceeds the accuracy of our
 * Arduino, we need to break it into minutes and degrees
 * into separate integers.
 *
 * @out	[GPS_GPGLL] All data fields
 */
int WindSense::updateGPS_GPGLL() {
	char* pEnd;
	char minutes[10];
	char degrees[10];

	/* The AIRMAR Actually reports invalid data, check it
	 * here and abort with 0 if invalid, not doing this
	 * will definitely crash the for loops
	 */
	if (stringArray[6][0] == 'V') {
		return 0;
	}

	// Since there will be parsing, an index will be used
	int idx = 0;

	/* The following two loops parse the latitude, uses
	 * the period as a separator between the minutes
	 * and degrees
	 */
	for (int i = 0; stringArray[1][idx] != '.'; i++) {
		minutes[i] = stringArray[1][idx++];
		// Always keeping a null at the end
		minutes[i+1] = '\0';
	}
	// Skip the period
	idx++;
	for (int i = 0; stringArray[1][idx] != '\0'; i++) {
		degrees[i] = stringArray[1][idx++];
		degrees[i+1] = '\0';
	}

	// Extract int from the isolated strings
	GPS_GPGLL.minuteLatitude = (int)strtol(minutes,&pEnd,10);
	GPS_GPGLL.degreeLatitude = (int)strtol(degrees,&pEnd,10);

	idx=0;
	for (int i = 0; stringArray[3][idx] != '.'; i++) {
		minutes[i] = stringArray[3][idx++];
		minutes[i+1] = '\0';
	}
	idx++;
	for (int i = 0; stringArray[3][idx] != '\0'; i++) {
		degrees[i] = stringArray[3][idx++];
		degrees[i+1] = '\0';
	}

	GPS_GPGLL.minuteLongitude = (int)strtol(minutes,&pEnd,10);
	GPS_GPGLL.degreeLongitude = (int)strtol(degrees,&pEnd,10);
	
	GPS_GPGLL.latitudeDirection = stringArray[2][0];
	GPS_GPGLL.longitudeDirection = stringArray[4][0];

	return 1;
}

/** Update the Wind Data Struct by Parsing
 *
 * Simply converts the strings into the correct types.
 *
 * @out [WIND_WIMWV] All Data Fields
 */
int WindSense::updateWIND_WIMWV() {
	// Check if the AIRMAR says the data is valid
	if (stringArray[5][0] == 'V') {
		return 0;
	}

	WIND_WIMWV.windAngle      = strtod(stringArray[1],'\0');
	WIND_WIMWV.reference      = stringArray[2][0];
	WIND_WIMWV.windSpeed      = strtod(stringArray[3],'\0');
	WIND_WIMWV.windSpeedUnits = stringArray[4][0];
	WIND_WIMWV.valid          = stringArray[5][0];

	return 1;
}

/** Update the Speet Data Struct by Parsing
 *
 * Converts strings into the correct types.
 *
 * @out [SPEED_GPVTG] All Data Fields
 */
int WindSense::updateSPEED_GPVTG() {
	// Check if the AIRMAR says the data is valid
	if (stringArray[9][0] == 'N') {
		return 0;
	}
	
	SPEED_GPVTG.courseoverGround      = strtod(stringArray[1], '\0');
	SPEED_GPVTG.unitCourseMeasurement = stringArray[2][0];
	SPEED_GPVTG.speedoverGround       = strtod(stringArray[5], '\0');
	SPEED_GPVTG.speedUnits            = stringArray[6][0];
	
	return 1;
}
