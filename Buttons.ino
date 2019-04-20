
#include "Button2.h";

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

#define BUTTON_OFFSET 12

boolean buttonState[15];

Button2 buttonCenterUp = Button2(BUTTON_CENTER_UP_PIN);
Button2 buttonCenterDown = Button2(BUTTON_CENTER_DOWN_PIN);
Button2 buttonP1A = Button2(BUTTON_P1_A_PIN);
Button2 buttonP1B = Button2(BUTTON_P1_B_PIN);
Button2 buttonP1C = Button2(BUTTON_P1_C_PIN);
Button2 buttonP1D = Button2(BUTTON_P1_D_PIN);
Button2 buttonP1E = Button2(BUTTON_P1_E_PIN);
Button2 buttonP2A = Button2(BUTTON_P2_A_PIN);
Button2 buttonP2B = Button2(BUTTON_P2_B_PIN);
Button2 buttonP2C = Button2(BUTTON_P2_C_PIN);
Button2 buttonP2D = Button2(BUTTON_P2_D_PIN);
Button2 buttonP2E = Button2(BUTTON_P2_E_PIN);

void buttonPressedHandler(Button2& btn);

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

  buttonCenterUp.setPressedHandler(buttonPressedHandler);
  buttonCenterDown.setPressedHandler(buttonPressedHandler);
  buttonP1A.setPressedHandler(buttonPressedHandler);
  buttonP1B.setPressedHandler(buttonPressedHandler);
  buttonP1C.setPressedHandler(buttonPressedHandler);
  buttonP1D.setPressedHandler(buttonPressedHandler);
  buttonP1E.setPressedHandler(buttonPressedHandler);
  buttonP2A.setPressedHandler(buttonPressedHandler);
  buttonP2B.setPressedHandler(buttonPressedHandler);
  buttonP2C.setPressedHandler(buttonPressedHandler);
  buttonP2D.setPressedHandler(buttonPressedHandler);
  buttonP2E.setPressedHandler(buttonPressedHandler);
}

void loopButtons() {
  buttonCenterUp.loop();
  buttonCenterDown.loop();
  buttonP1A.loop();
  buttonP1B.loop();
  buttonP1C.loop();
  buttonP1D.loop();
  buttonP1E.loop();
  buttonP2A.loop();
  buttonP2B.loop();
  buttonP2C.loop();
  buttonP2D.loop();
  buttonP2E.loop();
}

void buttonPressedHandler(Button2& btn) {
  
  if (btn == buttonCenterUp) {
    changeButtonState(BUTTON_CENTER_UP_PIN,true);
  } else if (btn == buttonCenterDown) {
    changeButtonState(BUTTON_CENTER_DOWN_PIN,true);
  } else if (btn == buttonP1A) {
    changeButtonState(BUTTON_P1_A_PIN,true);
  } else if (btn == buttonP1B) {
    changeButtonState(BUTTON_P1_B_PIN,true);
  } else if (btn == buttonP1C) {
    changeButtonState(BUTTON_P1_C_PIN,true);
  } else if (btn == buttonP1D) {
    changeButtonState(BUTTON_P1_D_PIN,true);
  } else if (btn == buttonP1E) {
    changeButtonState(BUTTON_P1_E_PIN,true);
  } else if (btn == buttonP2A) {
    changeButtonState(BUTTON_P2_A_PIN,true);
  } else if (btn == buttonP2B) {
    changeButtonState(BUTTON_P2_B_PIN,true);
  } else if (btn == buttonP2C) {
    changeButtonState(BUTTON_P2_C_PIN,true);
  } else if (btn == buttonP2D) {
    changeButtonState(BUTTON_P2_D_PIN,true);
  } else if (btn == buttonP2E) {
    changeButtonState(BUTTON_P2_E_PIN,true);
  }
}

void changeButtonState(int button,bool state) {
  buttonState[button-BUTTON_OFFSET] = state;
}

bool checkButtonState(int button) {
  return buttonState[button-BUTTON_OFFSET];
}
