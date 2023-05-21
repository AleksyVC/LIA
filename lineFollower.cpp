#include "LineFollower.h"

LineFollower::LineFollower(int multiPins[]){
leftPin = multiPins[2];
middlePin = multiPins[1];
rightPin = multiPins[0];
left = 0;
middle = 0;
right = 0;
lineCar.init();
lineCar.setSpeed(255);
}

void LineFollower::lineTrack(){
left = analogRead(leftPin);
middle = analogRead(middlePin);
right = analogRead(rightPin);
}

void LineFollower::linemove(){
left = analogRead(leftPin);
middle = analogRead(middlePin);
right = analogRead(rightPin);

if(left > 40) {
lineCar.move(1, 50, 0, 50);
}

else if(middle > 40){
lineCar.move(1, 100, 1, 100);
}

else if(right > 40){
lineCar.move(0, 50, 1, 50);
}

else{
lineCar.move(1, 100, 0, 100);
if(middle > 40){
return;
}
}
}

void lineFollower::changeMotors(int multiPins[]){
lineCar.changeMotors(multiPins);
}
