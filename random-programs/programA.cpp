//Exercise 5.17 Part A...
//By AbdulHameed Ahmed.
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	const int arraySize = 5;
	int c[arraySize] = {2,4,6,8,10};

	cout << c[(rand() % arraySize)] << endl;

	return 0;
}