//PROJECT 2: RATIONAL CLASS
//By AbdulHameed Ahmed.
#include <iostream>
#include "Rational.h" // Header file Rational.
using namespace std;

int main()
{   // Declared four numbers of type integer.
	int number1, number2, number3, number4;

	cout << "Please enter the first numerator:";
	cin >> number1;
	cout << "\nPlease enter the first denominator:";
	cin >> number2;
	while(number2 == 0) // Condition in case the user tries to enter zero as the denominator.
	{
		cout << "ERROR!!!!!!! PLEASE ENTER A NUMBER OTHER THAN ZERO!!!!";
		cin >> number2;
	}

	cout << "\nPlease enter the second numerator:";
	cin >> number3;
	cout << "\nPlease enter the second denominator:";
	cin >> number4;
	while(number4 == 0) // Condition in case the user tries to enter zero as the denominator.
	{
		cout << "ERROR!!!!!! PLEASE ENTER A NUMBER OTHER THAN ZERO!!!!!";
		cin >> number4;
	}

	Rational a(number1, number2); // number1 represents numerator1 and number2 represents denominator1.
	Rational b(number3, number4); // number3 represents numeraotr2 and number4 represents denominator2.
	Rational c, d, e, f; // c, d, e, and f were declared to carry out the the basic arithemitc operations.
	c = a + b; // c contains the addition of the two fractions.
	d = a - b; // d contains the subtraction of the two fractions.
	e = a * b; // e contains the multiplication of the two fractions.
	f = a / b; // f contains the division of the two fractions.

	cout << "\nAddition value: " << c;
	cout << "Addition float-point value: "; 
	c.decimal_print(); // prints the fraction in decimal form.

	cout << "\nSubtraction value: " << d;
	cout << "Subtraction float-point value: ";
	d.decimal_print(); // prints the fraction in decimal form.

	cout << "\nMultiplication value: " << e;
	cout << "Multiplication float-point value: ";
	e.decimal_print(); // prints the fraction in decimal form.

	cout << "\nDivison value: " << f;
	cout << "Divison float-point value: ";
	f.decimal_print(); // prints the fraction in decimal form.
	
	
	return 0;
}