#include "WindSense.h"

WindSense::WindSense() {
}

WindSense::~WindSense() {
}

double WindSense::getGPSLatitude() {
}

double WindSense::getGPSLongitude() {

}

int WindSense::updateGPSData() {
}

int WindSense::dumpToScreen() {
}

// Functions to deal with NMEA Strings

int grabNMEAChar(char input) {
	if (partCount > 0 || input == '$') {
		partSentence[partCount] = input;
		partCount++;
	}

	if (partCount > 3 && partSentence[partCount-3] == '*') {
		return 1;
	}
	return 0;
}



