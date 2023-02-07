#include <Arduino.h>
#include <Servo.h>
#include "pins_arduino.h"

Servo boob1;
Servo boob2;
Servo boob3;
Servo boob4;
int ass = 1;
int knop = 3;
int button;
byte state;

void setup() {
  Serial.begin(9600);
  Serial.println(); /*als je het mij vraagt doet dit ook niks en kan je dit verwijderen!!!!!!!!!!!!!!!!!!!!!!!*/
  Serial.println("Code has started!"); /*Prints in the serial monitor page, this is to make sure that the code actually ran xd*/
  pinMode(2,OUTPUT); /*Set pin 2 as an output*/
  pinMode(3,OUTPUT); /*Set pin 3 as an output*/
  pinMode(4,OUTPUT);  /*Set pin 4 as output*/
  pinMode(5,OUTPUT); /*Set pin 5 as output*/
  pinMode(8,INPUT); /*Set pin 8 as an input*/
}

// loop with checking if the power is going back to the arduino and changing the state of the servomotor
void loop() {  

// if the digital read from pin 8 is high (prob. anything higher then 0) then...
if(digitalRead(8) == HIGH){
  boob1.attach(2); /*Enable pin 2 for the servo connection*/  
  boob2.attach(3); /*Enable pin 3 for the servo connection*/
  boob3.attach(4);// ebenbles pin 4 fir teh survo connection
  boob4.attach(5); /*Enable pin 5 for the servo connection*/
  delay(1);
  Serial.print("on!");
}

if(digitalRead(9) == HIGH){
Serial.print("knop 2 aan");
boob1.attach(2);
boob2.attach(3);
boob2.write(180);
}

// if(digitalRead(10) == HIGH){
//   Serial.print("knop 3 aan");
//   boob2.attach(3);
//   boob2.attach(4);
// } 

// if pin 8 is anything except HIGH (prob 1) then...
else {
  delay(1);
  Serial.print("off!");
  boob1.detach();
  boob2.detach();
  boob3.detach();
  boob4.detach();

  }

// end loop
} 
