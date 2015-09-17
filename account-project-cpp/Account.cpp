/* MAT 373 Advanced Data Structures
   Project 1: Account Inheritance Hierarchy
   By AbdulHameed Ahmed. */
#include "Account.h"
#include <iostream>
using namespace std;

// The Account class constructor calls the setBalance function to set the balance.
Account::Account( double b )
{
	setBalance( b ); 
}

/* This functions job is to set the balance. Should the balance be negative, set the balance to zero,
   else issue an error message. */
void Account::setBalance( double bal) 
{                                    
	if( bal >= 0 )                  
		balance = bal;
	else
	{
		balance = 0;
		cout << "Error!!! The initial balance was invalid!!!" << endl;
	}
}

// Basically this function adds money to your current balance.
void Account::credit( double amount ) 
{
	balance += amount;
}

/* This function allows the usser to withdraw money. It issues a message whether the transaction
   was successful or not. The reason why the debit function returns a bool is for the debit2 function
   declared inside the seond derived class called CheckingAccount. */
bool Account::debit( double withdraw )
{                                     
	if( withdraw > balance )         
	{                               
		cout << "Debit amount exceeded account balance!" << endl;
	    return false;
	}
	else
	{
		balance -= withdraw;
		cout << "Congratulations!!! Transaction Successful!" << endl;
		return true;
	}
}

/* This function simply returns the balance.
   Accessor functions should be declared const. */
double Account::getBalance() const 
{                                 
	return balance;
}