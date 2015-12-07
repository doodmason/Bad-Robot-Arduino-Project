#include <Makeblock.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>


MeSoundSensor mySound(PORT6);
MeUltrasonicSensor ultraSensor(PORT_7);
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

int sound = 0;
int distance = 0;

void setup(){
 Serial.begin(9600);
}

void loop(){
 sound = mySound.strength();
 distance = ultraSensor.distanceCm();
 //robot drives in one direction
 motor1.run(-50);
 motor2.run(50);

 //yell at robot
 if (sound > 500){
   //spin
   motor1.run(150);
   motor2.run(150);
   buzzerOn();
   delay(500);
   //run away
   motor1.run(-150);
   motor2.run(150);
   delay(2000);
   buzzerOff();
   //forgets you hate him and returns
   motor1.run(50);
   motor2.run(50);
   delay(1550);
   
 } 

}
 
 

