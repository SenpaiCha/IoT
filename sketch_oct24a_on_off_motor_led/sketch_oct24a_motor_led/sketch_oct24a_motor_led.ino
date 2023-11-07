#define BLYNK_TEMPLATE_ID "TMPL6NH4kzzVz"
#define BLYNK_TEMPLATE_NAME "DCmotorLED"
#define BLYNK_AUTH_TOKEN "evG_DfqmL_1yPUO5qFwV-sa6UmzyTXm7"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "evG_DfqmL_1yPUO5qFwV-sa6UmzyTXm7";
char ssid[] = "Me";
char pass[] = "012345678900";

int MotorL = D1;
int MotorR = D2;
int MotorPWM = D3;

void setup() {
  pinMode(MotorL,OUTPUT);
  pinMode(MotorR,OUTPUT);
  pinMode(MotorPWM,OUTPUT); 
  pinMode(D5,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0) {
  int Button1 = param.asInt();
  if (Button1==0){
    analogWrite(MotorPWM,0);  //ปรับความเร็วมอเตอร์เป็นระดับ 0
    digitalWrite(D5,0);  
  }
  else{
    analogWrite(MotorPWM,1000); //ปรับความเร็วมอเตอร์เป็นระดับ 10
    digitalWrite(D5,1);  
  } 

}
void loop() {
  digitalWrite(MotorL,1);   
  digitalWrite(MotorR,0);
  Blynk.run();   
}
