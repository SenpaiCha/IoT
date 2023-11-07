#include"DHT.h"

#define DHTPIN  D1                // GPI05 ขาที่ต่อกับขา data
#define DHTTYPE  DHT22            // e.g. DHT11, DHT21,DHT22
DHT dhtSS(DHTPIN, DHTTYPE);

float humid = 0;                  //ค่าความชื้น
float temp = 0;                   //ค่าอุณภูมิ

void setup() {
  Serial.begin(9600);
  dhtSS.begin();
  pinMode(D1, INPUT);
  pinMode(D5, OUTPUT);
}

void loop() {
  humid = dhtSS.readHumidity();
  temp = dhtSS.readTemperature();
  Serial.print("Humid: ");
  Serial.print(humid);
  Serial.println(" %, ");
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println(" C ");
  if (temp > 28) {
    digitalWrite(D5, 1);
  }
  else {
    digitalWrite(D5, 0);
  }
  delay(2000);
}
