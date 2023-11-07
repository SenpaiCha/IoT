void setup() {
  pinMode(D1,OUTPUT);
  pinMode(D2,INPUT);
  pinMode(D7,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(D1,HIGH);
  delayMicroseconds(10);
  digitalWrite(D1,LOW);

  int pulseWidth=pulseIn(D2,HIGH);
  long distance=pulseWidth/29/2;
  Serial.print("ระยะห่าง = ");
  Serial.println(distance);
  if (distance<=20){
    digitalWrite(D7,LOW); // 0 degree
  }
  if (distance<=20 && distance>15){
    digitalWrite(D7,HIGH);
    tone(D7,600,100); 
  }
  if (distance<=15 && distance>5){
    digitalWrite(D7,HIGH); 
    tone(D7,600,1000);
  }
  if (distance<=5){
    digitalWrite(D7,HIGH); 
    tone(D7,600);
  }
  delay(1000);
}
