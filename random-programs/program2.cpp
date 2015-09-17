//Exercise 5.18...
//By AbdulHameed Ahmed.
#include <iostream>
using namespace std;

int integerPower(int, int);

int main()
{
	int base;
	int exponent;

	cout << "Enter base:";
	cin >> base;
	cout << "Enter exponent:";
	cin >> exponent;

	cout << "The value is:" << integerPower(base,exponent) << endl;

	return 0;
}

int integerPower(int rbase, int rexponent)
{
	int result = 1;
	
	for(int i = 1; i <= rexponent; i++)
		result *= rbase;

	return result;
}