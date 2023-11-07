#define BLYNK_TEMPLATE_ID "TMPL6pV9iPgCx"
#define BLYNK_TEMPLATE_NAME "DHT22"
#define BLYNK_AUTH_TOKEN "WfLPcYPU3fLNuCLjQl4jQyZO3fUudhQd"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "WfLPcYPU3fLNuCLjQl4jQyZO3fUudhQd";
char ssid[] = "D";
char pass[] = "12345678";

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
