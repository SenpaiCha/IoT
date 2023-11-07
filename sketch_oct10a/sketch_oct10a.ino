#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <sQ_n_2b9RgltB6zreYxlD7QTp_1NoDFk.h>

char auth[] = "sQ_n_2b9RgltB6zreYxlD7QTp_1NoDFk";
char ssid[] = "Me";
char pass[] = "01234567890";

int ledG = D1;
int ledR = D2;  

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);

  digitalWrite(ledPin, LOW); // Ensure the LED is initially off

}

void loop() {
  Blynk.run();

}

BLYNK_WRITE(V0) {
  int led1State = param.asInt();
  digitalWrite(ledG, led1State); // Turn the LED on or off based on the button state
}

BLYNK_WRITE(V0) {
  int led2State = param.asInt();
  digitalWrite(ledR, led2State); // Turn the LED on or off based on the button state
}
