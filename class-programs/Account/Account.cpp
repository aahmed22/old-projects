#include "Account.h"
#include <iostream>
using namespace std;

Account::Account() {}

Account::Account(double initial)
{
	setAccount(initial);
}

void Account::setAccount(double initial)
{
	if(initial >= 0)
      accountBalance = initial;
   else
     {
        accountBalance = 0;
        cout << "the initial balance is invalid.\n";
     }
}

void Account::credit(double amount)
{
   accountBalance += amount;
}

void Account::debit(double amount)
{

   if(amount < accountBalance)
      accountBalance -= amount;
   else
      cout << "Debit amount exceded balance.\n";
}

double Account::getBalance()
{
   return accountBalance;
}





























/*
Account::Account() { }

Account::Account(int b)
{
	setbalance(b);
}

void Account::setbalance(int b)
{
	if(b < 0)
		b = 0;
	balance = b;
}

void Account::credit(int add_balance)
{
	balance += add_balance;
}

void Account::debit(int amount)
{
	int withdraw = balance - amount;
	if(withdraw > balance)
		amount = balance;
	else
		balance -= withdraw;
	//if((account_balance - withdraw) > account_balance)
		//return account_balance;
	//else
	//return account_balance - withdraw;
}

int Account::getbalance()
{
	return balance;
}
*/