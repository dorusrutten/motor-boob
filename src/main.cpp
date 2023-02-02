#include <Arduino.h>
#include <Servo.h>
#include "pins_arduino.h"

#define GC 8 /*pin 8 is defined as GC, geen idee waarvoor omdat we de pins to uitlezen bij de if/else functie */
Servo boob; /*sets the servo (library) to boob*/
int ass = 1;
int knop = 3;
int button;
byte state;

void setup() {
  Serial.begin(9600);
  Serial.println(); /*als je het mij vraagt doet dit ook niks en kan je dit verwijderen!!!!!!!!!!!!!!!!!!!!!!!*/
  Serial.println("Code has started!"); /*Prints in the serial monitor page, this is to make sure that the code actually ran xd*/
  pinMode(GC, OUTPUT); /*Refer to Line 5, no idea what this does right now*/
  pinMode(8,INPUT); /*Set pin 8 as input*/
}

// loop with checking if the power is going back to the arduino and changing the state of the servomotor
void loop() {  
  state = digitalRead(GC);
  Serial.print(state);

// if the digital read from pin 8 is high (prob. anything higher then 0) then...
if(digitalRead(8) == HIGH){
  //boob.write(0); no fucking clue what did does/did or is suppost to do!!!!!!!!!!!!!!!!!
  boob.attach(2); /*Enable pin2 for the servo connection*/
  delay(1000);
  Serial.print("Hell yeaahhh I'm turned on");
}

// if pin 8 is anything except HIGH (prob 1) then...
else {
  delay(1000);
  Serial.print("No movement means turned off, instantly");
  boob.attach(3); /*Pin 3 is now sending data to the servo to rotate (Disconnected)*/
}

// end loop
} 
