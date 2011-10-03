/** The main file, currently for testing purposes.
 *
 * Later on this file might not be necessary, since all of the functions needed
 * will probably just be kept in their own libraries.
 */

#include <WindSense.h>

void setup() {
	Serial.begin(9600);
}

void loop() {
}

/** TinyGPS test function.
 * Uses a premade string to see if the GPS functions can parse it.
 * This function should be moved into a testing file later. */
int testTinyGPS() {
	TinyGPS gps;
	char nm[] = {"$GPGLL,5330.12,N,00215.31,W,134531,A*2"};
	long lat, lon;
	unsigned long fix_age, time, date, speed, course;
	unsigned long chars;
	unsigned short sentences, failed_checksum;
	
	int i;
	for (i = 0; i < sizeof(nm); i++) {
		int c = nm[i];
		if (gps.encode(c)) {
			// Save the values in the member variables
			Serial.println("GPS Reports a valid string.");
		}
	}
	gps.get_position(&lat, &lon, &fix_age);
	Serial.println(lat); Serial.println(lon); Serial.println(fix_age);
}
