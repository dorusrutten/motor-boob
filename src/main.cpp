#include <Arduino.h>
#include <Servo.h>
#include "pins_arduino.h"

Servo boob1;
Servo boob2;
Servo boob3;
Servo boob4;
byte state;
int Xpin= A0;
int Ypin= A1;
int sPin= 8;
int Xval;
int Yval;
int Sval;

void setup() {
  Serial.begin(9600);
  Serial.println(); /*als je het mij vraagt doet dit ook niks en kan je dit verwijderen!!!!!!!!!!!!!!!!!!!!!!!*/
  Serial.println("Code has started!"); /*Prints in the serial monitor page, this is to make sure that the code actually ran xd*/
  pinMode(2,OUTPUT); /*Set pin 2 as an output*/
  pinMode(3,OUTPUT); /*Set pin 3 as an output*/
  pinMode(4,OUTPUT); /*Set pin 4 as an output*/
  pinMode(5,OUTPUT); /*Set pin 5 as an output*/
  pinMode(8,INPUT);  /*Set pin 8 as an input*/
  pinMode(9,INPUT);  /*Set pin 9 as an input*/
  pinMode(10,INPUT); /*Set pin 10 as an input*/
  pinMode(11,INPUT); /*Set pin 11 as an input*/
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);
}

// loop with checking if the power is going back to the ar duino and changing the state of the servomotor
void loop() {  
Xval= analogRead(Xpin);
Yval= analogRead(Ypin);
Sval= digitalRead(sPin);
Serial.print(" X value =");
Serial.print(Xval);
Serial.print(" Y value =");
Serial.print(Yval);
Serial.print(" Switch value =");
Serial.print(Sval);

// if the digital read from pin 8 is high (prob. anything higher then 0) then...
if(Xval > 800){
  Serial.print("1");
  boob1.attach(2);   /*Enable pin 2 for the servo connection*/
  boob2.attach(3);   /*Enable pin 3 for the servo connection*/
  boob3.attach(4);   /*Enable pin 4 for the servo connection*/
  boob4.attach(5);   /*Enable pin 5 for the servo connection*/
  boob1.write(180);  /*Set the servo to 180 degrees*/
  boob2.write(180);  /*Set the servo to 180 degrees*/
  boob3.write(0);    /*Set the servo to 0 degrees*/
  boob4.write(0);    /*Set the servo to 0 degrees*/
}

else if(Xval < 300){
  Serial.print("2");
  boob1.attach(2);   /*Enable pin 2 for the servo connection*/
  boob2.attach(3);   /*Enable pin 3 for the servo connection*/
  boob3.attach(4);   /*Enable pin 4 for the servo connection*/
  boob4.attach(5);   /*Enable pin 5 for the servo connection*/
  boob1.write(0);    /*Set the servo to 0 degrees*/
  boob2.write(0);    /*Set the servo to 0 degrees*/
  boob3.write(180);  /*Set the servo to 180 degrees*/
  boob4.write(180);  /*Set the servo to 180 degrees*/
}

else if(Yval > 800){
  Serial.print("3");
  boob1.attach(2);   /*Enable pin 2 for the servo connection*/
  boob2.attach(3);   /*Enable pin 3 for the servo connection*/
  boob3.attach(4);   /*Enable pin 4 for the servo connection*/
  boob4.attach(5);   /*Enable pin 5 for the servo connection*/
  boob1.write(180);  /*Set the servo to 180 degrees*/
  boob2.write(0);    /*Set the servo to 0 degrees*/
  boob3.write(180);  /*Set the servo to 180 degrees*/
  boob4.write(0);    /*Set the servo to 0 degrees*/
} 
else if(Yval < 300){
  Serial.print("4");
  boob1.attach(2);   /*Enable pin 2 for the servo connection*/
  boob2.attach(3);   /*Enable pin 3 for the servo connection*/
  boob3.attach(4);   /*Enable pin 4 for the servo connection*/
  boob4.attach(5);   /*Enable pin 5 for the servo connection*/
  boob1.write(0);    /*Set the servo to 0 degrees*/
  boob2.write(10);  /*Set the servo to 180 degrees*/
  boob3.write(0);    /*Set the servo to 0 degrees*/
  boob4.write(180);  /*Set the servo to 180 degrees*/ 
}
else if(Sval == 0){
  boob1.attach(2);   /*Enable pin 2 for the servo connection*/
  boob2.attach(3);   /*Enable pin 3 for the servo connection*/
  boob3.attach(4);   /*Enable pin 4 for the servo connection*/
  boob4.attach(5);   /*Enable pin 5 for the servo connection*/
  boob1.write(10);  /*Set the servo to 180 degrees*/
  boob2.write(10);    /*Set the servo to 0 degrees*/
  boob3.write(10);  /*Set the servo to 180 degrees*/
  boob4.write(10);  
}
// if anything else is true then detach all motors and print off.
else {
Serial.print("off!");
boob1.detach();
boob2.detach();
boob3.detach();
boob4.detach();
} // end loop
}
