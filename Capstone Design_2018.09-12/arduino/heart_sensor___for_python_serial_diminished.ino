#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#define button 3

int blueTx=4;   //Tx (보내는핀 설정)at
int blueRx=5;   //Rx (받는핀 설정)
SoftwareSerial BTSerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
 

LiquidCrystal_I2C lcd(0x27, 16,2);


int signal;
int threshold = 163;  //380이 딱임
int pulse_sensor=0;
int led=13;
int i=0,j=0,k=0,temp=0;
unsigned long int curr_time = millis();
int second_var = 0;
int arr[400];     //if too many, cut down its size
int count=0,num=0;

unsigned int second=0;
unsigned int minute=0;

void setup(){
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600); //블루투스 시리얼
  
  lcd.init();
  lcd.backlight();
  
}


void loop(){
  
     
   while(1){
      int But = digitalRead(button);
      
      if(But == 1){
        
        delay(500);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Start!");
        lcd.setCursor(0,1);
        lcd.print("receaving data..");
        delay(500);
        //////////////------------------
        for(i=0;i<400;i++){    //num should have same value with arr[i]
            signal = analogRead(pulse_sensor);  
            Serial.println(signal);
   
            arr[i] = signal;
 //           Serial.print("sequence : ");
 //           Serial.print(i);
 //           Serial.print("    ");
      
            delay(12);
          
          
            if(arr[i] > threshold){
              if(arr[i-1] < threshold){
//                Serial.print("-----------heart pumped!!-----------");
                  count++;
              }
            }
        }
        goto here;
        
       
      }
       
       else if(But == 0){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("No signal");
//            Serial.println("off");
       }
      
   }
  
   
   
here:
  printing();
  delay(1000);
  
  sorting();
  cal();
     
   
  delay(3000);
   
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Heart beat: ");
  lcd.print(count);
  
  BTSerial.print("Heart beat : ");
  BTSerial.print(count);
  BTSerial.println(" (per/min)");
  
  if(count > 100){
     lcd.setCursor(0,1);
     lcd.print("Fast, calm down");    
     BTSerial.println("Fast, calm down");
  }
  
  else if(count <= 100){
     lcd.setCursor(0,1);
     lcd.print("Average");
     BTSerial.println("Average");
     
     if(count <=100 && count > 90){
           lcd.clear();
           lcd.setCursor(0,1);
           lcd.print("Level 4 (1~4)");
           BTSerial.print("Press Level 4 below");  
           delay(3000); 
     }
     
     else if(count <=90 && count > 80){
           lcd.clear();
           lcd.setCursor(0,1);
           lcd.print("Level 3 (1~4)");
           BTSerial.print("Press Level 3 below");  
           delay(3000);         
     }
     
     else if(count <= 80 && count > 70){
           lcd.clear();
           lcd.setCursor(0,1);
           lcd.print("Level 2 (1~4)");
           BTSerial.print("Press Level 2 below");  
           delay(3000);            
     }
     
     else if(count <= 70 ){
           lcd.clear();
           lcd.setCursor(0,1);
           lcd.print("Level 1 (1~4)");  
           BTSerial.print("Press Level 1 below");  
           delay(3000);      
     }
  }
  /*
  else if(count < 60){
     lcd.setCursor(0,1);
     lcd.print("Slow, get up!");
     BTSerial.println("Slow, get up!, try measuring aga");
  }
  */
  
  //
  
  
  else{
     lcd.setCursor(0,1);
     lcd.print("No signal");
     BTSerial.println("Connected, but no signal from Arduino");
  }
 
  delay(4680);
  
  
  //exit(0);

}


void printing(){
  lcd.clear();
  lcd.setCursor(0,0);
  BTSerial.print("Calculating ... ");
  lcd.print("Calculating .");
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
   Serial.print(count);
   Serial.println(" times");
   Serial.print("max : ");
   Serial.println(arr[i-1]);  //바꿔주기
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
   
   delay(10);
   
   BTSerial.print("max : ");
   BTSerial.println(arr[i-1]);
   BTSerial.print("min : ");
   BTSerial.println(arr[0]);
   
//   Serial.print("heart beat(times/10s) : ");
   

}




   
