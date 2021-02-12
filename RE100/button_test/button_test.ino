int button = 3;

void setup(){
  Serial.begin(9600);
  pinMode(button,INPUT);
}

void loop(){
 int B = digitalRead(button);
if(B == 1){
 Serial.println("on-----------------");
}

else if(B == 0){
  Serial.println("off");
}

else
  Serial.println("no signal");
  

delay(10);  
}

