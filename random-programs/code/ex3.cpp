//Exercise 2. from slides chapter 5_1.
//By AbdulHameed Ahmed.
#include <iostream>
using namespace std;

unsigned power(unsigned, unsigned);

int main()
{
	unsigned base;
	unsigned exponent;

	cout << "Enter a number for the base:" << endl;
	cin >> base;
	cout << "Enter a number for the exponent:" << endl;
	cin >> exponent;
	if ((power(base,exponent) == 0))
		cout << "Undefined!!!" << endl;
	else
		cout << "The value is: " << power(base,exponent) << endl;

	return 0;
}

unsigned power(unsigned rbase, unsigned rexponent)
{
	int error = 0;
	int result = 1;

	if ((rbase == 0) && (rexponent == 0))
		return error;
	else if ((rbase != 0) && (rexponent == 0))
		return result;
	else if (rexponent == 1)
		return rbase;
	else
		return rbase * power(rbase, rexponent - 1);
}
