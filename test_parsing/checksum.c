#include <stdio.h>

char convertASCIItoHex (const char ch);

// char nm[] = {"$GPGSV,2,1,08,01,40,083,46,02,17,308,41,12,07,344,39,14,22,228,45*75"};
char nm[] = {"GPGSV,2,1,08,01,40,083,46,02,17,308,41,12,07,344,39,14,22,228,45"};

int main(int argc, const char *argv[]) {
	printf("%x\n", convertASCIItoHex('0'));
	int checksum = 0;
	int i;

	printf("Beginning the checksum function...\n");
	for (i = 0; i < sizeof(nm); i++) {
		checksum ^= nm[i];
	}

	printf("The value calculated is, %x\n", checksum);

	printf("The value of the basic character 'A' is ...%x\n", 'A');

	return 0;
}

/** Converts ASCII Characters to Hex Values, but it sort of cheats.
 * Just uses the fact that an ascii number can be subtracted and added to
 * in order to get the hex value, look at the return equations.
 *
 * Given the way that C deals with characters, it should be possible to simply
 * feed the for loop actual characters, there is no need to have a function
 * to convert them to hex, when that is done automagically. 
 */
char convertASCIItoHex (char ch) {
	// if it's an ASCII number
    if(ch >= '0' && ch <= '9') {
		return (ch - '0') + 48;           // subtract ASCII 0 value to get the hex value
									 // if its a letter (assumed upper case)
    } else {
		return ((ch - 'A') + 65);    // subtract ASCII A value then add 10 to get the hex value
    }
}
