#include <Servo.h>
Servo servo1;

void setup() {
  // put your setup code here, to run once:
  pinMode(D5,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,INPUT);
  servo1.attach(14); // signal wire D5
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D1,HIGH);
  delayMicroseconds(10);
  digitalWrite(D1,LOW);

  int pulseWidth=pulseIn(D2,HIGH);
  long distance=pulseWidth/29/2;
  Serial.print("ระยะห่าง = ");
  Serial.println(distance);
  if (distance<15){
    servo1.write(180); // 0 degree
  }
  else{
    servo1.write(0); // 0 degree
  }
  delay(1000);
}
