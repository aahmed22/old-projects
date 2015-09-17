/* MAT 373 Advanced Data Structures
   Project 1: Account Inheritance Hierarchy
   By AbdulHameed Ahmed. */
#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "Account.h"

/* This SavingAccount class is the first derived class
   that inherits from the base class called Account. */
class SavingAccount : public Account 
{                                   
public:
	SavingAccount( double, double = 0 ); // SavingAccount constructor takes in to arguments of type double.
	void setInterestRate( double ); // Mutator function sets the interest rate for the saving's account.
	double getInterestRate() const;  // Accessor Functions should be declared const.
	double calculateInterest() const; // Accessor Functions should be declared const.
private:
	double interestRate;
};

#endif