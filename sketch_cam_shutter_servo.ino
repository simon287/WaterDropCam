/*
   Pour promicro  
   
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
#define servopin 6
#define tempsdechute 211// delay in ms between servo closing and shutter

int shutterPin =2;
int focusPin =3;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
 
  pinMode(servopin, OUTPUT);
  myservo.attach(servopin);  // attaches the servo on pin servopin to the servo object
  myservo.write(0);  
    pinMode(focusPin, OUTPUT);
    pinMode(shutterPin, OUTPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Connection OK...");

   digitalWrite(shutterPin,LOW);

}


void loop() {
  if (Serial.available())  

  { 
int inputstring = Serial.parseInt();
switch (inputstring){
case 0:
      Serial.println(inputstring);
      digitalWrite(focusPin,HIGH);
      delay (500);
      digitalWrite(focusPin,LOW);
      
break;

case 1:
      Serial.println(inputstring);
      servo_goutte(1500);
      delay(tempsdechute);       
      digitalWrite(shutterPin,HIGH);   
      delay (500);
      digitalWrite(shutterPin,LOW);
break;

default:
      Serial.println("Enter 1 for shutter or 0 for focus");
break;
  }
}
}
  
void servo_goutte(int tempoms) {


  int val=103;
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(tempoms);      // waits for the servo to get there
  myservo.write(0); 
                 // postion 103deg 

}









