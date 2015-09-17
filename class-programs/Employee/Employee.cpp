//Exercise1 from slide chapter 9_3.
//By AbdulHameed Ahmed.
#include "Employee.h" //Header file Employee.
//#include <string>

Employee::Employee() { }

Employee::Employee(string first, string last, int salary)
{
	setfirstname(first);
	setlastname(last);
	setsalary(salary);
}

void Employee::setfirstname(string first)
{
	firstname = first;
}

string Employee::getfirstname()
{
	return firstname;
}

void Employee::setlastname(string last)
{
	lastname = last;
}

string Employee::getlastname()
{
	return lastname;
}

void Employee::setsalary(int salary)
{
	monthly_salary = salary;
	if(monthly_salary < 0)
		monthly_salary = 0;
}

int Employee::getsalary()
{
	return monthly_salary * 12;
}

double Employee::getsalary_increase()
{
	double raise = 0.1;
	return (monthly_salary * 12)  + ((monthly_salary * 12) * raise);
}