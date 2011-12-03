Windsense airman;
Debugging panic;

char debugString[50] = {'\0'};

void setup() {
    Serial.begin(19200);
    airman.attach(Serial);

    panic.attach(Serial);
    panic.println("Ready for action");
}

void loop() {
    airman.pollAllValues();
    itoa(airman.stupidDebug(),debugString,10);
    panic.println(debugString);
}
