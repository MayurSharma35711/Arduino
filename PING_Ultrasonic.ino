int pwmA = 3;
int pwmB = 11;
int dirA = 12;
int dirB = 13;
int pin1=6;

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A3, INPUT);
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
  
  if(getDistance(pin1)>15)
  {
    linetrace();
  }
  else
  {
    analogWrite(pwmB,0);
    analogWrite(pwmA,0);
    /*analogWrite(pwmB,150);
    digitalWrite(dirA, HIGH);//backwards   
    analogWrite(pwmA,150);
    delay(1000);
    digitalWrite(dirA, LOW);*/
  }
}
