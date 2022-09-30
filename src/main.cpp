#include <Arduino.h>

boolean ledOn;

void setup() {
  // put your setup code here, to run once:

  // configure the USB serial monitor 
  Serial.begin(115200); 
 
 // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 

  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
 
  // set default PWM range 
  analogWriteRange(1023); 

  ledOn = false;
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read digiized value from d1 mini a/d convertor
  int iVal;
  iVal= analogRead(A0);

  int buttonState;
  buttonState = digitalRead(D5);
  

  // ON/OFF led from button
  if(buttonState == 0){
    if(!ledOn){
      ledOn = true;
      delay(500);
    } else if(ledOn){
      ledOn = false;
      delay(500);
    }
  }

  //Tunrs led on and of
  if(ledOn){
    analogWrite(D4, iVal);
    delay(100);
  } else if (!ledOn){
    digitalWrite(D4, buttonState);
    delay(100);

  }
  
  delay(1);
}