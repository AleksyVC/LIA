#include "motorClass.h"  // Includes the "motorClass" header

//class contructor
motorClass::motorClass(int multiPins[]) {
PWMA = multiPins[0];                     // Gives the value of the integer PWMA the value of the 0th value of multiPins[]
PWMB = multiPins[1];                     // Gives the value of the integer PWMB the value of the 1st value of multiPins[]
AIN1 = multiPins[2];                     // Gives the value of the integer AIN1 the value of the 2nd value of multiPins[]
BIN1 = multiPins[3];                     // Gives the value of the integer BIN1 the value of the 3rd value of multiPins[]
}

void motorClass::init() {  //this function initializes the following pins as OUTPUTS
pinMode(PWMA, OUTPUT);   
pinMode(PWMB, OUTPUT);   
pinMode(AIN1, OUTPUT);   
pinMode(BIN1, OUTPUT);   
pinMode(3, OUTPUT);      //initializes the standby pin
digitalWrite(3, 1);      //turns on the standby pin
}

void motorClass::move(bool a, int x, bool b, int y) {  //this function called "move" asignes variable to each integer
digitalWrite(AIN1, a);                               
analogWrite(PWMA, x);                                
digitalWrite(BIN1, b);                               
analogWrite(PWMB, y);                                
}

void motorClass::setSpeed(int speed) {  //this function allows to control the speed of the car/the motors
this->speed = speed;                  
}

void motorClass::forward() {         //this function makes the car go forward when called
move(1, speed / 2, 1, speed / 2); 
}

void motorClass::backward() {        //this function makes the car reverse when called
move(0, speed / 2, 0, speed / 2);  
}

void motorClass::left() {            //this function makes the car turn left when called
move(1, speed / 3, 0, speed / 3);  
}

void motorClass::right() {           //this function makes the car turn right when called
move(0, speed / 3, 1, speed / 3);  
}

void motorClass::stop() {  //this function makes the car stop/the motors stop when it is called
move(0, 0, 0, 0); 
}

void motorClass::boost(){
move(1,speed,1,speed);
}
