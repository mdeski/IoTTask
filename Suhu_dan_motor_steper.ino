#include <M5Stack.h>
#include "Arduino.h"
#include <DHT12.h>
#include "Wire.h"

// Instantiate Wire for generic use at 400kHz
TwoWire I2Cone = TwoWire(0);
// Instantiate Wire for generic use at 100kHz
TwoWire I2Ctwo = TwoWire(1);

DHT12 dht12(&I2Ctwo, 21,22);

const int MOTOR_A_A = 2;
const int MOTOR_A_B = 5;
const int MOTOR_A_C = 12;
const int MOTOR_A_D = 13;


void setup(){
  I2Cone.begin(21,22,400000);
  dht12.begin();
  Serial.begin(115200);
  M5.begin();
  Wire.begin();
  pinMode(MOTOR_A_A, OUTPUT);
  pinMode(MOTOR_A_B, OUTPUT);
  pinMode(MOTOR_A_C, OUTPUT);
  pinMode(MOTOR_A_D, OUTPUT);
}

//funciton motorr nya
void motor(){
  digitalWrite(MOTOR_A_A, HIGH);
  digitalWrite(MOTOR_A_B, HIGH);
  digitalWrite(MOTOR_A_C, LOW);
  digitalWrite(MOTOR_A_D, LOW);
  delay(10)
}

//Logika untuk suhu nya
void loop() {
  float tmp = dht12.readTemperature();
  M5.Lcd.setCursor(30, 100, 4);
  M5.Lcd.printf("Temp: %2.1f", temp);
  Serial.println(tmp);
  if (tmp>=30){
    motor();
  }
}
