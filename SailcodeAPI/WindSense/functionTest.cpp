/*
 * functionTest.cpp
 *
 *  Created on: 2011-11-13
 *      Author: allgood38
 */
#include <stdio.h>
#include "WindSense.h"

char nm[] = {"askdjfhalkjha$GPGSV,2,1,08,01,40,083,46,02,17,308,41,12,07,344,39,14,22,228,45*75asdf"};
WindSense airman;

int dummyIdx = 0;

char dummyRead() {
    dummyIdx = (dummyIdx + 1) % sizeof(nm);
    return nm[dummyIdx];
}

int main(int argc, const char *argv[]) {
    while (!airman.grabChar(dummyRead())) {
    }
    printf("The contents of the string are\n%s\n", airman.partSentence);
    if (airman.validateNMEA(airman.partSentence)) {
        printf("Apparently String is valid\n");
    }
    airman.parseInternalNMEA();

    for (int i = 0; i < airman.stringArrayIdx; i++) {
        printf("The contents of the string array at %d is %s\n", i, airman.stringArray[i]);
    }

    return 0;
}

