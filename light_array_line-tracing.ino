int l1=4;//right most
int l2=A2;//right analog
int l3=A3;
int l4=7;//HIGH is white
int threshold2 = 640;
int threshold3=440;
int pwmA = 3;//right motor
int pwmB = 11;//left motor
int pin = 4;
int dirA = 12;
int dirB = 13;//B is left motor

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void lineTrace()
{
  digitalWrite(dirA,HIGH);
  digitalWrite(dirB,HIGH);
  if(analogRead(l2)<=threshold2 && analogRead(l3)<=threshold3)
  {
    if(digitalRead(l1)==digitalRead(l4))
    {
      analogWrite(pwmA,100);
      analogWrite(pwmB,100);
    }
    else if(digitalRead(l1)<digitalRead(l4))
    {
      analogWrite(pwmA,15);
      analogWrite(pwmB,100);
    }
    else
    {
      analogWrite(pwmA,100);
      analogWrite(pwmB,15);
    }
  }
  else if(analogRead(l2)<=threshold2 && analogRead(l3)>=threshold3)
  {
      analogWrite(pwmA,15);
      analogWrite(pwmB,100);
  }
  else if(analogRead(l2)>=threshold2 && analogRead(l3)<=threshold3)
  {
      analogWrite(pwmA,100);
      analogWrite(pwmB,15);
  }
  else
  {
    if(digitalRead(l1)<digitalRead(l4))
    {
      analogWrite(pwmA,15);
      analogWrite(pwmB,100);
    }
    else if(digitalRead(l1)>digitalRead(l4))
    {
      analogWrite(pwmA,100);
      analogWrite(pwmB,15);
    }
  }
}
void loop() {
  Serial.println(analogRead(l3));
  // put your main code here, to run repeatedly:
  lineTrace();
}
