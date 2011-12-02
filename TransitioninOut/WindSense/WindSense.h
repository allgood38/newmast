#ifndef WindSense_H
#define WindSense_H

#include <WProgram.h> // This brings in the Arduino Standard Functions

class WindSense {
	public:
		int grabChar(char input);
		int validateNMEA(char* input);
		int parseNMEA(char* input);
		int parseInternalNMEA();
		void debug();
};

#endif
