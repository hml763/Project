#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define button 3

LiquidCrystal_I2C lcd(0x27, 16,2);


int signal;
int threshold = 370;  //380이 딱임
int pulse_sensor=0;
int led=13;
int i=0,j=0,k=0,temp=0;
unsigned long int curr_time = millis();
int second_var = 0;
int arr[400]; 
int count=0,num=0;

unsigned int second=0;
unsigned int minute=0;

void setup(){
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  
//  loop();
  
}


void loop(){
  
     
   while(1){
      int But = digitalRead(button);
      
      if(But == 1){
        
        delay(500);
        lcd.clear();
        Serial.println("button pushed!!!");
        lcd.setCursor(0,0);
        lcd.print("Button pushed!");
        delay(500);
        //////////////------------------
        for(i=0;i<10;i++){    //num should have same value with arr[i]
            signal = analogRead(pulse_sensor);  
            Serial.println(signal);
   
            arr[i] = signal;
            Serial.print("sequence : ");
            Serial.print(i);
            Serial.print("    ");
      
            delay(2);
          
          
            if(arr[i] > threshold){
              if(arr[i-1] < threshold){
                Serial.print("-----------heart pumped!!-----------");
                count++;
              }
            }
       
                        
            Serial.print("time : ");
            Serial.println(millis());
            //if(millis() > 10000 & millis() < 10060) //시간 정하기
        }
        ///////////////----------------
       
        goto here;
        
       }
       
       else if(But == 0){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("No signal");
            Serial.println("");
       }
      
   }
  
   
   
here:

  printing();
  delay(1000);
  
  sorting();
  cal();
     
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("max : ");
  lcd.print(arr[i-1]);
  lcd.setCursor(0,1);
  lcd.print("min : ");
  lcd.print(arr[0]);
  delay(3000);
   
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Heart beat: ");
  lcd.print(count);
  
  if(count > 100){
     lcd.setCursor(0,1);
     lcd.print("Fast, calm down"); 
  }
  
  else if(count <= 100 && count >= 60){
     lcd.setCursor(0,1);
     lcd.print("Average");
  }
  
  else if(count < 60){
     lcd.setCursor(0,1);
     lcd.print("Slow, get up!");
  }
  
  else{
     lcd.setCursor(0,1);
     lcd.print("No signal");
  }
 
  delay(5000);
  
  
  exit(0);

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
   Serial.print("max : ");
   Serial.println(arr[i-1]);  //바꿔주기
   Serial.print("min : ");
   Serial.println(arr[0]);
   
   Serial.print("heart beat(times/10s) : ");
   Serial.println(count);

}


void printing(){
  Serial.print("calculating . ");
  delay(400);
  Serial.print(" . ");
  delay(400);
  Serial.print(" . ");
  delay(400);
  Serial.print(" . ");
  delay(400);
  Serial.println();
}

   
