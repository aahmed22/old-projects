//Exercise 9.14: Complex Class
//By AbdulHameed Ahmed.
#include "Complex.h"

Complex::Complex() {}

Complex::Complex(double r = 0, double i = 0)
{
	rnumber = r;
	inumber = i;
}

Complex Complex::operator+(Complex temp)
{
	double r1, i1;

	r1 = (rnumber + temp.rnumber);
	i1 = (inumber + temp.inumber);

	return Complex(r1, i1);
}

Complex Complex::operator-(Complex temp)
{
	double r2, i2;

	r2 = (rnumber - temp.rnumber);
	i2 = (inumber - temp.inumber);

	return Complex (r2, i2);
}