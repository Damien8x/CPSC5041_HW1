#include <iostream>
#include <fstream>
#include <string>
#include "Rectangle.cpp"
using namespace std;

void printRectangle(Rectangle recArray[]);
void printLargestArea(Rectangle recArray[]);
void printSmallestArea(Rectangle recArray[]);
void printLargestPerimeter(Rectangle recArray[]);
void printSmallestPerimeter(Rectangle recArray[]);
void printEqualPerimeter(Rectangle recArray[]);
void printEqualArea(Rectangle recArray[]);

int main(){




string length = "";
string width = "";
string input = "";

Rectangle recArray[5];
cout << "Thanks for using rectangle Calculator. Please Enter integer values for length and width.:" << endl << endl;

 
ofstream outfile;
outfile.open("lengthwidth.txt");
for (int i=0; i<5; i++)
{
cout << "please enter the length of rectangle " <<  i+1  << " followed by enter" << endl;
getline(cin, length);

cout << "please enter the width of rectangle " << i+1 <<  " followed by enter" << endl;
getline(cin, width);
input= length + ", " + width;
recArray[i] = Rectangle(stoi(length), stoi(width));
outfile << input <<endl;
}
printRectangle(recArray);

printLargestArea(recArray);


printSmallestArea(recArray);
printLargestPerimeter(recArray);
printSmallestPerimeter(recArray);
printEqualPerimeter(recArray);
printEqualArea(recArray);



return 0;


};

void printRectangle(Rectangle recArray[]){
for (int i=0; i<5; i++){

cout << "Rectangle " << (i+1) << ": ";  recArray[i].show(); 
cout << ", Area= " << recArray[i].area()
<< ", Perimeter= " << recArray[i].perimeter()  << endl;
}
};

void printLargestArea(Rectangle recArray[]){
int rectangle = 0;
int area = recArray[0].area();

for (int i=1; i<5; i++){
	if(recArray[i].area() > area){
	area = recArray[i].area();
	rectangle = i;
	}
}
cout << "Rectangle with the largest area: Rectangle " << rectangle + 1 << " "; recArray[rectangle].show();
cout << ", Area= " << area << ", Perimeter= " << recArray[rectangle].perimeter() << endl;
};

void printSmallestArea(Rectangle recArray[]){
int rectangle = 0;
int area = recArray[0].area();

for (int i=1; i<5; i++){
	if(recArray[i].area() < area){
	area = recArray[i].area();
	rectangle = i;
	}
}
cout << "Rectangle with the smallest area: Rectangle " << rectangle + 1 << " "; recArray[rectangle].show();
cout << ", Area= " << area << ", Perimeter= " <<  recArray[rectangle].perimeter() << endl;

};

void printLargestPerimeter(Rectangle recArray[]){
int rectangle = 0;
int perimeter = recArray[0].perimeter();

for (int i=1; i<5; i++){
	if(recArray[i].perimeter() >  perimeter){
	perimeter = recArray[i].perimeter();
	rectangle = i;
	}
}
cout << "Rectangle with the smallest perimeter: Rectangle " << rectangle + 1 << " "; recArray[rectangle].show();
cout << ", Area= " << recArray[rectangle].area() << ", Perimeter= " << perimeter << endl;


};

void printSmallestPerimeter(Rectangle recArray[]){
int rectangle = 0;
int perimeter = recArray[0].perimeter();

for (int i=1; i<5; i++){
	if(recArray[i].perimeter() < perimeter){
	perimeter = recArray[i].perimeter();
	rectangle = i;
	}
}
cout << "Rectangle with the largest perimeter: Rectangle " << rectangle + 1 << " "; recArray[rectangle].show();
cout << ", Area= " << recArray[rectangle].area() << ", Perimeter= " << perimeter << endl;


};

void printEqualArea(Rectangle recArray[]){
int rectangle = 0;
int area = recArray[0].area();
int count = 0;

for (int i=1; i<5; i++){
	if(recArray[i].area() > area){
	area = recArray[i].area();
	rectangle = i;
	}
}
for (int i=0; i<5; i++){
	if(recArray[i].area() == area)
		count++;
}

if (count < 1){

cout << "No rectangles have equal area found." << endl;
}
else{
cout << "Rectangles: ";
	for (int i = 0; i<5; i++){
		if(recArray[i].area() == area)
			cout << i << ", ";
	}
cout << " have equal areas of " << area << " units each." << endl;
		

}
};

void printEqualPerimeter(Rectangle recArray[]){
int rectangle = 0;
int perimeter = recArray[0].perimeter();
int count = 0;

for (int i=1; i<5; i++){
	if(recArray[i].perimeter() > perimeter){
	perimeter  = recArray[i].perimeter();
	rectangle = i;
	}
}
for (int i=0; i<5; i++){
	if(recArray[i].perimeter() == perimeter)
		count++;
}

if (count < 1){

cout << "No rectangles have equal perimeter found." << endl;
}
else{
cout << "Rectangles: ";
	for (int i  = 0; i<5; i++){
		if(recArray[i].perimeter() == perimeter)
			cout << i << ", ";
	}
cout << " have equal perimeters of " << perimeter << " units each." << endl;
	
}
};


