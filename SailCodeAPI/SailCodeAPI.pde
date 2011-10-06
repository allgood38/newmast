/** The main file, currently for testing purposes.
 *
 * Later on this file might not be necessary, since all of the functions needed
 * will probably just be kept in their own libraries.
 */

#include <WindSense.h>

int n = 0; // Purely for testing with the dummy function
char collect[] = {""};

WindSense test;
int testTinyGPS();
char dummyRead();

void setup() {
	Serial.begin(9600);
}

void loop() {
	Serial.println(dummyRead());
	delay(100);
}

int collectString(char input) {
	
}

char dummyRead() {
	char nm[] = {"$GPGLL,3751.65,S,14507.36,E*77"};
	n++;
	if (n==sizeof(nm)-1) {
		n = 0;
	}
	return nm[n];
}

/** TinyGPS test function.
 * Uses a premade string to see if the GPS functions can parse it.
 * This function should be moved into a testing file later. */
int testTinyGPS() {
	Serial.println("TinyGPS has been called.");
	TinyGPS gps;
	char nm[] = {"$GPGLL,3751.65,S,14507.36,E*77"};
	long lat, lon;
	unsigned long fix_age, time, date, speed, course;
	unsigned long chars;
	unsigned short sentences, failed_checksum;
	
	int i;
	for (i = 0; i <= sizeof(nm); i++) {
		if (gps.encode(nm[i])) {
			// Save the values in the member variables
			Serial.println("GPS Reports a valid string.");
		}
	}
	gps.get_position(&lat, &lon, &fix_age);
	Serial.println(lat); Serial.println(lon); Serial.println(fix_age);
}
