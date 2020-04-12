/**+---
 * Used to play Google's T-Rex run game with no machine learning just servos and a LDR sensor. 
 * @author Jeffrey Boisvert
 */

#include <Servo.h>

Servo jumpServo; 
Servo duckServo; 

//Pins
const int JUMP_SERVO_PIN = 2; 
const int DUCK_SERVO_PIN = 4;  
const int JUMP_SENSOR_PIN = A0;

//Servo positions
const int JUMP_OFF_POSITION = 10; //Change this based on how your servos are set up 
const int JUMP_ON_POSITION = 20; //Change this based on how your servos are set up 
const int DUCK_OFF_POSITION = 105; //Change this based on how your servos are set up 
const int DUCK_ON_POSITION = 120; //Change this based on how your servos are set up 

//Sensor object values
const int MIN_OBJECT_RANGE = 532; //Change based on your screen
const int MAX_OBJECT_RANGE = 695; //Change based on your screen

int jumpSensorValue = 0; 
const int TIME_BETWEEN_JUMP = 290; //Change based on your placement

void setup() {
  jumpServo.attach(JUMP_SERVO_PIN); 
  duckServo.attach(DUCK_SERVO_PIN); 
  startPosition();
  Serial.begin(9600);
}

void loop() {

  jumpSensorValue = analogRead(JUMP_SENSOR_PIN);
  Serial.println(jumpSensorValue);
  if(jumpSensorValue > MIN_OBJECT_RANGE && jumpSensorValue < MAX_OBJECT_RANGE){
    jump();   
  }
  else {
    duck();
  }
}

/**
 * Put both keys off the trigger
 */
void startPosition(){
  jumpServo.write(JUMP_OFF_POSITION); 
  duckServo.write(DUCK_OFF_POSITION); 
}

/**
 * Used to press the key to jump
 */
void jump(){
  duckServo.write(DUCK_OFF_POSITION); 
  jumpServo.write(JUMP_ON_POSITION); 
  delay(TIME_BETWEEN_JUMP); 
  jumpServo.write(JUMP_OFF_POSITION); 
}

/**
 * Used to press the key to duck 
 */
void duck(){
  duckServo.write(DUCK_ON_POSITION); 
}
