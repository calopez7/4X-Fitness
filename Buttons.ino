
#include "Button2.h";

#define BUTTON_START_PIN  27
#define BUTTON_ARROW_UP_PIN  29
#define BUTTON_ARROW_DOWN_PIN  30
#define BUTTON_CENTER_UP_PIN  12
#define BUTTON_CENTER_DOWN_PIN  28
#define BUTTON_P1_A_PIN  22
#define BUTTON_P1_B_PIN  23
#define BUTTON_P1_C_PIN  24
#define BUTTON_P1_D_PIN  25
#define BUTTON_P1_E_PIN  26
#define BUTTON_P2_A_PIN  29
#define BUTTON_P2_B_PIN  30
#define BUTTON_P2_C_PIN  31
#define BUTTON_P2_D_PIN  32
#define BUTTON_P2_E_PIN  33

Button2 buttonStart = Button2(BUTTON_START_PIN);


void initializeButtons() {
  pinMode(12, INPUT_PULLUP);
/*  pinMode(BUTTON_CENTER_DOWN_PIN, INPUT);
  pinMode(BUTTON_P1_A_PIN, INPUT);
  pinMode(BUTTON_P1_B_PIN, INPUT);
  pinMode(BUTTON_P1_C_PIN, INPUT);
  pinMode(BUTTON_P1_D_PIN, INPUT);
  pinMode(BUTTON_P1_E_PIN, INPUT);
  pinMode(BUTTON_P2_A_PIN, INPUT);
  pinMode(BUTTON_P2_B_PIN, INPUT);
  pinMode(BUTTON_P2_C_PIN, INPUT);
  pinMode(BUTTON_P2_D_PIN, INPUT);
  pinMode(BUTTON_P2_E_PIN, INPUT);*/
}
