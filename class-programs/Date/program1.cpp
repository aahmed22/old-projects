//Exercise2 from slide chapter 9_3.
//By AbdulHameed Ahmed.
#include <iostream>
#include "Date.h" //header file Date.
using namespace std;

int main()
{
	Date part1, part2, part3; //par1, part2, and part3 are objects of class type Date.
	int m, d, y;

	cout << "Please enter the month:";
	cin >> m;
	part1.setmonth(m);
	cout << "Please enter the day:";
	cin >> d;
	part2.setday(d);
	cout << "Please enter the year:";
	cin >> y;
	part3.setyear(y);
	cout << endl << endl;
	//Displays month, day and year on a single line.
	cout << part1.getmonth() << '/' << part2.getday() << '/' << part3.getyear() << endl;
	return 0;
}