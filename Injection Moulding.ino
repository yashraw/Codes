#include <MAX6675_Thermocouple.h>

#define SCK_PIN 3
#define CS_PIN 4
#define SO_PIN 5

#define READINGS_NUMBER 10
#define DELAY_TIME 20
const double desiredTempC = 250; // which temperature to maintain
const double readingTempC = 0;
MAX6675_Thermocouple* thermocouple = NULL;
int relayPin = 8;// set pin 8 for relay output


void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    thermocouple = new MAX6675_Thermocouple(
    SCK_PIN, CS_PIN, SO_PIN,
    READINGS_NUMBER, DELAY_TIME
    );
    Serial.println("Recycling Of Waste Plastics Using Injection Moulding Machine");
    Serial.println("Temperature Sensing Module ");
    Serial.println("First Initialization ");
    Serial.println("Relay ON, Band Heaters On ");
    Serial.print("Temperature to Achieve :")+ Serial.print(desiredTempC)+  Serial.println(" degrees C");
    pinMode(relayPin, OUTPUT);
    digitalWrite(7, LOW); // sets the digital pin 7 as 3.3V
    digitalWrite(6, HIGH); // sets the digital pin 6 as GND
}
void loop() {

  const double readingTempC = thermocouple->readCelsius(); 
  Serial.print("Reading Temp :"); Serial.print(readingTempC); Serial.println(" degrees C");
  if(readingTempC < desiredTempC-2){
    digitalWrite(relayPin, HIGH);// set relay pin to HIGH
    Serial.println("Relay ON ");
    const double readingTempC = thermocouple->readCelsius(); 
    delay(200);
  }
  else if(readingTempC > desiredTempC+2){
    digitalWrite(relayPin, LOW);// set relay pin to LOW
    Serial.println("Relay OFF ");
    const double readingTempC = thermocouple->readCelsius(); 
    delay(2000);  
    
  }


  
}
