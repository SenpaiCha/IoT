int val = 0;
void setup() {
  pinMode(D5, OUTPUT);
  pinMode(D1,INPUT);
  Serial.drgin(9600);

}

void loop() {
  val = digitalWrite(D1);
  Serial.print("val = ");
  Serial.println(val);
  if (val == 0){
    digitalWrite(D5,1);
    Serial.println("ตรวจจับได้")
  }
  else {
    digitalWrite(D5,0);
    Serial.println("ไม่มีอะไรบัง IR Senser")
  }
  delay(100);
}
