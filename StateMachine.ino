#include "StateMachine.h"

StateMachine stateMachine = StateMachine();

State* S0 = stateMachine.addState(&welcomeState); 
State* S1 = stateMachine.addState(&selectGameState);
State* S2 = stateMachine.addState(&basicGameState);
State* S3 = stateMachine.addState(&gameOverState);

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
  Serial.println("Welcome state");
 
}

bool welcomeToSelectGameTransition() {
  delay(5000);
  return true;
}


void selectGameState() {
  Serial.println("Select game state");
  
}

bool selectGameToBasicGameTransition() {
  delay(5000);
  return true;
}


void basicGameState() {
  Serial.println("Basic game state");
  
}

bool gameToEndGameTransition() {
  delay(5000);
  return true;
}


void gameOverState() {
  Serial.println("Game over state");
  
}

bool gameOverToWelcomeTransition() {
  delay(5000);
  return true;
}
