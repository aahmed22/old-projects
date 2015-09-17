//Exercise 5.20...
//By AdbulHameed Ahmed.
#include <iostream>
using namespace std;

bool multiple(int, int);

int main()
{
	int x = 0;
	int y;

	while(x != -1)
	{
		cout << "Enter a number or -1 to quit: ";
		cin >> x;
		cout << "Enter another number:";
		cin >> y;
		cout << endl;
		cout << multiple(x,y) << endl;
	}

	return 0;
}

bool multiple(int a, int b)
{
	if ((b % a) != 0)
		return false;
	else
		return true;
}