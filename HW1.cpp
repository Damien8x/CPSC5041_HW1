// Author: Damien Sudol
// Filename: HW1.cpp
// Date: 1/19/18
// Package HW1
// Version: 1.0

#include <iostream>
#include <fstream>
#include <string>
#include "Rectangle.h"
using namespace std;

// Description: Driver designed to test full functionality of program set forth in the
// guidelines of HW1. All public methods of Rectangle.h will be tested in to fulfill
// the intedned functionality of the program. Program must store an array of 5 Rectangle 
// objects. Each Rectangle must remain distinct and access all available public functions.
// This class has been highly modularized into seven methods for functional decomposition.
// All method descriptions are provided below.
//
// Assumptions: Testing of all possible state transitions and limits 
// which have been thourougly tested will not appear in this driver. Driver WILL
// accept user data and will NOT be hard coded to be recognized as a deployable ready to
// use program. Program is intended to function as a container of a static number of
// Rectangle objects, 5. 

// method prototypes
void printRectangle(Rectangle recArray[]);
void printLargestArea(Rectangle recArray[]);
void printSmallestArea(Rectangle recArray[]);
void printLargestPerimeter(Rectangle recArray[]);
void printSmallestPerimeter(Rectangle recArray[]);
void printEqualPerimeter(Rectangle recArray[]);
void printEqualArea(Rectangle recArray[]);

// global constant for recArray size
int SIZE = 5;
string STARBREAK =
 "******************************************************************************************************";

int main(){

// main method variables
string length = "";
string width = "";
string input = "";
Rectangle recArray[SIZE];


// welcome message
cout << endl << endl <<
 "************************************~~WELCOME TO RECTANGLE INFO~~*************************************"
 << endl << endl << endl
<< "Program is designed to store the length and width of five rectangles, after which the area and" 
<< endl << "perimeter will be displayed for all rectangles, followed by the rectangle with the greatest"
<< endl << "area, greatest perimeter, smallest area, smallest perimeter, all Rectangles with values matching"
<< endl << "the greatest perimeter and greatest area. More details can be found in README.txt" << endl << endl <<
 "Your entries will be saved to the file: lengthwidth.txt. " << endl << endl<< "Hope You Enjoy" << endl
<< endl << endl << STARBREAK << endl << endl;
    

// create ofstream object 
ofstream outfile;

// create connection to txt document
outfile.open("lengthwidth.txt");

// collect input from user for 5 Rectangle objects
// add objects to recArray & print input to txt file
// if non- integer values are entered for either width or length program
// will continue to loop for given Rectangle until a proper value is given
for (int i=0; i<SIZE; i++)
{
	string loopOn = "yes";
	while(loopOn == "yes"){
	try{
	cout << "please enter the length of rectangle " <<  i+1  << " as an integer value followed by enter" << endl;
	getline(cin, length);
	cout << "please enter the width of rectangle " << i+1 <<  "  as an integer value followed by enter" << endl;
	getline(cin, width);
	recArray[i] = Rectangle(stoi(length), stoi(width));
	loopOn  = "no";
	} catch(const std::exception& e){ cout <<" ENTER PROPER INTEGER VALUE" << endl;
	loopOn = "yes";}
	}
	input= length + ", " + width;
	outfile << input <<endl;
}

// close ofstream object
outfile.close();

cout << STARBREAK << endl << endl;

// method calls for all available methods
printRectangle(recArray);
printLargestArea(recArray);
printSmallestArea(recArray);
printLargestPerimeter(recArray);
printSmallestPerimeter(recArray);
printEqualPerimeter(recArray);
printEqualArea(recArray);
return 0;
};

// method formats and prints width, length, area, and perimeter
// for all Rectangles in recArray
void printRectangle(Rectangle recArray[]){

for (int i=0; i<SIZE; i++){
	cout << "Rectangle " << (i+1) << ": ";  recArray[i].show(); 
	cout << ", Area= " << recArray[i].area()
	<< ", Perimeter= " << recArray[i].perimeter()  << endl << endl;
}
};

// method prints the Rectangle in recArray with the largest
// area. If multiple Rectangles share the max area
// the Rectangle with the lowest index will be displayed
void printLargestArea(Rectangle recArray[]){

int rectangle = 0;
int area = recArray[0].area();
for (int i=1; i<SIZE; i++){
	if(recArray[i].area() > area){
		area = recArray[i].area();
		rectangle = i;
	}
}
cout << "Rectangle with the largest area: Rectangle " << rectangle + 1 << ", "; recArray[rectangle].show();
cout << ", Area= " << area << ", Perimeter= " << recArray[rectangle].perimeter() << endl <<endl;
};

// method prints the Rectangle in recArray with the smallest
// area. If multiple Rectangles share the min area
// the Rectangle with the lowest index will be displayed
void printSmallestArea(Rectangle recArray[]){

int rectangle = 0;
int area = recArray[0].area();
for (int i=1; i<SIZE; i++){
	if(recArray[i].area() < area){
		area = recArray[i].area();
		rectangle = i;
	}
}
cout << "Rectangle with the smallest area: Rectangle " << rectangle + 1 << ", "; recArray[rectangle].show();
cout << ", Area= " << area << ", Perimeter= " <<  recArray[rectangle].perimeter() << endl << endl;
};

// method prints the Rectangle in recArray with the largest
// perimeter. If multiple Rectangles share the max perimeter
// the Rectangle with the lowest index will be displayed.
void printLargestPerimeter(Rectangle recArray[]){

int rectangle = 0;
int perimeter = recArray[0].perimeter();

for (int i=1; i<SIZE; i++){
	if(recArray[i].perimeter() >  perimeter){
		perimeter = recArray[i].perimeter();
		rectangle = i;
	}
}
cout << "Rectangle with the largest perimeter: Rectangle " << rectangle + 1 << ", "; recArray[rectangle].show();
cout << ", Area= " << recArray[rectangle].area() << ", Perimeter= " << perimeter << endl << endl;
};

// method prints the Rectangle in recArray with the smallest
// perimeter. If multiple Rectangles share the min perimeter
// the Rectangle with  the lowest index will be displayed.
void printSmallestPerimeter(Rectangle recArray[]){

int rectangle = 0;
int perimeter = recArray[0].perimeter();

for (int i=1; i<SIZE; i++){
	if(recArray[i].perimeter() < perimeter){
		perimeter = recArray[i].perimeter();
		rectangle = i;
	}
}
cout << "Rectangle with the smallest perimeter: Rectangle " << rectangle + 1 << ", "; recArray[rectangle].show();
cout << ", Area= " << recArray[rectangle].area() << ", Perimeter= " << perimeter << endl << endl;
};

// method prints all Rectangles in recArray which share the maximum area.
// If no Rectangles share the max area a message will display saying so.
void printEqualArea(Rectangle recArray[]){

int rectangle = 0;
int area = recArray[0].area();
int count = 0;

for (int i=1; i<SIZE; i++){
	if(recArray[i].area() > area){
		area = recArray[i].area();
		rectangle = i;
	}
}
for (int i=0; i<SIZE; i++){
	if(recArray[i].area() == area)
		count++;
}

if (count < 2){
	cout << "No rectangles with an equal area found." << endl << endl;
}
else{
	cout << "Rectangles: ";
		for (int i = 0; i<SIZE; i++){
			if(recArray[i].area() == area && count >1){
					cout << i << ", ";
					count--;
			}else{
				if(recArray[i].area() == area)
					cout << i;
			}
		}
	cout << " have equal areas of " << area << " units each." << endl << endl;
		

}
};

// method prints all Rectangles in recArray which share the maximum perimeter.
// If no Rectangles share the max perimeter will display saying so.
void printEqualPerimeter(Rectangle recArray[]){

int rectangle = 0;
int perimeter = recArray[0].perimeter();
int count = 0;

for (int i=1; i<SIZE; i++){
	if(recArray[i].perimeter() > perimeter){
		perimeter  = recArray[i].perimeter();
		rectangle = i;
	}
}
for (int i=0; i<SIZE; i++){
	if(recArray[i].perimeter() == perimeter)
		count++;
}

if (count < 2){
	cout << "No rectangles with an equal perimeter found." << endl << endl;
}
else{
	cout << "Rectangles: ";
		for (int i = 0; i<SIZE; i++){
			if(recArray[i].perimeter() == perimeter && count >1){
					cout << i << ", ";
					count--;
			}else{
				if(recArray[i].perimeter() == perimeter)
					cout << i;
			}
		}
cout << " have equal perimeters of " << perimeter << " units each." << endl << endl;
}
};


