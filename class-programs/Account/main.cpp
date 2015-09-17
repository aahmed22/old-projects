//Exercise 9.9 from Chapter 9.
#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
	Account account1; //account2;
	double value1; //value2;

	cout << "Enter your initial balance: ";
	cin >> value1;
	account1.setAccount(value1);

	cout << "Enter some money in your account: ";
	cin >> value1;
	account1.credit(value1);

	cout << "Enter an amount to withdraw from your account: ";
	cin >> value1;
	account1.debit(value1);

	cout << "Balance: " << account1.getBalance();
	cout << endl;
	/*
	Account type1, type2;
	int amount1, amount2, amount3;
	char w, d;

	cout << "Please enter the inital amount you have in your account:";
	cin >> amount1;
	type1.setbalance(amount1);
	if(amount1 < 0)
		cout << "Error: The initial balance was invalid!!!" << endl;
	cout << "Please enter the amount you want to deposit:";
	cin >> amount2;
	type1.credit(amount2);
	cout << "Please enter the amount you want to withdraw:";
	cin >> amount3;
	type2.debit(amount3);
	if(amount3 > amount1)
		cout << "Debit amount exceeds account balance!!!";

	cout << "Initial amount in account was:" << amount1 << endl;
	cout << "Amount deposit in account was:" << amount2 << endl;
	cout << "Amount withdraw from account was:" << amount3 << endl;
	cout << "Current balance is:" << type2.getbalance() << endl;
	*/

}