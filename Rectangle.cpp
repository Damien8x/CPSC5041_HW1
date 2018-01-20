#include <iostream>
#include <string>
using namespace std;

class Rectangle{

// private member variables
int length;
int width;
public:
// public Rectangle constructor. sets member variables to 0
Rectangle(){
length = 0;
width = 0;
}
// two argument, integer constructor. sets member variables to corresponding arguments
Rectangle(int length, int width){
this->length = length;
this->width = width;
}

// method sets value of length member variable
void setLength(int length){
this->length = length;
}

// method sets value of width member variable
void setWidth(int width){
this->width = width;
}

// method returns perimeter of Rectangle object
int perimeter(){
return length*2 + width*2;
}

// methodd returns area of Rectangle object
int area(){
return length*width;
}

// method formats and prints length and width of Rectangle object
void show(){
cout << "Length= " << length << ", Width= " << width;
}

// method returns true if passed objects area is equal to this Rectangles area
int sameArea(Rectangle obj2){
	if (obj2.area() == this->area())
		return 1;
	else
		return 0;
}

};

