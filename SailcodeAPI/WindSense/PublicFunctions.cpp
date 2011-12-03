/** All of the functions visible to the user.
 * PublicFunctions.cpp
 *
 *  Created on: Dec 2, 2011
 *      Author: allgood38
 */
#include "WindSense.h"

/** Wait until all the possible values from the wind sensor updated
 *
 * Within the maximum amount of time, wait for enough serial data
 * to parse all of the known values from the wind sensor.
 *
 * After every valid sentence
 */
int WindSense::pollAllValues() {
	const int recentlyUpdatedTime = 500;
	int timeStart = millis() - 10;
	int timeElapsed = millis() - timeStart;

	bool GPGLL_Updated = false;
	bool WIMWV_Updated = false;
	bool GPVTG_Updated = false;
	bool successfullParse = false;

	char* lastUpdated = '\0';

	while (!GPGLL_Updated || !WIMWV_Updated || !GPVTG_Updated) {

		if (senSerial->available() > MAX_SERIAL_BUFFER) {
			senSerial->flush();
		} else if (senSerial->available() && grabChar(senSerial->read())) {
			successfullParse = !(bool)processInternalNMEA();
		}

		/* Check to see which structure was just updated
		 */
		if (successfullParse) {
			if (GPS_GPGLL.lastUpdated > millis() - recentlyUpdatedTime) {
				GPGLL_Updated = true;
			} else if (WIND_WIMWV.lastUpdated > millis() - recentlyUpdatedTime) {
				WIMWV_Updated = true;
			} else if (SPEED_GPVTG.lastUpdated > millis() - recentlyUpdatedTime) {
				GPVTG_Updated = true;
			}
			successfullParse = false;
		}

		/* Further Conditions on the loop,
		 * if too much time has passed, abort */
		timeElapsed = millis() - timeStart;
		if (timeElapsed > MAX_POLL_TIME_MS) {
			return 1;
		}
	}

	return 0;
}

int WindSense::attach(HardwareSerial& sensorPort) {
	if (&sensorPort == NULL) {
		return 1;
	}
	senSerial = &sensorPort;
	return 0;
}

