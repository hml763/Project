#include <LiquidCrystal_I2C.h>
#include <Wire.h>


LiquidCrystal_I2C lcd(0x27, 16,2);


int button = 3;
int led = 4;


void setup(){
  pinMode(button,INPUT);
  
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  
}

void loop(){
 
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Become Healthy!");
 lcd.setCursor(0,1);
 lcd.print(" :)");
 
  
  
}


















