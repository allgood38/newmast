/** Class to control the Wind Sensor in an encapsulated way.
 *
 * @par
 * Once this class is complete, a unit test function will be written to make sure
 * that it always has valid input and outputs. In an effort to eliminate the use
 * of global variables, the only way to get output out of this should be through
 * functions, all variables should remain private.
 *
 */

#ifndef WindSense_H
#define WindSense_H

#include <WProgram.h>

class WindSense {
	private:
	public:
	WindSense();
	~WindSense();

	/** Check the boats current co-ordinates..
	 *
	 * Simply takes the value which has been updated during the class. Also, it
	 * might be worth getting it to keep track of when it was last updated so
	 * that it can update the memory values if necessary.
	 *
	 * @return int* The current co-ordinates
	 */
	int getGPSPosition();

};

// Attemping to write a global 
struct my_values {
	int x;
	int y;
};
#endif
