#include <LiquidCrystal.h>

LiquidCrystal display (7, 8, 9, 10, 11, 12);

unsigned long previousMillis = 0;

byte customArrows[] = {
  B00100,
  B01110,
  B11111,
  B00000,
  B00000,
  B11111,
  B01110,
  B00100
};

void initializeScreen() {
  display.begin(16,2);
  display.createChar(0,customArrows);
}

void printWelcomeScreen() {
  display.clear();
  display.setCursor(3,0);
  display.print("4X FITNESS");
  display.setCursor(3,1);
  display.print("BIENVENIDO");

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 3000) {
    previousMillis = currentMillis;
    printStartScreen();  
  }

}

void printStartScreen() {
  display.clear();
  display.setCursor(3,0);
  display.print("4X FITNESS");
  display.setCursor(2,1);
  display.print("PULSA START!");
}

void printGameSelect(char * game) {
  display.clear();
  display.setCursor(0,0);
  display.print("SELECCIONA JUEGO");
  display.setCursor(0,1);
  display.print(game);
  display.setCursor(15,1);
  display.write(byte(0));
}

void printLetsPlayScreen() {
  display.clear();
  display.setCursor(4,0);
  display.print("A JUGAR!");
}

void printGameTimeScreen(int * gameTime) {

  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    display.clear();
    display.setCursor(5,0);
    display.print("TIEMPO");
    display.setCursor(6,1);
    char buffer[4];
    sprintf(buffer,"%03d", *gameTime);
    display.print(buffer);
    *gameTime--; 
  }
  
}

void printGameOver() {
  display.clear();
  display.setCursor(3,0);
  display.print("GAME OVER!");
}
