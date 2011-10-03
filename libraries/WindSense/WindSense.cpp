#include "WindSense.h"

WindSense::WindSense() {
	fix_age = 4;
}

WindSense::~WindSense() {
}

double WindSense::getGPSLatitude() {

}

double WindSense::getGPSLongitude() {

}

int WindSense::updateGPSData() {
	int i = 0;

	/* While loop continues until either no more characters are available
	 * or the buffer runs out of data. Note c is type int*/
	while (Serial3.available() && i < 500) {
		int c = Serial3.read();
		/* When encode returns true, it means a valid NMEA sentence has just
		 * been parsed and changed the internal state of the TinyGPS instance
		 */
		if (gps.encode(c)) {
			// Save the values in the member variables
			gps.get_position(&lat, &lon, &fix_age);
			return 0;
		}
		i++;
	}
	/* If the function gets here, it didn't get a valid sentence */
	return 1;
}

int WindSense::dumpToScreen() {
	Serial.print("Lat...");
	Serial.println(lat);
	Serial.print("Lon...");
	Serial.println(lon);
	Serial.print("Fix_age...");
	Serial.println(fix_age);
}
