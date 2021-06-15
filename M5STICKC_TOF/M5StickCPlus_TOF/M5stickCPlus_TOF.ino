

// Import required l ibraries
#include <M5StickCPlus.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

VL53L0X sensor;
int textSize = 5;

//距離の測定＆LCDの表示関数
String measure_distance() {
  float dist = sensor.readRangeContinuousMillimeters();
  M5.update();
  int dstCMs = int(round(dist / 10));
  M5.Lcd.setCursor(20, 80);
  M5.Lcd.fillScreen( BLACK);
  M5.Lcd.print(dstCMs);
  SerialBT.println(float(dstCMs));
  Serial.println(float(dstCMs));
  return String(dstCMs);
}

void setup()
{
  Serial.begin(115200);  // 一応Serialを初期化
  SerialBT.begin("M5_Physics_ToF");
  M5.Lcd.setRotation( 1 );
  M5.Lcd.setTextSize(textSize);

  // put your setup code here, to run once:
  Wire.begin(0, 26, 400000);// join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output

  //センサーのセットアップ
  Wire.begin(0, 26, 100000);
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }
  sensor.startContinuous();
  M5.begin();

}

void loop()
{
  measure_distance();
  delay(100);
}
