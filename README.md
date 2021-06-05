# M5stack_Env2
 
## 自分用メモ
* 気圧を取得して、Bluetoothでブラウザに送信
* [こちらのサイト](https://plant-raspberrypi3.hatenablog.com/entry/2020/12/14/232112)を参考にしました。
* シリアルポートに送られてくるデータはバイナリなので、,decode("utf-8")で文字型にデコードする。[ここ](https://python.civic-apps.com/python3-bytes-str-convert/)に書いてあった
