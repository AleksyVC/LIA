//motorClass
#include "motorClass.h"  //Includes the "sevenSegment" h file
int motors[] = { 5, 6, 7, 8 };  //Creates an array composed of the pin of the motors
motorClass robotCar(motors);  //Constructs the robot car's motors using the pins

//LineFollower
#include "LineFollower.h"
int lines[] = {A0, A1, A2};
LineFollower lineTrack(lines);

//obstacleAvoid
#include "obstacleAvoid.h"
int obstaclePins[] = {13, 12, 10};
obstacleAvoid obstacleAvoid(obstaclePins);

//INFRARED REMOTE
#include "IRremote.h"//includes the infrared remote's library
int receiver = 9; // Signal Pin of IR receiver to Arduino Digital Pin 9
IRrecv irrecv(receiver);
decode_results results; 

int mode = 0; //sets the mode of the car when nothing is pressed to mode 0

//SERVO
#include <Servo.h>//includes the servo library
Servo myservo1;
Servo myservo2;//servo for passing the ball


void setup(){
//MOTOR CLASS
robotCar.init();

//LINE_FOLLOWER
lineTrack.changeMotors(motors);

//OBSTACLE_AVOID


//INFRARED_REMOTE
irrecv.enableIRIn(); //Start the receiver
Serial.begin(9600);

//SERVOS
myservo1.attach(10);  //attaches the servo on pin 10 to the servo object
myservo2.attach(11);  // attaches the servo on pin 11 to the servo object
}


void loop(){
robotCar.setSpeed(255);

if (irrecv.decode(&results)){
Serial.println(results.value);
irrecv.resume(); //receive the next value

switch (results.value){

case 3140497590: //OK button
mode = 0;
robotCar.stop();
break;

case 4126243066: // 1 button 
mode = 1;
break;
      
case 377844950: // 2 button
mode = 2;
break;

case 2305726874: // 3 button
mode = 3;
break;

if(mode == 0){   
robotCar.stop();
}

if(mode == 1){
case 115867002: // sraight button
robotCar.forward();                     
break;
      
case 3649045746: // left button
robotCar.left();                     
break;

case 1125684506: // backward button
robotCar.backward();
break;
      
case 467470074: // right button
robotCar.right();
break;

case 1366106270: // GUIDE button
robotCar.boost();
break;

/*pass*/
case 2166140447: // A button
myservo2.write(10);
break;

case 3183671899: //B button
myservo2.write(170);
break;
/**/
}
if(mode == 2){
lineTrack.lineMove();
break;

}
if(mode == 3){
obstacleAvoid.obstacleMove();
break;
}
}
}
}
