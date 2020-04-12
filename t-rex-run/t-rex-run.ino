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
const int JUMP_ON_POSITION = 30; //Change this based on how your servos are set up 
const int DUCK_OFF_POSITION = 105; //Change this based on how your servos are set up 
const int DUCK_ON_POSITION = 120; //Change this based on how your servos are set up 

void setup() {
  jumpServo.attach(JUMP_SERVO_PIN); 
  duckServo.attach(DUCK_SERVO_PIN); 
  startPosition();
  Serial.begin(9600);
}

void loop() {
  jump();   
  delay(180); 
  duck();
  delay(180);      
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
  jumpServo.write(JUMP_ON_POSITION); 
  delay(360); 
  jumpServo.write(JUMP_OFF_POSITION); 
}

/**
 * Used to press the key to duck 
 */
void duck(){
  duckServo.write(DUCK_ON_POSITION); 
  delay(360); 
  duckServo.write(DUCK_OFF_POSITION); 
}
