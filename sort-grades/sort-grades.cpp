/* The following program is design for a user to enter the grades
of 10 students then it will organize the grades and calculate the class average
By Abdulhameed Ahmed. */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int sum = 0;
	int number;
	double average;
	int c[ 10 ];
	for (int i = 0; i < 10; i++ )
	{
		cout << "Please enter the grade for student # " << i + 1 << endl;
		cin >> number;
		c[ i ] = number;
		sum += number;
	}

	cout<<"\n\n\n";
	average = (sum / 10);
	int insert;
	for (int next = 1; next < 10; next++ )
	{
		insert = c[ next ];
		
		int moveItem = next;

		while ( ( moveItem > 0 ) && ( c[ moveItem - 1 ] > insert ))
		{
			c[ moveItem ] = c[ moveItem - 1 ];
			moveItem--;
		}
		c[moveItem]=insert;
	}

	for ( int j = 0; j < 10; j++ )
		cout << c[ j ] << endl;
	cout << "average is: " << average << endl;


return 0;

}
