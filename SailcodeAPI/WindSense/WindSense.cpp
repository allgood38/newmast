<<<<<<< HEAD
#include "WindSense.h"

WindSense::WindSense() {
    partCount = 0;        //!< index for partSentence
    stringArrayIdx = 0;   //!< index for the array of strings
}

WindSense::WindSense(HardwareSerial &inSerial) {
	// Here, we initialize the wind sensor
	senSerial = &inSerial;
	//senSerial->begin(4800);
	delay(100);
	senSerial->println("$PAMTC,EN,RMC,0,10");
	delay(100);
}

/** Adds a character to the partial sentence string.
 * As long as the string has already started being built, or if a new $
 * character has been found. There a number of cases in which this can
 * fail and need to be handled.
 *
 * In the event of a string which begins to get created becomes much too
 * large, the function resets the partially completed string index and
 * returns a zero.
 *
 * @note Requires the external variables, partSentence and partCount
 * @return Whether or not a complete NMEA sentence has been stored, 0 if
 * it hasn't 1 if it has.
 */
int WindSense::grabChar(char input) {
	if (partCount >= sizeof(partSentence) - 1) {
		partCount = 0;
		partSentence[0] = '\0';
		return 0;
	} else if (partCount > 0 || input == '$') {
        partSentence[partCount] = input;
        partCount++;
    }

    if (partCount > 3 && partSentence[partCount-3] == '*') {
        partSentence[partCount] = '\0';
        return 1;
    }
    return 0;
}

/** Returns true if the checksum matches at the end.
 *
 * Note this function assumes that $ will always be the first character,
 * and that the entire NMEA sentence is untouched and isolated. It also
 * requires that partcount not be reset, since it uses it to determine
 * the end of the sentence
 *
 * @note Requires the external variables, partSentence and partCount
 * @param [in] input The complete and isolated NMEA sentence as a
 * @character array
 * @return The checksum is valid, 1 is True, 0 is False.
 */
int WindSense::validateNMEA(char* input) {
    int calculatedChecksum = 0;
    char rawGivenChecksum[2];
    int givenChecksum = 0;

    // XOR every element between [1] and *
    for (int i = 1; partSentence[i] != '*'; i++) {
        calculatedChecksum ^= partSentence[i];
    }

    // Convert the last two characters into a hexadecimal number
    rawGivenChecksum[0] = partSentence[partCount-2];
    rawGivenChecksum[1] = partSentence[partCount-1];

    char* parserChar;
    givenChecksum = (int)strtol(rawGivenChecksum, &parserChar, 16);

    // Another possible method
    //sscanf(rawGivenChecksum, "%x", &givenChecksum);

    partCount = 0;
    return (givenChecksum == calculatedChecksum);
}

int WindSense::validateInternalNMEA() {
    return validateNMEA(partSentence);
}

/** Returns an array of strings (char arrays) containing parsed values.
 *
 * This function relies on three different strings. Each string is just an
 * array of characters, so each string needs an index variables to keep
 * track of our progress within the string.
 *
 * The first string is simply the valid input sentence. The stringArray
 * is to store all the values from the input string. The newValue string
 * is a temporary buffer to hold on to a new value before it is stored in
 * the string array.
 *
 * The loop will place each input character into the new value string until
 * a comma or asterisk is encountered. Then it stores it to the array of
 * strings, resets the newValue and increments the index for stringArray.
 *
 * If there is a situation where there are two commas, indicating a null
 * value from the NMEA sentence, a null character will be stored in the
 * string array, rather than just skipping over it.
 */
int WindSense::splitNMEA(char* input) {
    int inputIdx = 1;

    char newValue[15];
    int newValueIdx = 0;

    // For an explanation of the conditions of this loop, see the pdf
    // documentation.
    while(inputIdx <= 1 || input[inputIdx - 1] != '*') {

        if (input[inputIdx] == ',' || input[inputIdx] == '*') {
            for (int i = 0; i < newValueIdx; i++) {
                stringArray[stringArrayIdx][i] = newValue[i];
            }

            stringArray[stringArrayIdx++][newValueIdx] = '\0';
            newValueIdx=0;

            // No comma, then store the value in the newValue array
        } else {
            newValue[newValueIdx++] = input[inputIdx];
            newValue[newValueIdx] = '\0';
        }

        // Move to the next character in the input string
        inputIdx++;
    }

    return 1;
}

int WindSense::splitInternalNMEA() {
    return splitNMEA(partSentence);
}

void WindSense::resetInternalNMEA() {
    stringArrayIdx = 0;
    partCount = 0;
}
=======
#include "WindSense.h"

WindSense::WindSense() {
    partCount = 0;        //!< index for partSentence
    stringArrayIdx = 0;   //!< index for the array of strings
}

WindSense::WindSense(HardwareSerial &inSerial) {
	// Here, we initialize the wind sensor
	senSerial = &inSerial;
	//senSerial->begin(4800);
	delay(100);
	senSerial->println("$PAMTC,EN,RMC,0,10");
	delay(100);
}

/** Adds a character to the partial sentence string.
 * As long as the string has already started being built, or if a new $
 * character has been found. There a number of cases in which this can
 * fail and need to be handled.
 *
 * @note Requires the external variables, partSentence and partCount
 * @return Whether or not a complete NMEA sentence has been stored, 0 if
 * it hasn't 1 if it has.
 */
int WindSense::grabChar(char input) {
    if (partCount > 0 || input == '$') {
        partSentence[partCount] = input;
        partCount++;
    }

    if (partCount > 3 && partSentence[partCount-3] == '*') {
        partSentence[partCount] = '\0';
        return 1;
    }
    return 0;
}

/** Returns true if the checksum matches at the end.
 *
 * Note this function assumes that $ will always be the first character,
 * and that the entire NMEA sentence is untouched and isolated. It also
 * requires that partcount not be reset, since it uses it to determine
 * the end of the sentence
 *
 * @note Requires the external variables, partSentence and partCount
 * @param [in] input The complete and isolated NMEA sentence as a
 * @character array
 * @return The checksum is valid, 1 is True, 0 is False.
 */
int WindSense::validateNMEA(char* input) {
    int calculatedChecksum = 0;
    char rawGivenChecksum[2];
    int givenChecksum = 0;

    // XOR every element between [1] and *
    for (int i = 1; partSentence[i] != '*'; i++) {
        calculatedChecksum ^= partSentence[i];
    }

    // Convert the last two characters into a hexadecimal number
    rawGivenChecksum[0] = partSentence[partCount-2];
    rawGivenChecksum[1] = partSentence[partCount-1];

    char* parserChar;
    givenChecksum = (int)strtol(rawGivenChecksum, &parserChar, 16);

    // Another possible method
    //sscanf(rawGivenChecksum, "%x", &givenChecksum);

    partCount = 0;
    return (givenChecksum == calculatedChecksum);
}

int WindSense::validateInternalNMEA() {
    return validateNMEA(partSentence);
}

/** Returns an array of strings (char arrays) containing parsed values.
 *
 * This function relies on three different strings. Each string is just an
 * array of characters, so each string needs an index variables to keep
 * track of our progress within the string.
 *
 * The first string is simply the valid input sentence. The stringArray
 * is to store all the values from the input string. The newValue string
 * is a temporary buffer to hold on to a new value before it is stored in
 * the string array.
 *
 * The loop will place each input character into the new value string until
 * a comma or asterisk is encountered. Then it stores it to the array of
 * strings, resets the newValue and increments the index for stringArray.
 *
 * If there is a situation where there are two commas, indicating a null
 * value from the NMEA sentence, a null character will be stored in the
 * string array, rather than just skipping over it.
 */
int WindSense::splitNMEA(char* input) {
    int inputIdx = 1;

    char newValue[15];
    int newValueIdx = 0;

    // For an explanation of the conditions of this loop, see the pdf
    // documentation.
    while(inputIdx <= 1 || input[inputIdx - 1] != '*') {

        if (input[inputIdx] == ',' || input[inputIdx] == '*') {
            for (int i = 0; i < newValueIdx; i++) {
                stringArray[stringArrayIdx][i] = newValue[i];
            }

            stringArray[stringArrayIdx++][newValueIdx] = '\0';
            newValueIdx=0;

            // No comma, then store the value in the newValue array
        } else {
            newValue[newValueIdx++] = input[inputIdx];
            newValue[newValueIdx] = '\0';
        }

        // Move to the next character in the input string
        inputIdx++;
    }

    return 1;
}

int WindSense::splitInternalNMEA() {
    return splitNMEA(partSentence);
}

void WindSense::resetInternalNMEA() {
    stringArrayIdx = 0;
    partCount = 0;
}
>>>>>>> 88a386f26258b2a9c5b70d6068c0fe89070e8088
