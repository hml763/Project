#include <Wire.h>
#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
#include <LiquidCrystal_I2C.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS     1000

// PulseOximeter is the higher level interface to the sensor it offers:
//  * beat detection reporting
//  * heart rate calculation
//  * SpO2 (oxidation level) calculation
PulseOximeter pox;
int button = 8;

uint32_t tsLastReport = 0;
int blueTx=2;   //Tx (보내는핀 설정)at
int blueRx=3;   //Rx (받는핀 설정)


SoftwareSerial BTSerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
LiquidCrystal_I2C lcd(0x27,20,4); 

int i=0,j=0,k=0,temp=0;
int second_var=0;
int arr[200];
int count=0,num=0;

// Callback (registered below) fired when a pulse is detected

void onBeatDetected(){
    Serial.println("Beat!");
}

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello");
  
  Serial.begin(9600);
  BTSerial.begin(9600); //블루투스 시리얼
  pinMode(button,INPUT);
  Serial.print("Initializing pulse oximeter..");  // Initialize the PulseOximeter instance

    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }

    // The default current for the IR LED is 50mA and it could be changed by uncommenting the following line.
    // pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

    // Register a callback for the beat detection
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop(){
    while(1){
        int B = digitalRead(button);
        if(B==1){
               lcd.clear();
               pox.update();
               lcd.setCursor(0,0);
               lcd.print("Start!");
               lcd.setCursor(0,1);
               lcd.print("receaving data..");
               delay(1000);
    
               for(i=0;i<20;i++){     //측정할 횟수(i<횟수)
    
    // Asynchronously dump heart rate and oxidation levels to the serial For both, a value of 0 means "invalid"
                //    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
                    //Serial.print("Heart rate:");
                    //Serial.print(pox.getHeartRate());
                    arr[i] = 97;
                    Serial.print("bpm / SpO2:");
                    Serial.print(arr[i]);
                    Serial.println("%");

                    
                    delay(100);
            
                  //  tsLastReport = millis();
                   // }
                
                }

                goto there;
      
        }

        else if(B==0){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("no signal");
        }
    }

there:

  delay(10);
  
  printing();
  delay(1000);
  sorting();
  cal();

  delay(3000);

  if(arr[2] >= 95 ){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Normal  :)");
    
    BTSerial.print("You are healthy :) ");
  }
/*
  else if( < 95 && pox.getSpO2() >= 90){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Low_Oxg..Lev1");
    lcd.setCursor(0,1);
    lcd.print("Go see Doctor");

    BTSerial.println("Very Low Oxygen level");  
    BTSerial.print("Need regular Hospital");
  }
  */
/*
  else if(pox.getSpO2() < 90 && pox.getSpO2() >= 75 ){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Low_Oxg..Lev2");
    lcd.setCursor(0,1);
    lcd.print("Go Hospital NOW");  

    BTSerial.println("Low Oxygen level");  
    BTSerial.print("Require to go Hospital");
  }

  else if(pox.getSpO2() < 75 ){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Low_Oxg..Lev3");
    lcd.setCursor(0,1);
    lcd.print("Go Hospital NOW!!!");

    BTSerial.println("Very Low Oxygen level");  
    BTSerial.print("Require to go Hospital Immediately");
  }

*/
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wrong signal");
    lcd.setCursor(0,1);
    lcd.print("Estimate again");
    BTSerial.print("Wrong signal");
  }

  delay(5000);
  
}

void printing(){
  lcd.clear();
  lcd.setCursor(0,0);
  BTSerial.print("Calculating ...");
  lcd.print("calculating .");
  delay(400);
  lcd.print(".");
  delay(400);
  lcd.print(".");
  delay(400);
  lcd.print(".");
  
}
  

void sorting(){
  for(j=0;j<i;j++){
    for(k=0;k<i-1-j;k++){
      if(arr[k] > arr[k+1]){
        temp = arr[k];
        arr[k] = arr[k+1];
        arr[k+1] = temp;
      }
    }
  }
  
}



void cal(){
  /*
    Serial.print("max : ");
    Serial.println(arr[i-1]);
    Serial.print("min : ");
    Serial.println(arr[0]);
*/
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("max : ");
    lcd.print(arr[i-1]);
    lcd.setCursor(0,1);
    lcd.print("min : ");
    lcd.print(arr[0]);

    BTSerial.print("SP02 max : ");
    BTSerial.println(arr[i-1]);
    BTSerial.print("SP02 min : ");
    BTSerial.print(arr[0]);
    
    
}




