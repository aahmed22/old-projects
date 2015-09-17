/* MAT 373 Advanced Data Structures
   Project 1: Account Inheritance Hierarchy
   By AbdulHameed Ahmed. */
#ifndef ACCOUNT_H
#define ACCOUNT_H

// This Account class is the base class for this application.
class Account  
{
public:
	Account( double = 0 ); // Set the default value of balance to zero.
	void setBalance( double ); // This mutator function sets the balance.
	void credit( double ); // This functions allows you to add money to your account.
	bool debit( double ); // This function allows you to withdraw money from your account.
	double getBalance() const; // Accessor Functions should be declared const.
private:
	double balance;
};

#endif