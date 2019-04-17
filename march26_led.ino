int dirB = 13;
int dirA=12;
int breakA = 9;
int breakB=8;
int pwmA = 3;
int pwmB = 11;
int z=0;
int timeNum = 3000;

void setup() {
  pinMode(breakA, OUTPUT);
  pinMode(breakB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A0));
  delay(100);
  if(analogRead(A0) > 190)
  {
    digitalWrite(dirA, LOW);//backwards
    digitalWrite(dirB, HIGH);
    analogWrite(pwmA, 255);
    analogWrite(pwmB, 255);
    delay(450);
  }
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(pwmA, 127);
  analogWrite(pwmB, 127);
//  else
//  {
//    digitalWrite(dirA, HIGH);
//    digitalWrite(dirB, HIGH);
//    analogWrite(pwmA, 255);
//    analogWrite(pwmB, 255);
//    delay(1000);
//  }
}
