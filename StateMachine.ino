#include "StateMachine.h"

StateMachine stateMachine = StateMachine();

int gameTime = 120;

State* S0 = stateMachine.addState(&welcomeState); 
State* S1 = stateMachine.addState(&selectGameState);
State* S2 = stateMachine.addState(&basicGameState);
State* S3 = stateMachine.addState(&gameOverState);

bool S0NotExecuted = true;
bool S1NotExecuted = true;

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
}

bool welcomeToSelectGameTransition() {

  if (checkButtonState(BUTTON_CENTER_UP_PIN)) {
    changeButtonState(BUTTON_CENTER_UP_PIN,false);
    return true;
  }
  return false;
}


void selectGameState() {

  if (S1NotExecuted) {
    Serial.println("Select game state");
    S1NotExecuted = false;
    printGameSelect("BASICO");
  }
}

bool selectGameToBasicGameTransition() {
  
  if (checkButtonState(BUTTON_CENTER_UP_PIN)) {
    changeButtonState(BUTTON_CENTER_UP_PIN,false);
    return true;
  }
  return false;
}


void basicGameState() {
  Serial.println("Basic game state");
}

bool gameToEndGameTransition() {
  printGameTimeScreen(&gameTime);
  return false;
}


void gameOverState() {
  Serial.println("Game over state");
  
}

bool gameOverToWelcomeTransition() {
  delay(5000);
  return true;
}
