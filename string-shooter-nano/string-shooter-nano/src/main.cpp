#include <Arduino.h>

#define POTENTIOEMTER 8
#define MOTORS 11
#define BUTTON 12

bool ON = false;
bool prevON = false;
int potency = 0;
int buttonState;
int pButtonState = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(MOTORS, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  analogWrite(MOTORS, 0);
}

void loop() {
  potency = analogRead(POTENTIOEMTER);
  buttonState = digitalRead(BUTTON);

  if (buttonState == LOW && pButtonState == HIGH){
    if (ON) {
      ON = false;
    } else {
      ON = true;
    }
  }

  if (ON && !prevON){
    analogWrite(MOTORS, static_cast<float>(potency) * 1.953);
  } else if (!ON && prevON) {
    analogWrite(MOTORS, 0);
  }

  pButtonState = buttonState;
  prevON = ON;
  delay(300);

}