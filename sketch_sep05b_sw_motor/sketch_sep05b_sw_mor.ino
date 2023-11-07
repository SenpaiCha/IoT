int MotorL = D1;
int MotorR = D2;
int MotorPWM = D3;
int k1 = D5;
int k2 = D6;
int k3 = D7;
void setup() {
  pinMode(MotorL,OUTPUT);
  pinMode(MotorR,OUTPUT);
  pinMode(MotorPWM,OUTPUT); 
  pinMode(k1,INPUT);
  pinMode(k2,INPUT);
  pinMode(k3,INPUT);
  Serial.begin(9600);
}
void loop() {
  //สั่งให้มอเตอร์หมุนขวา
  digitalWrite(MotorL,1);
  digitalWrite(MotorR,0);
  k1=digitalRead(D5);
  k2=digitalRead(D6);
  k3=digitalRead(D7);
  if ((k1==0)&&(k2==1)&&(k3==1)){
    analogWrite(MotorPWM,1000);      
    Serial.println("speed no.3");
    }
  if ((k1==1)&&(k2==0)&&(k3==1)){
    analogWrite(MotorPWM,600);      
    Serial.println("speed no.2");
    }
  if ((k1==1)&&(k2==1)&&(k3==0)){
    analogWrite(MotorPWM,300);      
    Serial.println("speed no.1");
    }
  if ((k1==1)&&(k2==1)&&(k3==1)){
    analogWrite(MotorPWM,0);      
    Serial.println("stop");
    }
}
