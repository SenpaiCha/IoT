void setup() {                        
  Serial.begin(9600);
  pinMode(D1,OUTPUT); // ขา trig
  pinMode(D7,OUTPUT); // ขา + หลอดไฟ
  pinMode(D5,INPUT); // ขา echo  
  pinMode(D8,OUTPUT);       
}

void loop() {
  digitalWrite(D1,HIGH);
  delayMicroseconds(10);
  digitalWrite(D1,LOW);

  int pulseWidth=pulseIn(D5,HIGH);
  Serial.print("Pulse Width: ");
  Serial.println(pulseWidth);
  long distance=pulseWidth/29/2;
  Serial.print("distance: ");
  Serial.println(distance);
  if (distance<15){
    digitalWrite(D7,LOW);
    digitalWrite(D8,HIGH);
    Serial.println("LED OFF");
    }
  else{
    digitalWrite(D7,HIGH);
    digitalWrite(D8,LOW);
    Serial.println("LED ON");
    }
  delay(500);
}
