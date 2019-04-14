

void setup() {
 Serial.begin(115200);
 //initializeScore();
  initializeStates();
}

void loop() {
//scoreScreen.refreshDisplay();
 runStateMachine();
}
