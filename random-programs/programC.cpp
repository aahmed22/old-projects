//Exercise 5.17 Part C...
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
	int c[arraySize] = {6,10,14,18,22};

	cout << c[(rand() % arraySize)] << endl;

	
	return 0;
}
