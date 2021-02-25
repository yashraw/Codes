int DCWATERPUMP = 13; 
int sensor = 8; 
int val; //This variable stores the value received from Soil moisture sensor.
void setup() {
  pinMode(13,OUTPUT); //Set pin 13 as OUTPUT pin, to send signal to relay
  pinMode(8,INPUT); //Set pin 8 as input pin, to receive data from Soil moisture sensor.
}

void loop() { 
  val = digitalRead(8);  //Read data from soil moisture sensor  
  if(val == LOW) 
  {
  digitalWrite(13,HIGH); //if soil moisture sensor provides LOW value send LOW value to relay
  Serial.println(val);
  }
  else
  {
  digitalWrite(13,LOW); //if soil moisture sensor provides HIGH value send HIGH value to relay
  Serial.println(val);
  }
  delay(600); //Wait for few second and then continue the loop.
}
