//Exercise 5.27...
//By AbdulHameed Ahmed.
#include <iostream>
using namespace std;

template <class T>
T smallest(T value1, T value2, T value3)
{
	T smallestValue = value1;
	if(value2 < smallestValue)
		smallestValue = value2;

	if(value3 < smallestValue)
		smallestValue = value3;

	return smallestValue;
}
int main()
{
	double double1, double2, double3;
	
	
	cout << "Enter three double values: ";
	cin >> double1 >> double2 >> double3;

	cout << "The smallest double value is: "
		<< smallest(double1,double2,double3) << endl;

	float float1, float2, float3;
    cout << "\nEnter three floating-point numbers: ";
	cin >> float1 >> float2 >> float3;

	cout << "The smallest float value is: " << smallest(float1, float2, float3) << endl;
	

	return 0;
}