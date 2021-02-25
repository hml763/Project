#include <CapacitiveSensor.h>
#include <SoftwareSerial.h>

//CapacitiveSensor   cs_4_6 = CapacitiveSensor(11,10);
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
int blueTx=8;   //Tx (보내는핀 설정)at
int blueRx=9;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
int green = 12;
int red = 13;
long num = 1;  //for counting

extern volatile unsigned long timer0_millis; //타이머변수
unsigned long timeVal; //이전시간
unsigned long readTime; //현재타이머시간
int hour, min, sec, i=1, s;
int limit = 600;
boolean state=false;


void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   //Serial.begin(2000000);
   //Serial.begin(230400);
   Serial.begin(9600);
   mySerial.begin(9600); //블루투스 시리얼
   pinMode(green,OUTPUT);
   pinMode(red,OUTPUT);
}

void loop()                    
{
  
  if (mySerial.available()) {       
    Serial.write(mySerial.read());  //블루투스측 내용을 시리얼모니터에 출력
  }
  if (Serial.available()) {         
    mySerial.write(Serial.read());  //시리얼 모니터 내용을 블루추스 측에 WRITE
  }

    long start = millis();
    long timer = (millis()/1000);
    long total1 =  cs_4_2.capacitiveSensor(30);   //30이거!!!! 이거조절해보기 
//    long total2 =  cs_4_6.capacitiveSensor(30);

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
     Serial.print(num);
     Serial.print("   ");   
     Serial.print(hour);
     Serial.print(":");
     Serial.print(min);
     Serial.print(":");
     Serial.print(sec);      
     Serial.print(".");
     Serial.print(i);

     mySerial.print(num);
     mySerial.print("   ");   
     mySerial.print(hour);
     mySerial.print(":");
     mySerial.print(min);
     mySerial.print(":");
     mySerial.print(sec);      
     mySerial.print(".");
     mySerial.print(i);
     i++;
     
     s = sec;

    Serial.print("          ");                    // tab character for debug windown spacing
    Serial.println(total1);                  // print sensor output 1
    
    mySerial.print("       Capacitance : ");
    mySerial.println(total1); 
 //   Serial.print("    ");
 //   Serial.println(total2);
    }
    

    if(total1 > limit){
      digitalWrite(green, HIGH);      
      digitalWrite(red, LOW);
    }

 /*   else if(total2 > limit){
      digitalWrite(green,LOW);
      digitalWrite(red, HIGH);
    }
*/

    //delay(10);                             // arbitrary delay to limit data to serial port 
    num = num ;//+1;
}
