//Exercise 9.20: Rectangle Class
//By AbdulHameed Ahmed.
#include "Rectangle.h" // Header file Rectangle
#include <iostream>
using namespace std;

Rectangle::Rectangle() {}

Rectangle::Rectangle(double l = 1, double w = 1)
{
	setlength(l);
	setwidth(w);
}

void Rectangle::setlength(double l)
{
	while(l < 0 || l > 20)
	{
		cout << "Please enter a number greater than zero and less than twenty!!!!";
		cin >> l;
	}
	length = l;
}

void Rectangle::setwidth(double w)
{
	while( w < 0 || w > 20)
	{
		cout << "Please enter a number greater than zero and less than twenty!!!!";
		cin >> w;
	}
	width = w;
}

double Rectangle::getlength()
{
	return length;
}

double Rectangle::getwidth()
{
	return width;
}

double Rectangle::getarea()
{
	return length * width;
}

double Rectangle::getperimeter()
{
	return (length * length) + (width * width);
}