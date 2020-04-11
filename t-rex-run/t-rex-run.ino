/**
 * Used to play Google's T-Rex run game with no machine learning just servos and LDR sensors. 
 * @author Jeffrey Boisvert
 */

#include <Servo.h>

Servo jumpServo; 
Servo duckServo; 

//Pins
const int JUMP_SERVO_PIN = 2; 
const int DUCK_SERVO_PIN = 4;  

//Servo positions
const int JUMP_OFF_POSITION = 10; //Change this based on how your servos are set up 
const int JUMP_ON_POSITION = 25; //Change this based on how your servos are set up 
const int DUCK_OFF_POSITION = 105; //Change this based on how your servos are set up 
const int DUCK_ON_POSITION = 120; //Change this based on how your servos are set up 

void setup() {
  jumpServo.attach(JUMP_SERVO_PIN); 
  duckServo.attach(DUCK_SERVO_PIN); 
  startPosition();
  Serial.begin(9600);
}

void loop() {
  offPosition();     
  delay(180); 
  onPosition();
  delay(180);  
  offPosition();          
}

void startPosition(){
  jumpServo.write(JUMP_OFF_POSITION); 
  duckServo.write(DUCK_OFF_POSITION); 
}

void offPosition(){
  jumpServo.write(JUMP_OFF_POSITION); 
  duckServo.write(DUCK_OFF_POSITION); 
}

void onPosition(){
  jumpServo.write(JUMP_ON_POSITION); 
  duckServo.write(DUCK_ON_POSITION); 
}
