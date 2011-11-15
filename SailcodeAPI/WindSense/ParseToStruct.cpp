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
	char* pEnd;
	char minutes[5];
	char degrees[5];

	for (int i = 0; i < 4; i++) {
		minutes[i] = stringArray[1][i];
		degrees[i] = stringArray[1][i+5];
	}
	minutes[4] = '\0';
	degrees[5] = '\0';

	GPS_GPGLL.minuteLatitude = (int)strtol(minutes,&pEnd,10);
	GPS_GPGLL.degreeLatitude = (int)strtol(degrees,&pEnd,10);

	for (int i = 0; i < 4; i++) {
		minutes[i] = stringArray[3][i];
		degrees[i] = stringArray[3][i+5];
	}
	minutes[4] = '\0';
	degrees[5] = '\0';

	GPS_GPGLL.minuteLongitude = (int)strtol(minutes,&pEnd,10);
	GPS_GPGLL.degreeLongitude = (int)strtol(degrees,&pEnd,10);
	
	GPS_GPGLL.latitudeDirection = stringArray[2][0];
	GPS_GPGLL.longitudeDirection = stringArray[4][0];

	// Debugging Nov 14, remove if found
	Serial.print("The current value of String 1 is ");
	Serial.println(stringArray[1]);
	Serial.print("Minutes in string ");
	Serial.println(minutes);
	Serial.print("Degrees in String ");
	Serial.println(degrees);

	return 1;
}

/** Update the Wind Data Struct by Parsing
 *
 * Simply converts the strings into the correct types.
 *
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

/** Update the Speet Data Struct by Parsing
 *
 * Converts strings into the correct types.
 *
 * @out [SPEED_GPVTG] All Data Fields
 */
int WindSense::updateSPEED_GPVTG() {
	// $GPVTG,224.9,T,237.5,M,0.0,N,0.0,K,A*2D
	
	SPEED_GPVTG.courseoverGround = strtod(stringArray[1], '\0');
	SPEED_GPVTG.unitCourseMeasurement = stringArray[2][0];
	SPEED_GPVTG.speedoverGround = strtod(stringArray[5], '\0');
	SPEED_GPVTG.speedUnits = stringArray[6][0];
	
	return 1;
}
