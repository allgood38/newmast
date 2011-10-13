/** Class to control the Wind Sensor in an encapsulated way.
 *
 * @par
 * Once this class is complete, a unit test function will be written to make sure
 * that it always has valid input and outputs. In an effort to eliminate the use
 * of global variables, the only way to get output out of this should be through
 * functions, all variables should remain private.
 *
 * @par 2011-10-02 Sun 05:09 pm
 * Will try to use TinyGPS to get values from the sensor. The library actually
 * suggests the use of a software serial library, but that doesn't have a buffer
 * and forces the Arduino to sit and listen for the data.
 *
 */

#ifndef WindSense_H
#define WindSense_H

#include <WProgram.h>

class WindSense {
	private:
	int partCount = 0; //!< Used in the grabChar function
	char partSentence[100]; //!< Used in the grabChar function

	public:
	WindSense();
	
	~WindSense();

	/** Check the boats current co-ordinates..
	 *
	 * Simply takes the value which has been updated during the class. Also, it
	 * might be worth getting it to keep track of when it was last updated so
	 * that it can update the memory values if necessary.
	 *
	 * @return double The current co-ordinates
	 */
	double getGPSLatitude();
	double getGPSLongitude();

	/** Updates the internal variables of this class with data.
	 *
	 * Calls functions from the TinyGPS instance in order to read data from the
	 * serial buffer and extract data from the NMEA strings. The simplest way to
	 * do this is to just keep on feeding the TinyGPS until it runs out of data
	 * to parse, although.
	 *
	 * @note We need to find a way to get it to stop before it hits the end of the
	 * buffer, since the buffer may never empty depending on the frequency of the
	 * wind sensor
	 *
	 * @return int Zero if successful, greater than 0 otherwise
	 */
	int updateGPSData();

	/** Dumps WindSesnor Variables to the console for debugging purposes. */
	int dumpToScreen();

	/** Validates the checksum on the sentence.
	 *
	 * Performs the checksum using a case-switch and a loop. 
	 *
	 * @param NMEA [in] The complete NMEA String, no parsing required yet though
	 * it does need to be a single sentence
	 *
	 * @return 0 if successful, greater than 0 if there are errors or eny kind of
	 * complication which will need to be handled. 
	 */
	int validateSentence(char* NMEA);
};

#endif
