#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int temp;
	while(b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}


int main()
{
	int x, y;

	cout << "Enter two values:";
	cin >> x >> y;

	cout << "GCD:" << gcd(x,y) << endl;

	return 0;
}