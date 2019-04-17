#include <Servo.h>

Servo logic;

void setup() {
  // put your setup code here, to run once:
  logic.attach(5);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  logic.write(93);
  Serial.println(logic.read());
  logic.write(0);
  Serial.println(logic.read());
}
