//Exercise 9.14: Complex Class
//By AbdulHameed Ahmed.
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{ 
private:
	double rnumber, inumber; // Declared two data members of type double.
public:
	Complex(); // Default Constructor.
	Complex(double, double); // Constructor taking two arguments of type double.
	Complex operator+(Complex); // Overloading the + operator.
	Complex operator-(Complex); // Overloading the - operator.
	/* Overlaoding the stream insertion ( << ) operator to print the Complex number
	in a + bi form.*/
	friend ostream & operator<<(ostream & output, Complex & print)
	{
		output << print.rnumber << "+" << print.inumber << "i" << endl;
		return output;
	}
};


#endif