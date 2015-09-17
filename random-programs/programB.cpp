//Exercise 5.17 Part B...
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
	int c[arraySize] = {3,5,7,9,11};

	cout << c[(rand() % arraySize)] << endl;

	
	return 0;
}