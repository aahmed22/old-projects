//Exercise1 from slide chapter 9_3.
//By AbdulHameed Ahmed.
#include <iostream>
#include <string>
#include "Employee.h"// Header file Employee.
using namespace std;

int main()
{
	string f, l;
	int salary1, salary2;
	Employee worker1, worker2; // worker1 and worker2 are objects of class type Employee.

	cout << "Please enter worker1 first name:";
	cin >> f;
	worker1.setfirstname(f);
	cout << "Please enter worker1 last name:";
	cin >> l;
	worker1.setlastname(l);
	cout << "Enter worker1 monthly salary:";
	cin >> salary1;
	worker1.setsalary(salary1);
	cout << '\n' << worker1.getfirstname() << '\t' << worker1.getlastname() 
		<< '\t' << "monthly salary:" << salary1 << '\t'<< "yearly salary:" << worker1.getsalary() << endl;
	cout << endl;
	cout << "Please enter worker2 first name:";
	cin >> f;
	worker2.setfirstname(f);
	cout << "Please enter worker2 last name:";
	cin >> l;
	worker2.setlastname(l);
	cout << "Enter worker2 monthly salary:";
	cin >> salary2;
	worker2.setsalary(salary2);
	cout << '\n' << worker2.getfirstname() << '\t' << worker2.getlastname()
		<< '\t'<< "monthly salary:" << salary2 << '\t' << "yearly salary:" 
		<< worker2.getsalary() << endl;
	cout << endl;

	//The following line displays worker1 firstname and yearly salary.
	cout << worker1.getfirstname() << "\tyearly salary:" << worker1.getsalary() << endl;
	//The following line displays worker1 firstname and salary raised.
	cout << worker1.getfirstname() << "\traised salary:" << worker1.getsalary_increase() << endl;

	//The following line displays worker 2 firstname and yearly salary.
	cout << worker2.getfirstname() << "\tyearly salary:" << worker2.getsalary() << endl;
	//The following line displays worker2 firstname and salary raised.
	cout << worker2.getfirstname() << "\traised salary:" << worker2.getsalary_increase();
	cout << endl;
	
	return 0;
}