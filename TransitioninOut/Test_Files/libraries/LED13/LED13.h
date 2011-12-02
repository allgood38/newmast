/** This file will be used to test the Arduino class ability.
 *
 * Since the Arduino doesn't have a way to deal with classes like C++, this
 * file will attempt to create a library from a website, so that we can check
 * to see if this kind of thing will be useful for the actual project.
 */

#ifndef LED13_H
#define LED13_H

#include <WProgram.h> // This brings in the Arduino Standard Functions

/** Basic class to control a single pin.
 * Allows it to call some functions, which turn pin 13 on or off, and blink
 * at a specified time interval. Basically this is nothing special, but it
 * does pretty much copy the source website word-for-word.
 */
class LED13 {
public:
	int test_var;
	LED13();
	~LED13();
	void on();
	void off();
	void blink(int time);
};

#endif
