#include <WProgram.h>
#include <arduino.h>

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

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
  Serial.begin(19200);
  //Serial3.begin(4800);
}

void loop() {

  if (Serial.available()) {
	  Serial.print(Serial.read(),BYTE);
  }
}
