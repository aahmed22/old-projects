//PROJECT 2: RATIONAL CLASS
//By AbdulHameed Ahmed.
#include "Rational.h" // Header file Rational.
#include <iostream>
using namespace std;

Rational::Rational() {}

Rational::Rational(int n = 0, int d = 1)
{
	numerator = n, denominator = d;

	int temp;
	while(d != 0)
	{
	 	temp = n % d;
		n = d;
		d = temp;
	}

	numerator = numerator / n;
	denominator = denominator / n;

}

Rational Rational::operator+(Rational value)
{
	int n,d;
	n = (numerator * value.denominator) + (value.numerator * denominator);
	d = denominator * value.denominator;

	return Rational(n,d);
}

Rational Rational::operator-(Rational value)
{
	int n1, d1;

	n1 = (numerator * value.denominator) - (value.numerator * denominator);
	d1 = denominator * value.denominator;
	
	return Rational(n1, d1);
}

Rational Rational::operator*(Rational value)
{
	int n2, d2;

	n2 = numerator * value.numerator;
	d2 = denominator * value.denominator;

	return Rational(n2, d2);
}

Rational Rational::operator/(Rational value)
{
	int n3, d3;

	n3 = numerator * value.denominator;
	d3 = denominator * value.numerator;

	return Rational(n3, d3);
}

void Rational::decimal_print()
{
	cout << static_cast<double> (numerator)/denominator;
	cout << endl;
}