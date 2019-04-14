

void setup() {
 Serial.begin(115200);
 //initializeScore();
 initializeScreen();
 initializeStates();
}

void loop() {
 //scoreScreen.refreshDisplay();
 runStateMachine();
}
