int MotorL = D1;
int MotorR = D2;
int MotorPWM = D3;

#include"DHT.h"

#define DHTPIN  D5                // GPI05 ขาที่ต่อกับขา data
#define DHTTYPE  DHT22            // e.g. DHT11, DHT21,DHT22
DHT dhtSS(DHTPIN, DHTTYPE);

float humid = 0;                  //ค่าความชื้น
float temp = 0;                   //ค่าอุณภูมิ


void setup() {
  pinMode(MotorL,OUTPUT);
  pinMode(MotorR,OUTPUT);
  pinMode(MotorPWM,OUTPUT); 
  Serial.begin(9600);
  dhtSS.begin();
  pinMode(D5, INPUT);
}
void loop() {
  //สั่งให้มอเตอร์หมุนขวา
  digitalWrite(MotorL,1);
  digitalWrite(MotorR,0);
  humid = dhtSS.readHumidity();
  temp = dhtSS.readTemperature();
  if (temp > 25){
    analogWrite(MotorPWM,1000);
    Serial.print("Temp = ");
    Serial.print(temp);
    Serial.println(" C ");
    Serial.print("Humid: ");
    Serial.print(humid);
    Serial.println(" %, ");
    Serial.print("--->");       
    Serial.println("Hot and Open Fan");
    }
  else{
    analogWrite(MotorPWM,0);
    Serial.print("Temp = ");
    Serial.print(temp);
    Serial.println(" C ");
    Serial.print("Humid: ");
    Serial.print(humid);
    Serial.println(" %, ");
    Serial.print("--->");      
    Serial.println("Cool stop Fan");
    }
    delay(1000);
}
 
