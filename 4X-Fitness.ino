

void setup() {
 Serial.begin(115200);
 //initializeScore();
 initializeButtons();
// initializeScreen();
 initializeStates();
}

void loop() {
 //scoreScreen.refreshDisplay();
 runStateMachine();
 
}
