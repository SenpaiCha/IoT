void setup() {
  // put your setup code here, to run once:
  pinMode(D1,INPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,INPUT);
  pinMode(D4,OUTPUT);  
  pinMode(D5,INPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,INPUT);
  pinMode(D8,OUTPUT);                                   
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(D1)==0){
    digitalWrite(D2,1);
    Serial.println("LED NO");
  } 
  else{
    digitalWrite(D2,0);
    Serial.println("LED OFF");
  }
  if (digitalRead(D3)==0){
    digitalWrite(D4,1);
    Serial.println("LED NO");
  } 
  else{
    digitalWrite(D4,0);
    Serial.println("LED OFF");
  }
  if (digitalRead(D5)==0){
    digitalWrite(D6,1);
    Serial.println("LED NO");
  } 
  else{
    digitalWrite(D6,0);
    Serial.println("LED OFF");
  }
  if (digitalRead(D7)==0){
    digitalWrite(D8,1);
    Serial.println("LED NO");
  } 
  else{
    digitalWrite(D8,0);
    Serial.println("LED OFF");
  }
}
