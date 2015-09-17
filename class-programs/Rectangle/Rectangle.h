//Exercise 9.20: Rectangle Class
//By AbdulHameed Ahmed.

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
	double length, width; // Declare two data members of type double.
public:
	Rectangle(); // Default Constructor
	Rectangle(double, double); // Constructor taking two arguments of type double.
	void setlength(double); // function to set the length.
	void setwidth(double); // function to set width.
	double getlength(); // function to get the length.
	double getwidth(); // function to get the width.
	double getarea(); // function to get the area.
	double getperimeter(); // function to the perimeter.
};

#endif