//Exercise 9.14: Complex Class
//By AbdulHameed Ahmed.
#include <iostream>
#include "Complex.h" // Header file Complex
using namespace std;

int main()
{   // Declared four variables of type integer.
	int r1, r2, i1, i2;

	cout << "Enter the first r number:";
	cin >> r1; // r1 represents real number1.

	cout << "Enter the first i number:";
	cin >> i1; // i1 represents imaginary number1.

	cout << "Enter the second r number:";
	cin >> r2; // r2 represents real number2.

	cout << "Enter the second i number:";
	cin >> i2; // i2 represents imaginary number2.

	Complex a(r1, i1); // a contains both real number1 and imaginary number1.
	Complex b(r2, i2); // b contains both real number2 and imaginary number2.
	Complex c, d;

	c = a + b; // c contains the sum of both real numbers and imaginary numbers.
	d = a - b; // d contains the difference of both real numbers and imaginary numbers.

	// The following contains the sum and difference of complex numbers in a + bi form.
	cout << "(" << r1 << "+" << i1 << "i" << ")" << " + " << "(" << r2 << "+" << i2 << "i" << ")";
	cout << " = " << c;
	cout << "(" << r1 << "-" << i1 << "i" << ")" << " - " << "(" << r2 << "-" << i2 << "i" << ")";
	cout << " = " << d;

	
	return 0;
}