/* MAT 373 Advanced Data Structures
   Project 1: Account Inheritance Hierarchy
   By AbdulHameed Ahmed. */
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

/* The CheckingAccount is the second derived class
   that inherits from the base class Account. */
class CheckingAccount : public Account 
{                                     
public:
	CheckingAccount( double, double ); // CheckingAccount constructor takes in two arguments of type double.
	void setFee( double ); // Mutator function sets the fee for the checking account.
	double getFee() const; // Accessor Functions should be declared const.
	void credit2( double ); // Redefined credit member function from the base class.
	void debit2( double ); // Redefined debit member function from the base class.
private:
	double fee;
};

#endif