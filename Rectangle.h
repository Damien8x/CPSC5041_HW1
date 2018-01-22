// Author: Damien Sudol
// Filename: Rectangle.h
// Date: 1/19/18
// Package HW1
// Version: 1.0


#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>

using namespace std;

// Description: class designed to meet all expectations laid out in
// HW1. Specifics are laid out below. An object's state is said to
// be "ON" if it has been initalized. Default constructor will 
// put object in an acceptable state but may not produce desireable
// output. 


class Rectangle{

public:

// Rectangle constructor. Initializes width andd length to 0
// precondition: None
// postcondtion: Rectangle creeated and member variable set to 0
Rectangle();

// Rectangle constructor for two integer arguments
// Sets widdth and length to value of respective arguments
// precondition: None
// postcondition: Rectangle created and member variables set to 
// value of respective argument
Rectangle(int, int);

// Sets the value of length variable to integer argument
// precondition: Object is ON
// postcondition: length value may or may not change
void setLength(int);

// Sets the value of width variable to integer argument
// precondtion: Object is ON
// postcondition: width value may or may not change
void setWidth(int);

// returns perimeter value for Rectangle
// precondition: Object is ON
// postcondtion: None
int perimeter() const;

// returns area value for Rectangle
// precondition: Object is ON
// postcondtion: None
int area() const;

// formats and displays width and lenght of Rectangle
// precondtion: Object is ON
// postcondtion: None
void show() const;

// returns 1 if passed object has equal area to current object.
// else, returns 0
// precondition: Both objects are of type Rectangle and  ON
// postcondtion: None 
int sameArea(Rectangle) const;

private:

//private member variables
int length;
int width;

};


#endif
