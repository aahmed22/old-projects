//Exercise 1. From the slides chapter 5_1.
//By AbdulHameed Ahmed.
#include <iostream>
using namespace std;

double diameter(double);

double circumference(double);

double area(double);

int main()
{
	double radius = 0;

	cout << "Please enter the radius of the circle: ";
	cin >> radius;

	cout << "Diameter is: " << diameter(radius) << endl;
	cout << "Circumference is: " << circumference(radius) << endl;
	cout << "Area is: " << area(radius) << endl;
    
	
	return 0;
}

double diameter(double a)
{
	return 2 * a;
}

double circumference(double b)
{
	double diameter = 2 * b;
	return (3.14 * diameter);
}

double area(double c)
{
	return (3.14 * c * c);
}
