#include <SoftwareSerial.h>
 #define CURRENT 20 // CURRENT 의 20 대신 30A 나 5A제품의 경우, 30 또는 5를 적어 주시면 됩니다.
int led = 13;
int blueTx=8;   //Tx (보내는핀 설정)at
int blueRx=9;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언

void setup() {

  // put your setup code here, to run once:
   mySerial.begin(9600); //블루투스 시리얼
   Serial.begin(9600);
}

void loop() {
    if (mySerial.available()) { 
      Serial.println("Prepared");      
    Serial.write(mySerial.read());  //블루투스측 내용을 시리얼모니터에 출력
    
  }

    float volt = analogRead(A0) * (5.0 / 1024);
  float current = (volt - 2.5) * (CURRENT / 2);

  digitalWrite(led,HIGH);
  
  mySerial.print("volt: \t");
  mySerial.print(volt);
  mySerial.print("  current: \t");
  mySerial.print(current);
  mySerial.println();

  delay(100);

}
