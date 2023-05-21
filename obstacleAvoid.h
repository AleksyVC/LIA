#ifndef OBSTACLEAVOID_H
#define OBSTACLEAVOID_H

#include <Arduino.h>
#include "motorClass.h"
#include <Servo.h>

class obstacleAvoid {
private:
int trigPin;
int echoPin;
int servo;
float duration;
float distance;
motorClass obstacleCar;
Servo myservo1;//servo for the ultrasonic sensor

public:
obstacleAvoid(){};
obstacleAvoid(int multiPins[]);

void init();
void read();
void changeMotors(int multiPins[]);
void obstacleMove();
};

#endif
