#include <Servo.h>

Servo Head;

// Pins
int Head_pin = 38;
int CH8 = 3;

// Limits
int Head_max = 175;
int Head_min = 85;

// Rest
int Head_rest = 135;

float currentAngle = Head_rest;

void setup() {
  pinMode(CH8, INPUT);

  Head.attach(Head_pin);
  Head.write(Head_rest);
}

void loop() {
  unsigned long ch8pulse = pulseIn(CH8, HIGH, 25000);

  if (ch8pulse > 900 && ch8pulse < 2100) {

    int target = map(ch8pulse, 1000, 2000, Head_min, Head_max);

    // Easing factor: 0.05 = slow, 0.1 = medium, 0.2 = fast
    currentAngle = currentAngle + (target - currentAngle) * 0.05;

    Head.write((int)currentAngle);

    delay(10);  // small delay for stability
  }
}


