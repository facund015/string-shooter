#include <Arduino.h>

#define POTENTIOEMTER A0
#define MOTORS D0
#define BUTTON D1

bool ON = false;
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

  if (ON){
    analogWrite(MOTORS, potency*5);
  } else {
    analogWrite(MOTORS, 0);
  }

  pButtonState = HIGH;
  delay(500);
}