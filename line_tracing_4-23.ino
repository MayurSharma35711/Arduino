  int dirB = 13;
  int dirA=12;//LOW is backward
  int pwmA = 3;
  int pwmB = 11;
void setup() {
  pinMode(A3, INPUT);
  Serial.begin(9600);

}

void loop() {
  Serial.println(analogRead(A3));
  if(analogRead(A3)<400)
  {
    analogWrite(pwmA, 150);
    analogWrite(pwmB, 30);
  }
  else
  {
    analogWrite(pwmA, 30);
    analogWrite(pwmB, 150);
  }
}
