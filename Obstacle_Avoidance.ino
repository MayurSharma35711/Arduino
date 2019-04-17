#include <Servo.h>

Servo jim;
int pwmA = 3;
int pwmB = 11;
int dirA = 12;
int dirB = 13;
int pin1=6;
int time1 = 900;

int getDistance(int pin)
{
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
  delayMicroseconds(2);
  digitalWrite(pin,HIGH);
  delayMicroseconds(5);
  digitalWrite(pin,LOW);
  pinMode(pin,INPUT);
  int timing = pulseIn(pin,HIGH);
  int distance = timing/29/2;
  delay(100);
  return distance;
}
void turn(int timer, int dir)// dir 0 = right
{
  if(dir==0)
  {
  digitalWrite(dirA,LOW);
  digitalWrite(dirB,HIGH);//LEFT TURN
  }
  else
  {
  digitalWrite(dirA,HIGH);
  digitalWrite(dirB,LOW);//RIGHT TURN
  }
  analogWrite(pwmA, 100);
  analogWrite(pwmB,100);
  delay(timer);
  analogWrite(pwmA, 0);
  analogWrite(pwmB, 0);
  delay(1500);
  digitalWrite(dirA,HIGH);
  digitalWrite(dirB,HIGH);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A3, INPUT);
  jim.attach(10);
}
void linetrace()
{
  Serial.println(analogRead(A3));
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  if(digitalRead(4)==HIGH)
  {
    analogWrite(pwmA,100);
    analogWrite(pwmB, 25);
  }
  else
  {
    analogWrite(pwmB,100);
    analogWrite(pwmA, 25);
  }
}
void loop() {
  // put your main code here, to run :
  jim.write(90);
  if(getDistance(pin1)>15)
  {
    linetrace();
  }
  else
  {
    analogWrite(pwmA, 0);
    analogWrite(pwmB,0);
    jim.write(0);
    delay(2000);
    int d1 = getDistance(pin1);
    jim.write(180);
    delay(2000);
    int d2 = getDistance(pin1);
    if(d1>d2)
    {
      turn(time1,0);
      analogWrite(pwmA,100);
      analogWrite(pwmB,100);
      delay(2000);
      turn(time1,1);
      analogWrite(pwmA,100);
      analogWrite(pwmB,100);
      delay(2500);
      if(digitalRead(4)==HIGH)
      {
        analogWrite(pwmA,100);
        analogWrite(pwmB,100);
      }
    else 
    {
      turn(time1,1);
      analogWrite(pwmA,100);
      analogWrite(pwmB,100);
      delay(2000);
      turn(time1,0);
      analogWrite(pwmA,100);
      analogWrite(pwmB,100);
      delay(2500);
      turn(time1,0);
      analogWrite(pwmA,100);
      analogWrite(pwmB,100);
      delay(2000);
      if(digitalRead(4)==HIGH)
      {
      analogWrite(pwmA,100);
      analogWrite(pwmB,100);
      }
    }
  }
}
