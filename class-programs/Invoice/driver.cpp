//Exercise 9.10 from Chapter 9.
//By AbdulHameed Ahmed.
#include <iostream>
#include <string>
#include "Invoice.h"//Header file Invoice.
using namespace std;


int main()
{
	Invoice info1, info2;//info1 and info2 are objects of class type Invoice.
	string string1, string2;
	int q, p;

	cout << "Enter the item number:";
	cin >> string1;
	info1.setNumber(string1);
	cout << "\nEnter a description of the item:";
	cin >> string2;
	info1.setdescription(string2);
	cout << "\nEnter the quantity of the " << string2 << "'s being purchased:";
	cin >> q;
	info2.setquantity(q);
	cout << "\nEnter the price per " << string2 << " :";
	cin >> p;
	info2.setprice(p);
	cout << endl;
	//The following displays all the infomation on the item in the invoice.
	cout << "\nAll details related to the item you got are below:" << endl;
	cout << "Number of the item:" << '\t' << info1.getNumber() << endl;
	cout << "Description of the item:" << '\t' << info1.getdescription() << endl;
	cout << "Quantity of the item:" << '\t' << info2.getquantity() << endl;
	cout << "Price per item:" << '\t' << info2.getprice() << endl;
	cout << "Invoice Amount is:" << '\t' << info2.getInvoiceAmount() << endl;

	return 0;
}