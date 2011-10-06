#include <stdio.h>


char nm[] = {"askdjfhalkjha$GPGSV,2,1,08,01,40,083,46,02,17,308,41,12,07,344,39,14,22,228,45*75asdf"};

int i;
int partCount = 0;
char partSentence[100];


// Counters for dummy read
int dummyIdx = 0;

// Prototypes
char dummyRead();
int grabChar(char input);
int validateNMEA(char* input);
char* parseNMEA(char* input);

int main(int argc, const char *argv[])
{
	// Getting the input and running the checksum
	int worked = 0;
	while (!grabChar(dummyRead())) {
	}

	worked = validateNMEA(partSentence);
	printf("The checksum is... %d\n", worked);

	// Now we will test the parsing requirements 
	parseNMEA(partSentence);

	return 0;
}

char dummyRead() {
	dummyIdx = (dummyIdx + 1) % sizeof(nm);
	return nm[dummyIdx];
}

/** Adds a character to the partial sentence string.
 * As long as the string has already started being built, or if a new $ character has
 * been found. There a number of cases in which this can fail and need to be handled.
 *
 * @note  Requires the external variables, partSentence and partCount
 * @return Whether or not a complete NMEA sentence has been stored, 0 if it hasn't 
 * 1 if it has.
 */
int grabChar(char input) {
	if (partCount > 0 || input == '$') {
		partSentence[partCount] = input;
		partCount++;
	}

	if (partCount > 3 && partSentence[partCount-3] == '*') {
		return 1;
	}
	return 0;
}

/** Returns true if the checksum matches at the end.
 *
 * Note this function assumes that $ will always be the first character, and that the
 * entire NMEA sentence is untouched and isolated.
 *
 * @note Requires the external variables, partSentence and partCount
 * @param [in] input The complete and isolated NMEA sentence as a character array
 * @return The checksum is valid, 1 is True, 0 is False.
 */
int validateNMEA(char* input) {
	int calculatedChecksum = 0;
	char rawGivenChecksum[2];
	int givenChecksum = 0;
	
	// XOR every element between [1] and *
	for (i = 1; partSentence[i] != '*'; i++) {
		calculatedChecksum ^= partSentence[i];
	}

	// Convert the last two characters into a hexadecimal number
	rawGivenChecksum[0] = partSentence[partCount-2];
	rawGivenChecksum[1] = partSentence[partCount-1];

	char parserChar;
	givenChecksum = (int)strtol(rawGivenChecksum, &parserChar, 16);

	// Another possible method
	// sscanf(rawGivenChecksum, "%x", &givenChecksum);

	return (givenChecksum == calculatedChecksum);
}

/** Returns an array of strings (char arrays) containing parsed values.
 *
 * Uses a two dimensional array of fixed size in order to store the values
 *
 *
 */
char* parseNMEA(char* input) {
	int inputIdx = 1;

	char stringArray[40][15];
	int stringArrayIdx = 0;

	char newValue[15];
	int newValueIdx = 0;

	while(inputIdx <= 1 || input[inputIdx - 1] != '*') {
		printf("Input buffer progress... %c\n", input[inputIdx]);

		if (input[inputIdx] == ',' || input[inputIdx] == '*') {

			printf("Adding %s to string array\n", newValue);

			for (int i = 0; i < newValueIdx; i++) {
				stringArray[stringArrayIdx][i] = newValue[i];
			}
			stringArray[stringArrayIdx++][newValueIdx] = '\0';
			newValueIdx=0;
			
		// No comma, then store the value in the newValue array
		} else {
			newValue[newValueIdx++] = input[inputIdx];
			newValue[newValueIdx] = '\0';
			printf("newValue Buffer progress... %s\n", newValue);
		}

		inputIdx++;
	}

	for (int i = 0; i < stringArrayIdx; i++) {
		printf("%s\n", stringArray[i]);
	}
	return stringArray;
}
