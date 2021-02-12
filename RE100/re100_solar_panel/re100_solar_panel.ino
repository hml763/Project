#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // LCD 라이브러리
#include "LowPower.h" // 태양광 모듈 라이브러리
#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

long randNumber;
int blueTx=7;   //Tx (보내는핀 설정)at
int blueRx=6;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


int redLed = 9;          // r핀 설정
int greenLed = 10;       // g핀 설정
int blueLed = 11;        // b핀 설정
int j = 0;
char company[12][12] = {"Samsung","KEPCO","LG","POSCO", "WoongJin",
"SK", "Knergy", "Incheon_E", "Greenco", "E-inteco", "Skens", "GS_energy"};

//const int analogIn = A0; //아날로그 입력 PIN
int mVperAmp = 66; // 아날로그 입력 mV당 전류 값
                   // 5A 짜리는 185
                   // 20A 짜리는 100
                   // 30A 짜리는 66
int RawValue= 0;   // 아날로그 값 저장 변수
int ACSoffset = 2500; // 기준 값 0A일때 아날로그 값은 2500 이다.
double Voltage = 0;   // 계산된 아날로그 값
double Amps = 0;      // 실제 측정된 전류 값

int LED = 13;            // 우노 LED핀 설정


void setup()
{
    // No setup is required for this library
    
    Serial.begin(9600);   // 시리얼 통신속도
    mySerial.begin(9600); //블루투스 시리얼
    pinMode(redLed,OUTPUT);    // RGB 출력으로 설정
    pinMode(greenLed,OUTPUT);
    pinMode(blueLed,OUTPUT);
    pinMode(LED,OUTPUT);
    
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
    
    lcd.init();                      // initialize the lcd 
    lcd.backlight();
    randomSeed(analogRead(0));
}

void loop() 
{
    digitalWrite(LED,LOW);
    
    if (mySerial.available()) {       
      Serial.write(mySerial.read());  //블루투스측 내용을 시리얼모니터에 출력
    }
    
    if (Serial.available()) {         
      mySerial.write(Serial.read());  //시리얼 모니터 내용을 블루추스 측에 WRITE
    }
    
    //Serial.println("hello");
    //Serial.flush(); //시리얼이 모두 전송될때까지 기다린다
    lcd.clear();

    float solarVolt = (float)analogRead(A0) * (5.0 / 1024.0);
    float batVolt = (float)analogRead(A1) * (5.0 / 1024.0);
  
    //아날로그 값 읽기
    RawValue = analogRead(A2);
    //아날로그 값 0 ~ 1024을 전앖 0(0V) ~ 5000(5V)으로 변경(계산을 쉽게 하기 위해)
    Voltage = (RawValue / 1024.0) * 5000; // Gets you mV
    //전류값 계산
    //측정된 전압을 0A기준으로 뺀다음 mV당 전류값으로 나누면 끝!
    Amps = ((Voltage - ACSoffset) / mVperAmp);
    
    Amps = Amps * (-1);

    Serial.print("mV = "); // shows the voltage measured 
    Serial.println(Voltage=Voltage/1000,3); // the '3' after voltage allows you to display 3 digits after decimal point
    Serial.print("Amps = "); // shows the voltage measured 
    Serial.println(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point   
    Serial.print("solarVolt = ");
    Serial.println(solarVolt);
    Serial.print("Battery Volt : ");
    Serial.println(batVolt);
 
    lcd.setCursor(0, 0);
    lcd.print("Volt: ");
    lcd.print(Voltage);
    lcd.setCursor(11,0);
    lcd.print("V");
    lcd.setCursor(0, 1);
    lcd.print("Amp : ");    
    lcd.print(Amps);
    lcd.setCursor(11,1);
    lcd.print("A");
    
    
    randNumber = random(1000,9999);
    double SMP = randNumber * 75;
    if(SMP < 0)
      SMP = SMP * (-1);
    double REC = randNumber/1000 * 78000;
    double amount = SMP + REC;
    //for(j=0;j<12;j++){}
    mySerial.print("Enterprise : ");
    for(int k=0;k<12;k++){
      for(int p=0;p<10;p++){
        mySerial.print(company[k][p]);
      }
      
      mySerial.print("\nEnergy Produced : ");
      mySerial.print(randNumber);
      mySerial.println(" KW");
      mySerial.print("SMP : ");
      mySerial.print(SMP);
      mySerial.println(" Won");
      mySerial.print("REC : ");
      mySerial.print(REC);
      mySerial.println(" Won");
      mySerial.print("Sum : ");
      mySerial.print(amount);
      mySerial.println(" Won\n");
      mySerial.println("\n\n\n\n\n\n\n");
      
          //솔라셀
    if(solarVolt > 4.5 )  
    {
        lcd.backlight(); //4.5V 이상일때 백라이트 전원을 깜빡인다
        delay(100);
    }

    //배터리
    if(batVolt >= 4.0)  //충분할때
    {
        digitalWrite(redLed,LOW);
        digitalWrite(greenLed,HIGH);
        digitalWrite(blueLed,LOW);
        delay(20);
        
        digitalWrite(redLed,LOW);
        digitalWrite(greenLed,LOW);
        digitalWrite(blueLed,LOW);
    }
    
    else if(batVolt > 3.5 && batVolt < 4.0 )  //보통일때
    {
        digitalWrite(redLed,LOW);
        digitalWrite(greenLed,LOW);
        digitalWrite(blueLed,HIGH);
        delay(20);
        
        digitalWrite(redLed,LOW);
        digitalWrite(greenLed,LOW);
        digitalWrite(blueLed,LOW);
    }
    
    else //배터리 부족일때
    {
        digitalWrite(redLed,HIGH);
        digitalWrite(greenLed,LOW);
        digitalWrite(blueLed,LOW);
        delay(20);
        
        digitalWrite(redLed,LOW);
        digitalWrite(greenLed,LOW);
        digitalWrite(blueLed,LOW);
    }

    // Enter power down state for 8 s with ADC and BOD module disabled
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);  //테스트 코드 1초마다
   // LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);  //실제 코드 8초마다
    
      
    }
    
    


}

