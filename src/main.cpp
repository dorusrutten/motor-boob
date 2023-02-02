#include <Arduino.h>
#include <Servo.h>
#include "pins_arduino.h"

#define GC 8
Servo boob;
int ass = 1;
int knop = 3;
int button;
byte state;

void setup() {
  Serial.begin(9600);
  Serial.println();
  // print the code has started in the serial monitor on the computer
  Serial.println("Code has started!");
  pinMode(GC, OUTPUT);
  pinMode(8,INPUT);
  // boob.attach(2);
}

// loop with checking if the power is going back to the arduino and changing the state of the servomotor
void loop() {  
  state = digitalRead(GC);
  Serial.print(state);

// if the digital read from pin 8 is high (prob. anything higher then 0) then...
if(digitalRead(8) == HIGH){
  //boob.write(0);
  //Enable pin2 for the servo connection
  boob.attach(2);
  delay(1000);
  Serial.print("1oob");
}

// if pin 8 is anything except HIGH (prob 1) then...
else {
  delay(1000);
  Serial.print("dor");
  // pin3 now is the connection to the servo (Disconnected)
  boob.attach(3);
}

// end loop
} 
