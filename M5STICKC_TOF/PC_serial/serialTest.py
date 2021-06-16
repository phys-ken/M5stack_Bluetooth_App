#できるのは、ターミナルに文字列を表示するだけ。

import serial
import matplotlib.pyplot as plt
import numpy as np

ser = serial.Serial()
ser.baudrate = 115200
ser.port = '/dev/cu.M5_Physics_ToF-ESP32SPP'
ser.open()

while(1):
  data = ser.readline().decode('utf-8').strip()
  # 配列をキューと見たてて要素を追加・削除
  print(data)
  print(type(data))

ser.close()