#include <WProgram.h>
#include <arduino.h>
#include "Servo/Servo.h"

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
Servo motor;

// This is the main loop, shouldn't be changed for any reason
int main(void)
{
	init();

	setup();

	for (;;)
		loop();

	return 0;
}

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);     
  Serial.begin(9600);
  motor.attach(13);
  motor.write(90);
}

void loop() {
	if ( Serial.available() ) {
		Serial.println("I hear you say");

		while ( Serial.available() ) {
			Serial.print(Serial.read(),BYTE);
		}
	}
}
