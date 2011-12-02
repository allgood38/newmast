/** Take notes anywhere in the program and output to your
 * choice
 *  Debugging.h
 *
 *  Created on: Dec 1, 2011
 *      Author: QMAST
 *
 *  The goal is to be able to write sentences to this class
 *  from anywhere within the main code. Meanwhile this class
 *  will control what is done with that sentence.
 *
 *  It should be able to send the data to either the serial
 *  port or the SD card without needing the change any part
 *  of the main code except for the constructor when it is
 *  initialized.
 */

#ifndef DEBUGGING_H_
#define DEBUGGING_H_


class Debugging {
public:
	Debugging();

	/** The main point of this class
	 *
	 * Take a single string and send it to the desired output
	 * as specified by the constructor.
	 *
	 * @param [in] notable string
	 * @return [out] 0 if successful
	 */
	int takeNote(char* input);
};

#endif /* DEBUGGING_H_ */
