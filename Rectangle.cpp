#include <iostream>
#include <string>

using namespace std;

class Rectangle{

int length;
int width;
public:
Rectangle(){
length = 0;
width = 0;
}
Rectangle(int length, int width){
this->length = length;
this->width = width;
}

void setLength(int length){
this->length = length;
}

void setWidth(int width){
this->width = width;
}

int perimeter(){
return length*2 + width*2;
}

int area(){
return length*width;
}

void show(){
cout << "Length= " << length << ", Width= " << width;
}

int sameArea(Rectangle obj2){
if (obj2.area() == this->area())
	return 1;
else
	return 0;
}

};

