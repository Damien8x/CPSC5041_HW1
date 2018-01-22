// Author: Damien Sudol
// Filename: Rectangle.cpp
// Date: 1/19/18
// Package: HW1
// Version 1.0

#include <iostream>
#include <string>
#include "Rectangle.h"

int length;
int width;

Rectangle::Rectangle(){
length = 0;
width = 0;
}

Rectangle::Rectangle(int length, int width){
this->length = length;
this->width = width;
}

void Rectangle::setLength(int length){
this->length = length;
}

void Rectangle::setWidth(int width){
this->width = width;
}

int Rectangle::perimeter() const{
return length*2 + width*2;
}

int Rectangle::area() const{
return length*width;
}

void Rectangle::show() const{
cout << "Length= " << length << ", Width= " << width;
}

int Rectangle::sameArea(Rectangle obj2) const{
	if (obj2.area() == this->area())
		return 1;
	else
		return 0;
}



