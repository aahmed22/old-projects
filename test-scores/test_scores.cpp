/*This assignment allows the user to enter 3 grades for 10 students,
then it calculates the average of each student as well as the class average.
Alos it assigns a grade letter to each student. Design By Abdulhameed Ahmed */
#include <iostream>
#include <iomanip>
using namespace std; 

int main()
{
	int sum = 0;
	double average;
	int classAvg=0;
	const int students = 10;
	const int tests = 3;

	int c[students][tests];

	

	for (int i = 0; i < students; i++ )
	{	
		for (int j = 0; j < tests; j++ )
		{
			cout << "Please enter the grade for student # " << i + 1 << " Test # " << j + 1<<endl;
			cin >> c[ i ][ j ];
		}
	}
	
	cout<<"Student"<<setw(10)<<"Test #1"<<setw(10)<<"Test #2"<<setw(10)<<"Test #3"<<setw(10)<<"Average"<<setw(10)<<"Grade"<<endl;

	for (int i = 0; i < students; i++ )
	{	
		cout<<setw(4)<<i+1;
		for (int j = 0; j < tests; j++ )
		{
			sum+=c[i][j];
			cout<<setw(10)<<c[i][j];
		}
		
		average=sum/tests;
		classAvg+=average;
		cout<<setw(10)<<average;
		if (average>=90)
			cout<<setw(10)<<'A'<<endl;

		if (average<90&&average>=80)
			cout<<setw(10)<<'B'<<endl;

		if (average<80 && average>=70)
			cout<<setw(10)<<'C'<<endl;

        if (average<70&& average>=60)
			cout<<setw(10)<<'D'<<endl;

		if (average<65)
			cout<<setw(10)<<'F'<<endl;

		sum=0;
	}

	cout<<"Class Average is "<<classAvg/students<<endl;

	return 0;
}
