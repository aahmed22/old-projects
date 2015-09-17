/* MAT 373 Advanced Data Structures
   Project 1: Account Inheritance Hierarchy
   By AbdulHameed Ahmed. */
#include "SavingAccount.h"

/* The SavingAccount constructor parameter consist of two variables iRate and bal declared of type double.
   bal has a default value of zero, and we use the class member initialization list to contact the base class
   constructor to initialize the balance. The SavingAccount constructor also calls the mutator function 
   setInterestRate to set the interest rate for the saving's account. */
SavingAccount::SavingAccount( double iRate, double bal ) : Account( bal ) 
{  
	setInterestRate( iRate ); 
}

void SavingAccount::setInterestRate( double i )
{
	interestRate = i;
}

/* Accessor functions should be declared const.
   This function returns the interest rate. */
double SavingAccount::getInterestRate() const 
{                                            
	return interestRate;
}

/* Accessor functions should be declared const.
   This function returns the calculateInterest for the saving's account */
double SavingAccount::calculateInterest() const 
{                                              
	return getInterestRate() * getBalance();
}