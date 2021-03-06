/** Defines the Windsense Class
 *
 * Made up of multiple files, this class is pretty extensive.
 *
 */

#ifndef WindSense_H
#define WindSense_H

#define MAX_SERIAL_BUFFER 120
#define MAX_POLL_TIME_MS 2000 //@< Max time to wait for sensor data update

// This brings in the Arduino Standard Functions
// For the Hardware Serial Functions only
// and the delay function used during initialization
#include <WProgram.h>
#include <stdlib.h>   // Parsing Functions
#include <string.h>   // String Comparison Functions

class WindSense {
private:
	int partCount; //!< index for partSentence
	char partSentence[100]; //!< buffer for incoming NMEA for grabChar function
	char stringArray[40][15]; //!< Array of strings for splitNMEA
	int stringArrayIdx; //!< index for the array of strings

	/** GPS Data Struct
	 * Contains the GPS data from the airmar.
	 * Note Lattitude and longitude will be split into two variables
	 * each otherwise we lose precision
	 */
	struct GPGLL {
		int lastUpdated;
		int degreeLatitude;
		int minuteLatitude;
		char latitudeDirection;

		int degreeLongitude;
		int minuteLongitude;
		char longitudeDirection;

		char valid;
	};

	struct WIMWV {
		int lastUpdated;
		double windAngle;
		char reference;

		double windSpeed;
		char windSpeedUnits;

		char valid;
	};

	struct GPVTG {
		int lastUpdated;
		double courseoverGround;
		char unitCourseMeasurement;
		double speedoverGround;
		char speedUnits;
	};

	// Create Instances of the structs so that they can
	// be updated
	GPGLL GPS_GPGLL;
	WIMWV WIND_WIMWV;
	GPVTG SPEED_GPVTG;

	// Create an instance of the Hardware Serial
	// to be used within the class
	HardwareSerial* senSerial;
	HardwareSerial* debugPort;

	int grabChar(char input);

	int validateNMEA(char* input);
	int validateInternalNMEA();
	int splitNMEA(char* input);
	int splitInternalNMEA();
	void resetInternalNMEA();

	int processInternalNMEA();

	// Functions with ParseToStruct
	int parseInternalNMEA();
	int parseInternalNMEA(char* input);
	int updateGPS_GPGLL();
	int updateWIND_WIMWV();
	int updateSPEED_GPVTG();

public:
	WindSense();
	//Functions with AIRMARSpecific
	int debug(HardwareSerial &debugPortIn);
	int debugDump(HardwareSerial &debugPortIn);
	int betterDebug(HardwareSerial &debugPortIn);

	int pollAllValues();
	int pollValue(char nmea);
	int attach(HardwareSerial& sensorPort);

	int stupidDebug();

};

#endif
