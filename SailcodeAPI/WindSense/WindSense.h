#ifndef WindSense_H
#define WindSense_H

#include <WProgram.h> // This brings in the Arduino Standard Functions
#include <stdlib.h>
#include <string.h>


class WindSense {
public:
    WindSense();
    int grabChar(char input);

    int validateNMEA(char* input);
    int validateInternalNMEA();

    int splitNMEA(char* input);
    int splitInternalNMEA();

    int parseInternalNMEA(char* input);
    int updateGPS_GPGLL();
	int updateWIND_WIMWV();

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
        double degreeLatitude;
        double minuteLatitude;
        char latitudeDirection;

        double degreeLongitude;
        double minuteLongitude;
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
        double course_overGround;
        char unitCourse_Measurement;
        double speed_overGround;
        char speed_Units;
    };

    // Create Instances of the structs so that they can
    // be updated
    GPGLL GPS_GPGLL;
	WIMWV WIND_WIMWV;
	GPVTG SPEED_GPVTG;
};

#endif
