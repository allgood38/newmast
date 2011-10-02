/** @file The main file, currently for testing purposes.
 *
 * Later on this file might not be necessary, since all of the functions needed
 * will probably just be kept in their own libraries.
 */

#include "WindSense.h"



void setup() {
}

void loop() {
	my_values test;
	test = test_function(test);
}

my_values test_function(my_values diffName) {
	diffName.x = 4;
	diffName.y = 5;
}
