#ifndef MOTORCLASS_H  // If the "motorClass.h" is not defined
#define MOTORCLASS_H  // Define the "motorClass.h"

#include <Arduino.h>  // Includes the "Arduino" header in the code

class motorClass {  // Creates a class called "PBClass"
private:        
int PWMA;         // Integer motor PWMA
int PWMB;         // Integer motor PWMB
int AIN1;         // Integer motor AIN1
int BIN1;         // Integer motor BIN1
int speed;        // Integer speed

public:                    
motorClass(){};               //constructor
motorClass(int multiPins[]);  //constructor being used

void init();                              //Calls function called "init"
void move(bool a, int x, bool b, int y);  //Calls function called "move" requiring the values a, x, b, and y
void setSpeed(int speed);                 //Calls function called "setSpeed" requiring the value of speed
void forward();                           //Calls function called "forward"
void backward();                          //Calls function called "backward"
void left();                              //Calls function called "left"
void right();                             //Calls function called "right"
void stop();                              //Calls function called "stop"
void boost();                             //Calls function called "boost"
};

#endif  // End the if statement
