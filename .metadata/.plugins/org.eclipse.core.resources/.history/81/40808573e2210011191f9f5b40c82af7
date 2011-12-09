/*
 * Debugging.cpp
 *
 *  Created on: Dec 1, 2011
 *      Author: QMAST
 *
 *  See the Header documentation for this.
 */
#include "Debugging.h"

Debugging::Debugging() {

}

int Debugging::takeNote(char* input) {


	return 0;
}

int Debugging::attach(HardwareSerial& serialPort) {
	if (debugOut != NULL) {
		// The output has already been set
		return 1;
	}
	debugOut = &serialPort;
	return 0;
}

int Debugging::println(char* stringIn) {
	if (debugOut == NULL) {
		// The output has not been set
		return 1;
	}

	debugOut->println(stringIn);
	return 0;
}



