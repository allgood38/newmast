#ifndef WindSense_H
#define WindSense_H

// This brings in the Arduino Standard Functions
// For the Hardware Serial Functions only
// and the delay function used during initialisation
#include <WProgram.h>
#include <stdlib.h>   // Parsing Functions
#include <string.h>   // String Comparison Functions
//#include <HardwareSerial.h>

class WindSense {
public:
    WindSense();
    WindSense(HardwareSerial* inSerial);
    int grabChar(char input);

    int validateNMEA(char* input);
    int validateInternalNMEA();

    int splitNMEA(char* input);
    int splitInternalNMEA();

    int parseInternalNMEA(char* input);
    int updateGPS_GPGLL();
	int updateWIND_WIMWV();
	int updateSPEED_GPVTG();

    void resetInternalNMEA();

    int partCount;            //!< index for partSentence
    char partSentence[100];   //!< buffer for incoming NMEA for grabChar function
    char stringArray[40][15]; //!< Array of strings for splitNMEA
    int stringArrayIdx;       //!< index for the array of strings

    /** GPS Data Struct
     * Contains the GPS data from the airmar.
     * Note Lattitude and longitude will be split into two variables 
	 * each otherwise we lose precision
     */
    struct GPGLL {
        int degreeLatitude;
        int minuteLatitude;
        char latitudeDirection;

        int degreeLongitude;
        int minuteLongitude;
        char longitudeDirection;

		char valid;
    };

    struct WIMWV {
        double windAngle;
        char reference;

        double windSpeed;
        char windSpeedUnits;

        char valid;
    };

    struct GPVTG {
        double courseoverGround;
        char   unitCourseMeasurement;
        double speedoverGround;
        char   speedUnits;
    };

    // Create Instances of the structs so that they can
    // be updated
    GPGLL GPS_GPGLL;
	WIMWV WIND_WIMWV;
	GPVTG SPEED_GPVTG;

	// Create an instance of the Hardware Serial
	// to be used within the class
	HardwareSerial* senSerial;
};

#endif
