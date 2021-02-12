#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#define button 2

int blueTx=8;   //Tx (보내는핀 설정)at
int blueRx=7;   //Rx (받는핀 설정)
SoftwareSerial BTSerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
 

LiquidCrystal_I2C lcd(0x3F, 16,2);

int sensorvalue = 0;
int arr[400];
int count=0;
int temp=0;
int j,k,i=0;

void setup() {
  
  Serial.begin(9600); 
  pinMode(button,INPUT);
  BTSerial.begin(9600); //블루투스 시리얼
  
  lcd.init();
  lcd.backlight();
}

void loop() {
  
  while(1){
    
    int B = digitalRead(button);
    
    if(B == 1){    //button pushed!! hands off => which makes B==0
        delay(500);
    //    Serial.println("button pushed!!!");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Start!");
        lcd.setCursor(0,1);
        lcd.print("receaving data..");
        delay(500);
        
        //Serial.println("on-----------------");
                    
        for(i=0;i<400;i++){        //how much array
           
            sensorvalue = analogRead(A1);
            //Serial.print("sensor = " );                       
            Serial.println(sensorvalue); 
            arr[i] = sensorvalue;
            delay(50);
           
        }
     goto here;   
    }
        
     
  
    else if(B == 0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("No signal");
        //Serial.println("off");
    }
  }
    
  
here:
  
  printing();
  delay(1000);
  
  sorting();
  cal();  
  
  delay(3000);
  

  
  if(arr[i-1] > 800 && arr[i-1] < 999 ){      //amount of emg 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Level 4 (0~5)");
      lcd.setCursor(0,1);
      lcd.print("Strong");
      
      BTSerial.println("Level 4");
      BTSerial.print("Press level 4 below");
      delay(2000);
  }
  
   else if(arr[i-1] >= 999){      //amount of emg 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Level 5 (0~5)");
      lcd.setCursor(0,1);
      lcd.print("VERY Strong");
      
      BTSerial.println("Level 5");
      BTSerial.print("Press level 5 below");
      delay(2000);
  }
  
  else if(arr[i-1] > 600 && arr[i-1] <= 800){      //amount of emg 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Level 3 (0~5)");
      lcd.setCursor(0,1);
      lcd.print("Adequate");
      
      BTSerial.println("Level 3");
      BTSerial.print("Press level 3 below");
      delay(2000);
  }
  
  else if(arr[i-1] > 400 && arr[i-1] <= 600){      //amount of emg 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Level 2 (0~5)");
      lcd.setCursor(0,1);
      lcd.print("Weak");
      
      BTSerial.println("Level 2");
      BTSerial.print("Press level 2 below");
      delay(2000);
  }
  
  else if(arr[i-1] > 400 && arr[i-1] <= 600){      //amount of emg 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Level 1 (0~5)");
      lcd.setCursor(0,1);
      lcd.print("Very Weak");
      
      BTSerial.println("Level 1");
      BTSerial.print("Press level 1 below");
      delay(2000);
  }
  
  else {      //amount of emg 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Level 0 (0~5)");
      lcd.setCursor(0,1);
      lcd.print("Unmeasureable");
      
      BTSerial.print("Level 0 .. no signal try again");
      delay(2000);
  }
  
 delay(3000);
  
 // exit(0);
  
}


void printing(){
  /*Serial.print("calculating . ");
  delay(400);
  Serial.print(" . ");
  delay(400);
  Serial.print(" . ");  
  delay(400);
  Serial.print(" . ");
  delay(400);
  Serial.println();  */
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("calculating .");
  BTSerial.print("calculating ...");
  delay(600);
  lcd.print(".");
  //BTSerial.print(" . ");
  delay(600);
  lcd.print(".");
  //BTSerial.print(" . ");
  delay(600);
  lcd.print(".");
  //BTSerial.print(" . ");
  delay(600);
  
  
  
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
   
  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("max : ");
   lcd.print(arr[i-1]);  //바꿔주기
   lcd.setCursor(0,1);
   lcd.print("min : ");
   lcd.print(arr[0]);
  
   BTSerial.print("max : ");
   BTSerial.println(arr[i-1]);
   BTSerial.print("min : ");
   BTSerial.println(arr[0]);
  // Serial.print("max : ");
  // Serial.println(arr[i-1]);  //바꿔주기
  // Serial.print("min : ");
  // Serial.println(arr[0]);
   

}



