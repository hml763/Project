#include <CapacitiveSensor.h>
#include <SoftwareSerial.h>
#define CURRENT 20

CapacitiveSensor   cs_3_2 = CapacitiveSensor(3,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_8_7 = CapacitiveSensor(8,7);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_13_12 = CapacitiveSensor(13,12);  

int blueTx=9;   //Tx (보내는핀 설정)at
int blueRx=10;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언


extern volatile unsigned long timer0_millis; //타이머변수
unsigned long timeVal; //이전시간
unsigned long readTime; //현재타이머시간
int hour, min, sec, i=1, s;
boolean state=false;

  
void setup()                    
{
   cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   cs_8_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_13_12.set_CS_AutocaL_Millis(0xFFFFFFFF);
   Serial.begin(9600);
   
   mySerial.begin(9600); //블루투스 시리얼
}

void loop()                    
{    
    long start = millis();
    long timer = (millis()/1000);
    long total1 =  cs_3_2.capacitiveSensor(30);   //30이거!!!! 이거조절해보기
    long total2 =  cs_8_7.capacitiveSensor(30); 
    long total3 =  cs_13_12.capacitiveSensor(30); 
 
    //float volt = analogRead(A0) * (5.0 / 1024);   //전압 측정
    //float current = (volt - 2.5) * (CURRENT / 2); //전류 측정
    
    //Serial.print(millis() - start);        // check on performance in milliseconds
    
    if(Serial.available()){
        String inString = Serial.readStringUntil('\n');    
        int index1 = inString.indexOf(':'); 
        int index2 = inString.indexOf(':',index1+1);   
        int index3 = inString.length();
    
        hour = inString.substring(0, index1).toInt();
        min = inString.substring(index1+1,index2).toInt();
        sec = inString.substring(index2+1,index3).toInt();
  
    
        timer0_millis = ((long)hour*3600+min*60+sec)*1000;
        state=true;
        timeVal=millis();
     }
  
    /*
     if(millis()-timeVal>=16.1){ //1초 단위 출력
        readTime = millis()/1000;
      
        if(millis()>=86400000){
            timer0_millis=0;
        }
        timeVal = millis();
   
        sec = readTime%60;
        min = (readTime/60)%60;
        hour = (readTime/(60*60))%24;       
     
        if(sec != s){
          i = 1;
        }      
     Serial.print(hour);
     Serial.print(":");
     Serial.print(min);
     Serial.print(":");
     Serial.print(sec);      
     Serial.print(".");
     Serial.print(i);
     i++;
     
     s = sec;
                       // print sensor output 1
    Serial.print("      volt: \t");
    Serial.print(volt);
    Serial.print("  current: \t");
    Serial.print(current);*/
    Serial.print(" t1 : ");                    // tab character for debug windown spacing
    Serial.print(total1);
    Serial.print(" t2 : ");
    Serial.print(total2);
    Serial.print(" t3 : ");
    Serial.println(total3);
    //}
    
  delay(5);                             // arbitrary delay to limit data to serial port 
}
