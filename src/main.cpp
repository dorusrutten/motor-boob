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
  Serial.println("Code has started!");

  
  pinMode(GC, OUTPUT);

  //boob.attach(2);
  pinMode(8,INPUT);
}

void loop() {
  
  state = digitalRead(GC);
   Serial.print(state);
  
  if(digitalRead(8) == HIGH){
  //boob.write(0);
     boob.attach(2);
  delay(1000);
   Serial.print("1oob");
 }
else {
  delay(1000);
   Serial.print("dor");
   boob.attach(3);

}

}
