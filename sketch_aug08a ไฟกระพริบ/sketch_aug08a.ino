void setup() {
  // put your setup code here, to run once:
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D0,1);
  delay(5000);
  digitalWrite(D0,0);
  digitalWrite(D1,1);
  delay(2000);
  digitalWrite(D1,0);
  digitalWrite(D2,1);
  delay(4000);
  digitalWrite(D2,0);
}
