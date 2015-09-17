//Exercise 5.27...
//By AbdulHameed Ahmed.
#include <iostream>
#include "minimum.h"
using namespace std;

int main()
{
	double double1, double2, double3;
	
	
	cout << "Enter three double values: ";
	cin >> double1 >> double2 >> double3;

	cout << "The smallest double value is: "
		<< minimum(double1,double2,double3) << endl;

	float float1, float2, float3;
    cout << "\nEnter three floating-point numbers: ";
	cin >> float1 >> float2 >> float3;

	cout << "The smallest float value is: " << minimum(float1, float2, float3) << endl;
	
	return 0;
}
