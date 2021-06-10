# M5stack Bluetooth App
 

## 自分用メモ
* 実験で使う無線通信アプリのコードは、ここで管理しよう。

1. 気圧取得アプリ
    1.  気圧を取得して、Bluetoothでブラウザに送信
    1. [こちらのサイト](https://plant-raspberrypi3.hatenablog.com/entry/2020/12/14/232112)を参考にしました。
    1. シリアルポートに送られてくるデータはバイナリなので、,decode("utf-8")で文字型にデコードする。[ここ](https://python.civic-apps.com/python3-bytes-str-convert/)に書いてあった

1. 距離計アプリ
    1. 実験
    1. 制御