#include <iostream>
#include <fstream>
#include <string>
#include "Rectangle.cpp"
using namespace std;

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
Rectangle recArray[5];

cout << STARBREAK << endl << endl;

// welcome message
cout << "******************WELCOME TO RECTANGLE INFO******************" << endl << endl;

// create ofstream object 
ofstream outfile;

// create connection to txt document
outfile.open("lengthwidth.txt");

// collect input from user for 5 Rectangle objects
// add objects to recArray & print input to txt file
for (int i=0; i<SIZE; i++)
{
	cout << "please enter the length of rectangle " <<  i+1  << " as an integer value followed by enter" << endl;
	getline(cin, length);
	cout << "please enter the width of rectangle " << i+1 <<  "  as an integer value followed by enter" << endl;
	getline(cin, width);
	input= length + ", " + width;
	recArray[i] = Rectangle(stoi(length), stoi(width));
	outfile << input <<endl;
}

// close ofstream object
outfile.close();

// method calls for all available methods
printRectangle(recArray);
printLargestArea(recArray);
printSmallestArea(recArray);
printLargestPerimeter(recArray);
printSmallestPerimeter(recArray);
printEqualPerimeter(recArray);
printEqualArea(recArray);

cout << STARBREAK << endl;
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


