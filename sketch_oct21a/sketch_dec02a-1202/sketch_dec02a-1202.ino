#include <Servo.h>

Servo myservo; // 建立一個 servo 物件，最多可建立 12 個 servo

int pos =0; // 設定 servo 位置變數

void setup() {
  // put your setup code here, to run once:
  myservo.attach(5); // 將 servo 物建連接到 D1
}

void loop() {
  // put your main code here, to run repeatedly:

  // 正轉 180 度
  for (pos =0; pos <=180; pos +=1) // 從 0 度旋轉到 180 度，每次 1 度
  {
    myservo.write(pos); // 告訴 servo 走到 'pos' 的位置
    delay(15); // 等待 15 ms 讓走到指定位置
  }

  // 反轉 180 度
  for (pos =180; pos >=0; pos -=1) // 從 180 度旋轉到 0 度，每次 1 度
  {
    myservo.write(pos); // 告訴 servo 走到 'pos' 的位置
    delay(15); // 等待 15 ms 讓走到指定位置
  }
  
}
