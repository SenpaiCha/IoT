#define BLYNK_TEMPLATE_ID "TMPL6i9dx8GYX"
#define BLYNK_TEMPLATE_NAME "HHT22Only"
#define BLYNK_AUTH_TOKEN "1j2nOIIHJlKMlG2GctkYz_k3cE8FVYHz"
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "1j2nOIIHJlKMlG2GctkYz_k3cE8FVYHz";
char ssid[] = "Me";
char pass[] = "01234567890";

#define DHTPIN  D1                
#define DHTTYPE  DHT22            
DHT dht(DHTPIN, DHTTYPE);

float humid = 0;                  
float temp = 0;  

void setup() 
{
  Serial.begin(9600);
  dht.begin();
  pinMode(D1, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() 
{
  temp = dht.readTemperature();
  humid = dht.readHumidity();
  Serial.print("Temp : ");
  Serial.print(temp);
  Serial.println(" C ");
  Serial.print("Humid : ");
  Serial.print(humid);
  Serial.println(" %, ");
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, humid);
  Blynk.run();
  delay(2000);
}

