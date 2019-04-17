#include <Servo.h>

Servo logic;

void setup() {
  // put your setup code here, to run once:
  logic.attach(10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  logic.write(0);
  delay(2000);
  logic.write(90);
  delay(2000);
  logic.write(180);
  delay(2000);
}
