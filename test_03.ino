// LEDのピン番号
int LED = 13;
// 可変抵抗のピン番号
int VRES = 0;
// 可変抵抗の値
int vresVal = 0;
// LEDの値
int ledVal = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  // シリアル通信の開始
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  vresVal = analogRead(VRES);
  ledVal = map(vresVal,0,1023,0,255);

  // アナログ出力でLEDを光らせる
  analogWrite(LED,ledVal);

  // シリアルモニターで確認
  Serial.print(vresVal);
  Serial.print(",");
  Serial.print(ledVal);
  Serial.println();

  // 適度な感覚を開ける
  delay(100);
}
