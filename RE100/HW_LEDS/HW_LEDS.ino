#include <LiquidCrystal_I2C.h>
#include <Wire.h>


LiquidCrystal_I2C lcd(0x27,16,2);

int button = 13;

void setup(){
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  
  pinMode(button,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(35,OUTPUT);  
  pinMode(48,OUTPUT);
}

void loop(){
  
  lcd.clear();
  lcd.setCursor(0,0);
    
  int B = digitalRead(button);

  if(B == 1){     

   Serial.println("on-----------------");
   lcd.setCursor(0,0);
   lcd.print("Sending...");
   digitalWrite(11,HIGH);
   digitalWrite(10,HIGH);
   delay(100);
   digitalWrite(11,LOW);
   digitalWrite(10,LOW); 
   digitalWrite(9,HIGH);
   digitalWrite(8,HIGH);
   delay(100);
   digitalWrite(9,LOW);
   digitalWrite(8,LOW); 
   digitalWrite(7,HIGH);
   digitalWrite(6,HIGH);
   delay(100);
   digitalWrite(7,LOW);
   digitalWrite(6,LOW); 
   digitalWrite(5,HIGH);
   digitalWrite(4,HIGH);
   delay(100);
   digitalWrite(5,LOW);
   digitalWrite(4,LOW);
   digitalWrite(3,HIGH);
   digitalWrite(2,HIGH);
   delay(100);
   digitalWrite(3,LOW);
   digitalWrite(2,LOW);
   digitalWrite(22,HIGH);
   digitalWrite(23,HIGH);
   delay(100);
   digitalWrite(22,LOW);
   digitalWrite(23,LOW);   
   digitalWrite(24,HIGH);
   digitalWrite(25,HIGH);
   delay(100);
   digitalWrite(24,LOW);
   digitalWrite(25,LOW);
   digitalWrite(26,HIGH);
   digitalWrite(27,HIGH);
   delay(100);
   digitalWrite(26,LOW);
   digitalWrite(27,LOW);
   digitalWrite(28,HIGH);
   digitalWrite(29,HIGH);
   delay(100);
   digitalWrite(28,LOW);
   digitalWrite(29,LOW);
   digitalWrite(30,HIGH);
   digitalWrite(31,HIGH);
   delay(100);
   digitalWrite(30,LOW);
   digitalWrite(31,LOW);
   digitalWrite(34,HIGH);
   digitalWrite(35,HIGH);
   delay(100);
   digitalWrite(34,LOW);
   digitalWrite(35,LOW);
   delay(100);
   digitalWrite(34,HIGH);
   digitalWrite(35,HIGH);
   delay(100);
   digitalWrite(34,LOW);
   digitalWrite(35,LOW);   
   digitalWrite(34,HIGH);
   digitalWrite(35,HIGH);
   delay(100);
   digitalWrite(34,LOW);
   digitalWrite(35,LOW);
   digitalWrite(34,HIGH);
   digitalWrite(35,HIGH);
   delay(100);
   digitalWrite(34,LOW);
   digitalWrite(35,LOW);
   
   for(int i=0;i<10;i++){
      digitalWrite(35,HIGH);
      delay(200);
      digitalWrite(35,LOW); 
   }
   
   for(int r=0;r<10000;r++){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Complete!!!");
     digitalWrite(11,HIGH);
     digitalWrite(10,HIGH); 
     digitalWrite(9,HIGH);
     digitalWrite(8,HIGH);
     digitalWrite(7,HIGH);
     digitalWrite(6,HIGH);
     digitalWrite(5,HIGH);
     digitalWrite(4,HIGH);
     digitalWrite(3,HIGH);
     digitalWrite(2,HIGH);
     digitalWrite(22,HIGH);
     digitalWrite(23,HIGH);
     digitalWrite(24,HIGH);
     digitalWrite(25,HIGH);
     digitalWrite(26,HIGH);
     digitalWrite(27,HIGH);   
     digitalWrite(28,HIGH);
     digitalWrite(29,HIGH);
     digitalWrite(30,HIGH);
     digitalWrite(31,HIGH);
     digitalWrite(34,HIGH);
     digitalWrite(35,HIGH);
   
     delay(1000);
   
     digitalWrite(11,LOW);
     digitalWrite(10,LOW);
     digitalWrite(9,LOW);
     digitalWrite(8,LOW); 
     digitalWrite(7,LOW);
     digitalWrite(6,LOW);   
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,LOW);
     digitalWrite(22,LOW);
     digitalWrite(23,LOW);   
     digitalWrite(24,LOW);
     digitalWrite(25,LOW);   
     digitalWrite(26,LOW);
     digitalWrite(27,LOW);   
     digitalWrite(28,LOW);
     digitalWrite(29,LOW);  
     digitalWrite(30,LOW);
     digitalWrite(31,LOW);   
     digitalWrite(34,LOW);

     }
        
  }
   


else if(B == 0){
  Serial.println("off");
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("No signal");
  
   digitalWrite(11,HIGH);
   delay(300);
   digitalWrite(11,LOW); 
   digitalWrite(9,HIGH);
   delay(300);
   digitalWrite(9,LOW); 
   digitalWrite(7,HIGH);
   delay(300);
   digitalWrite(7,LOW);
   digitalWrite(5,HIGH);
   delay(300);
   digitalWrite(5,LOW);
   digitalWrite(3,HIGH);
   delay(300);
   digitalWrite(3,LOW);
   digitalWrite(22,HIGH);
   delay(300);
   digitalWrite(22,LOW); 
   digitalWrite(24,HIGH);
   delay(300);
   digitalWrite(24,LOW);
   digitalWrite(26,HIGH);
   delay(300);
   digitalWrite(26,LOW);
   digitalWrite(28,HIGH);
   delay(300);
   digitalWrite(28,LOW);
   digitalWrite(30,HIGH);
   delay(300);
   digitalWrite(30,LOW);
  
    }



else
  Serial.println("no signal");
  

delay(10);  
}
