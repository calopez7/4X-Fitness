#include "StateMachine.h"

StateMachine stateMachine = StateMachine();

int gameTime = 120;

State* S0 = stateMachine.addState(&welcomeState); 
State* S1 = stateMachine.addState(&selectGameState);
State* S2 = stateMachine.addState(&basicGameState);
State* S3 = stateMachine.addState(&gameOverState);

bool S0NotExecuted = true;
bool S1NotExecuted = true;
bool S3NotExecuted = true;

void initializeStates() {
  S0->addTransition(&welcomeToSelectGameTransition,S1);
  S1->addTransition(&selectGameToBasicGameTransition,S2);
  S2->addTransition(&gameToEndGameTransition,S3);
  S3->addTransition(&gameOverToWelcomeTransition,S0);
}

bool pushed = false;

void runStateMachine() {
  stateMachine.run();
}

void welcomeState() {

  if (S0NotExecuted) {
    Serial.println("Welcome state");
    S0NotExecuted = false;
    printWelcomeScreen(); 
  }
  blinkLed(LED_CENTER_UP_PIN,1000);
}

bool welcomeToSelectGameTransition() {

  if (checkButtonState(BUTTON_CENTER_UP_PIN)) {
    changeButtonState(BUTTON_CENTER_UP_PIN,false);
    turnOffLed(LED_CENTER_UP_PIN);
    S0NotExecuted = true;
    return true;
  }
  return false;
}


void selectGameState() {

  if (S1NotExecuted) {
    Serial.println("Select game state");
    S1NotExecuted = false;
    printGameSelect("BASICO");
    turnOnLed(BUTTON_P2_A);
    turnOnLed(BUTTON_P2_B);
  }
  blinkLed(LED_CENTER_UP_PIN,1000);
}

bool selectGameToBasicGameTransition() {
  
  if (checkButtonState(BUTTON_CENTER_UP_PIN)) {
    changeButtonState(BUTTON_CENTER_UP_PIN,false);
    turnOffLed(LED_CENTER_UP_PIN);
    S1NotExecuted = true;
    return true;
  }
  return false;
}


void basicGameState() {
  Serial.println("Basic game state");
}

bool gameToEndGameTransition() {
  //printGameTimeScreen(&gameTime);
  delay(5000);
  return true;
}


void gameOverState() {
  
  if (S3NotExecuted) {
    Serial.println("Game over state");
    S3NotExecuted = false;
    printGameOver();
  }
  blinkLed(LED_CENTER_UP_PIN,500);
}

bool gameOverToWelcomeTransition() {
  if (checkButtonState(BUTTON_CENTER_UP_PIN)) {
    changeButtonState(BUTTON_CENTER_UP_PIN,false);
    S3NotExecuted = true;
    return true;
  }
  return false;
}
