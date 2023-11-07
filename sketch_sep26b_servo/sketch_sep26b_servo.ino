#include <Servo.h>
Servo servo;
int val = 0;
int servoPin = 4;

void setup() {
  pinMode(D1, INPUT);
  pinMode(D2, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
  val = digitalRead(D1);
  Serial.print("val = ");
  Serial.println(val);
  if (val == 0){
    servo.write(0);
    digitalWrite(D5,1);
    digitalWrite(D6,0); 
    Serial.println("ตรวจจับได้");
  }
  else {
    servo.write(180); 
    digitalWrite(D5,0);
    digitalWrite(D6,1);
    Serial.println("ไม่มีอะไรบัง IR Senser");
  }
}
