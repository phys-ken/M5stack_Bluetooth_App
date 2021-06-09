/*
    Description: Use ENV II Unit to read temperature, humidity, atmospheric pressure, and display the data on the screen.
    Please install library before compiling:  
    Adafruit BMP280: https://github.com/adafruit/Adafruit_BMP280_Library
*/
#include <M5Stack.h>
#include <Wire.h>
#include "BluetoothSerial.h"
#include "Adafruit_Sensor.h"
#include <Adafruit_BMP280.h>
#include "SHT3X.h"
SHT3X sht30;
Adafruit_BMP280 bme;
BluetoothSerial SerialBT;

float tmp = 0.0;
float hum = 0.0;
float pressure = 0.0;

void setup() {
  Serial.begin(115200);  // 一応Serialを初期化
  SerialBT.begin("M5_Physics");
  
  M5.begin();
  M5.Power.begin();
  Wire.begin();
  M5.Lcd.setBrightness(10);
  M5.Lcd.setTextSize(3);
  Serial.println(F("ENV Unit(SHT30 and BMP280) test..."));

  while (!bme.begin(0x76)){  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    M5.Lcd.println("Could not find a valid BMP280 sensor, check wiring!");
  }
  M5.Lcd.clear(BLACK);
}

void loop() {
  pressure = bme.readPressure();
  if(sht30.get()==0){
    tmp = sht30.cTemp;
    hum = sht30.humidity;
  }
  Serial.printf("Temperatura: %2.2f*C  Humedad: %0.2f%%  Pressure: %0.2fPa\r\n", tmp, hum, pressure);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(WHITE, BLACK);
  
  M5.Lcd.printf("Temp: %2.1f  \r\nHumi: %2.0f%%  \r\nPressure:%2.0fPa\r\n", tmp, hum, pressure);
  SerialBT.println(pressure);
  delay(100);

}
