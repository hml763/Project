//rp_heart_sensor

int signal;
int threshold = 550;
int pulse_sensor=0;
int led=13;


void setup(){
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  
}




void loop(){
  signal = analogRead(pulse_sensor);
  
  Serial.println(signal);
  
  if(signal > threshold){
    digitalWrite(led,HIGH);
  }
  
  else
    digitalWrite(led,LOW);
  
  delay(1000);  
}
