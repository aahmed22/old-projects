//Exercise1 from slide chapter 9_3.
//By AbdulHameed Ahmed.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
public:
	Employee(); //default constructor to declare objects worker1 and worker2 in main.cpp
	Employee(string, string, int); //constructor to intialize values for three data members.
	void setfirstname(string); //function to set the firstname.
	void setlastname(string); //function to set the lastname.
	void setsalary(int); //function to set the salary.
	string getfirstname(); //function to retrieve the firstname.
	string getlastname(); //function to retrieve the lastname.
	int getsalary(); //function to retrieve the salary.
	double getsalary_increase(); //function to retrieve the salary raise.
private: //Declared three data members;
	string firstname;
	string lastname;
	int monthly_salary;
	
};

#endif