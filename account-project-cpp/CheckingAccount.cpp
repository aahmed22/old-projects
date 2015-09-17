/* MAT 373 Advanced Data Structures
   Project 1: Account Inheritance Hierarchy
   By AbdulHameed Ahmed. */
#include "CheckingAccount.h"
#include <iostream>
using namespace std;

/*The checkingaccount constructor is takes the arguments for the fee and bal, then
  uses the class member initialization list to contact the base class constructor 
  to initialize the balance. The checkingaccount constructor also calls the mutator
  function setFee to set the fee for the checking account. */
CheckingAccount::CheckingAccount( double f, double bal ) : Account( bal )
{
	setFee( f ); 
}

// This function sets the fee.
void CheckingAccount::setFee( double f ) 
{
	fee = f;  
}

// This functions returns the fee.
double CheckingAccount::getFee() const 
{
	return fee;
}

/* The credit2 function is a redefined version of the credit function of the base class.
   The creit2 function works like this, if the user decides to add money to their checking account,
   then the user will get a fee deducted from the current balance and then the amount he wishs to add
   be sent to the current balance. I called the setBalance member function from the base class Account
   so that it can update the balance for the checking account. */
void CheckingAccount::credit2( double amount ) 
{
	double temp;

	if( amount > 0 )
	{
		temp = amount + ( getBalance() - getFee() );
		Account::setBalance( temp );
	}
}

/* The debit2 function is a redefined version of the debit function of the base class. The debit2 function
   works like this, if the user decided to withdraw money from their checking account, I add the fee along 
   with the amount thy want to withdraw a store it in a temp variable. I then call the original debit function
   within the base class Account, to make sure that the amount store in temp does not exceed their current balance
   if the amount exceeds their balance the transaction is considered NOT SUCCESSFUL and will return false to debit2 function.
   However if the amount does not exceed the current balance, then we withdraw the amount from their current balance and return 
   true, displaying a message "Congratulations!!! Transactions Successful!" */
void CheckingAccount::debit2( double amount )
{
	double temp;

	if( amount > 0 )
	{
		temp = amount + getFee();
		if( Account::debit( temp ) );
	}
}