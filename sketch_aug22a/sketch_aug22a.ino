int val = 0;
void setup() {
  pinMode(D1,INPUT);
  pinMode(D5,OUTPUT); 
  pinMode(D7,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(D1);          //อ่าค่าสัญญาณ digital ขา D1 ที่ต่อกับเซ็นเซอร์
  Serial.print("val = ");         //พิมพ์ข้อความส่งเข้าคอมพิวเตอร์ "Val = "
  Serial.println(val);            // พิมพ์ค่าของตัวแปร val
  if (val == 1){                  //ค่าเป็น 1 ตรวจสอบวัตถุ สั่งให้ไฟ LED ติด
    digitalWrite(D5,HIGH);        //สั่งให้ LED ติด
    tone(D7,600);
    Serial.println("Motion!");
    }
  else{
    digitalWrite(D5,LOW);         //สั่งให้ LED ดับ
    noTone(D7);  
    Serial.println("Not Motion!");
  }
  delay(5000);
}
