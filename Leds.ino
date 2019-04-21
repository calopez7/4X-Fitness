
#define LED_CENTER_UP_PIN  11
#define LED_CENTER_DOWN_PIN  35
#define LED_P1_A_PIN  36
#define LED_P1_B_PIN  37
#define LED_P1_C_PIN  38
#define LED_P1_D_PIN  39
#define LED_P1_E_PIN  40
#define LED_P2_A_PIN  41
#define LED_P2_B_PIN  42
#define LED_P2_C_PIN  43
#define LED_P2_D_PIN  44
#define LED_P2_E_PIN  45

unsigned long previousMillisLed = 0;
int previousBlinkState = LOW;

void initializeLeds() {
  pinMode(LED_CENTER_UP_PIN,OUTPUT);
  pinMode(LED_CENTER_DOWN_PIN,OUTPUT);
  pinMode(LED_P1_A_PIN,OUTPUT);
  pinMode(LED_P1_B_PIN,OUTPUT);
  pinMode(LED_P1_C_PIN,OUTPUT);
  pinMode(LED_P1_D_PIN,OUTPUT);
  pinMode(LED_P1_E_PIN,OUTPUT);
  pinMode(LED_P2_A_PIN,OUTPUT);
  pinMode(LED_P2_B_PIN,OUTPUT);
  pinMode(LED_P2_C_PIN,OUTPUT);
  pinMode(LED_P2_D_PIN,OUTPUT);
  pinMode(LED_P2_E_PIN,OUTPUT);
}

void blinkLed(int pin, int time) {
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisLed >= time) {
    previousMillisLed = currentMillis;
    if (previousBlinkState == LOW) {
      digitalWrite(pin,HIGH);   
      previousBlinkState = HIGH;
    } else {
      digitalWrite(pin,LOW); 
      previousBlinkState = LOW;
    }
  }
}

void turnOnLed(int pin) {
  digitalWrite(pin,HIGH);
}

void turnOffLed(int pin) {
  digitalWrite(pin,LOW);
}
