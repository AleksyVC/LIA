#ifndef LINEFOLLOWER_H
#define LINEFOLLOWER_H

#include <Arduino.h>
#include "motorClass.h"

class LineFollower{
private:
int leftPin;
int middlePin;
int rightPin;
int left;
int middle;
int right;
int motorPins;
motorClass lineCar;

public:
LineFollower(){};
LineFollower(int multiPins[]);

void lineFollow();
void lineMove();
void changeMotors(int multiPins[]);
void whatTrack();
}

#endif
