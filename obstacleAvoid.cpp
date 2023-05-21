#include "obstacleAvoid.h"

obstacleAvoid::obstacleAvoid(int multiPins[]){
trigPin = multiPins[0];
echoPin = multiPins[1];
servo = multiPins[2];
obstacleCar.init();
obstacleCar.setSpeed(255);
}

void obstacleAvoid::init(){
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
myservo.attach(servo);
}

void obstacleAvoid::read(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = (duration/2) * 0.0343;
}

void obstacleAvoid::changeMotors(int multiPins[]){
obstacleCar.changeMotors(multiPins);
}

void obstacleAvoid::obstacleMove(){
obstacleCar.move(1, 150, 1, 150);
myservo1.write(90);
read();

if(distance <= 30){
obstacleCar.move(0, 0, 0, 0);
myservo1.write(180);
delay(750);
read();
myservo1.write(90);

if(distance <= 30){
obstacleCar.move(0, 0, 0, 0);
myservo1.write(0);
delay(750);
read();
myservo1.write(90);

if(distance <= 30){
obstacleCar.move(1, 255/3, 0, 255/3);
delay(1500);
return;

}else{
obstacleCar.move(0, 255/3, 1, 255/3);
delay(750);
}

}else{
obstacleCar.move(1, 255/3, 0, 255/3);
delay(750);
}
}
}
