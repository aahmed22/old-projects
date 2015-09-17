//PROJECT 2: RATIONAL CLASS
//By AbdulHameed Ahmed.
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational 
{
	/* Overloading the insertion stream ( << ) operator and using friend to access
	Rational class private data members*/
	friend ostream & operator<<(ostream & output, Rational & print)
	{
		output << print.numerator << "/" << print.denominator << endl;
		return output;
	}

public:
	Rational(); // Default Constructor.
	Rational(int, int); //Constructor for class Rational.
	Rational operator+(Rational); // Overloading the + operator.
	Rational operator-(Rational); // Overloading the - operator.
	Rational operator*(Rational); // Overlaoding the * operator.
	Rational operator/(Rational); // Overlaoding the / operator.
	void decimal_print(); // function to print the fraction in decimal point value.
private:
	int numerator, denominator; // Declare two data member of type int.
};

#endif