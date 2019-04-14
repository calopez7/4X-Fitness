#include "SevSeg.h"

SevSeg scoreScreen;//object to manage the seven segment screen
int score;//holds the score 

byte numDigits = 4;
byte digitPins[4] {8, 11, 12, 2}; // From com1 - com4 TODO cambiar pines
byte segmentPins[8] {9, 13, 4, 6, 7, 10, 3,5}; // From a - g (abc...g) TODO cambiar pines
bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
byte hardwareConfig = COMMON_CATHODE; // See README.md for options
bool updateWithDelays = false; // Default 'false' is Recommended
bool leadingZeros = true; // Use 'true' if you'd like to keep the leading zeros

void initializeScore() {
  score = 0;
  scoreScreen.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros);
  scoreScreen.setNumber(score,0);
}

void refreshScore() {
  scoreScreen.refreshDisplay();
}

void addScore(int points) {
  score += points;
  scoreScreen.setNumber(score,0);
}

void resetScore() {
  score = 0;
  scoreScreen.setNumber(score,0);
}
