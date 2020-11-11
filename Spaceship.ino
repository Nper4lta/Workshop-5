#include <Servo.h> 
int switchState = 0;
int buzzer = 7; 
Servo myservo;
int pos = 0; 

void setup()
{
  pinMode(buzzer, OUTPUT);
  myservo.attach(6);
  pinMode(5, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (10, INPUT);
}

void loop()
{
  switchState = digitalRead(10);

  if (switchState == HIGH) {
    tone(buzzer,1000);
    myservo.write(90);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    
    delay(1000);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(1000);
      

  }
  else {
    myservo.write(0);
    noTone(buzzer);
    digitalWrite(3, HIGH);
    delay(250);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(250);
    digitalWrite(5, HIGH);
    digitalWrite(4,LOW);
  }
}
