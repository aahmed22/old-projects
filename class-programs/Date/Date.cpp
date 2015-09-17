//Exercise2 from slide chapter 9_3.
//By AbdulHameed Ahmed.
#include "Date.h"
#include <iostream>
using namespace std;


Date::Date() { }

Date::Date(int m, int d, int y)
{
	setmonth(m);
	setday(d);
	setyear(y);
}

void Date::setmonth(int m)
{
	if(m < 1 || m > 12)
		m = 1;
	month = m;
}

void Date::setday(int d)
{
	if(d < 0)
		d = 1;
	  day = d;
}

void Date::setyear(int y)
{
	if(y < 0 || y > 2012)
		y = 2012;
	    year = y;
}

int Date::getmonth()
{
	return month;
}

int Date::getday()
{
	return day;
}

int Date::getyear()
{
	return year;
}

void Date::displayDate()
{
	cout << getmonth() << '/' << getday() << '/' << getyear() << endl;
}