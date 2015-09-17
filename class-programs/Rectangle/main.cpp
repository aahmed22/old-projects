//Exercise 9.20: Rectangle Class
//By AbdulHameed Ahmed.
#include <iostream>
#include "Rectangle.h" // Header file Rectangle
using namespace std;

int main()
{
	Rectangle set1; // set1 is an object of class Rectangle
	double l, w; // Declared two varibles of type double.

	cout << "Please enter the length for the rectangle: ";
	cin >> l; // l represents length of the rectangle.
	set1.setlength(l); // set length of the class Rectangle.
	cout << "Please enter the width for the rectangle: ";
	cin >> w; // w represents width of the rectangle.
	set1.setwidth(w); // set width to the class Rectangle.
	
	cout << "Area of Rectangle: ";
	cout << set1.getarea() << endl; // Result of the area.
	cout << "Perimeter of Rectangle:";
	cout << set1.getperimeter() << endl; // Result of the perimeter.

	
	return 0;
}