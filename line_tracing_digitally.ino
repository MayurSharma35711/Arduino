int pwmA = 3;//right motor
int pwmB = 11;//left motor
int pin = 4;
int dirA = 12;
int dirB = 13;

void linetrace()
{
  digitalWrite(dirA, HIGH);
    }
  digitalWrite(dirB, HIGH);
  if(digitalRead(pin) == HIGH)
  {
    analogWrite(pwmA, 100);
    analogWrite(pwmB, 25);
  }
  else
  {
    analogWrite(pwmB, 100);
    analogWrite(pwmA, 25);
  }
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
linetrace();
}
