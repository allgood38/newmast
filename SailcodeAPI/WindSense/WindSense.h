#ifndef WindSense_H
#define WindSense_H

//It doesn't appear as though this class will require use of the built in
//Arduino functions
#include <WProgram.h> // This brings in the Arduino Standard Functions
#include <stdlib.h>

class WindSense {
public:
    WindSense();
    int grabChar(char input);
    int validateNMEA(char* input);
    int validateInternalNMEA();
    int parseNMEA(char* input);
    int parseInternalNMEA();
    void resetInternalNMEA();

    int partCount;            //!< index for partSentence
    char partSentence[100];   //!< buffer for incoming NMEA for grabChar function

    char stringArray[40][15]; //!< Array of strings for parseNMEA
    int stringArrayIdx;       //!< index for the array of strings

};

#endif
