//Exercise 5.13...
//By AbdulHameed Ahmed.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x = 0;
	double z = 0.5;
    double y;

	while(x != -1)
	{
		cout << "Enter a number or -1 to quit:";
		cin >> x;
		y = floor(x+z);
		cout << "x:" << x << "\ty:" << y << endl;
	}
	
	return 0;
}