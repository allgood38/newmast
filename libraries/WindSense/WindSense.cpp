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

	while (Serial.available() && i < 500) {
		int c = Serial.read();
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

}

