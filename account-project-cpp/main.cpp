/* MAT 373 Advanced Data Structures
   Project 1: Account Inheritance Hierarchy
   By AbdulHameed Ahmed. */
#include <iostream>
#include <iomanip>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
using namespace std;

const int OPTION1 = 1, OPTION2 = 2, OPTION3 = 3, OPTION4 = 4, OPTION5 = 5;

int main()
{
	int option;  // Holds the option number.
	double bal;  // Holds the balance.
	double add;  // Holds the amount you want to add to your account.
	double withdraw; // Holds the amount you want to withdraw.
	double iRate;   // Holds the interest rate.
	double charge; // Holds the fee.

	/* This requires the <iomanip> header file. All numbers from this point forward will be 
	   displayed in fixed-point notation with at least two numbers behind the decimal. */
	cout << fixed << setprecision( 2 );

	// THE FOLLOWING CODE BELOW DEALS WITH THE BASE CLASS ACCOUNT.
	cout << "\tWelcome To Your Online Account!!!\n";
	cout << "Please enter a balance for your account: ";
	cin >> bal;

	// Create an object called acc1 of type Account. acc1 sends the value of bal to the Account constructor. 
	Account acc1( bal ); 

	cout << "\n\nPlease Read The Menu Below..." << endl;
	cout << "\n\tMAIN MENU\n\n" << "1. ADD MONEY TO YOUR ACCOUNT\n"
		<< "2. WITHDRAW MONEY FROM YOUR ACCOUNT\n" << "3. DISPLAY BALANCE\n"
		<< "4. QUIT\n\n";

	do
	{
		cout << "\nPlease select an option between 1 - 4: ";
		cin >> option;

		while( option < 1 || option > 4 )
		{
			cout << "Error!!! Select an option between 1 - 4: ";
			cin >> option;
		}

		switch( option )
		{
		   case OPTION1:
			   cout << "How much money do you want to add to your account: ";
			   cin >> add;
			   acc1.credit( add );
			   break;
		   case OPTION2:
			   cout << "How much money do you want to withdraw: ";
			   cin >> withdraw;
			   acc1.debit( withdraw );
			   break;
		   case OPTION3:
			   cout << "Current Balance is $" << acc1.getBalance() << endl << endl;
			   break;
		   case OPTION4:
			   cout << "Ending Phase 1..." << endl;
			   break;
		}
	}while( option != OPTION4 );


	// THE FOLLOWING CODE BELOW DEALS WITH THE FIRST DERIVED CLASS SAVINGACCOUNT.
	cout << "\n\n\tEntering the Saving's Account Mode\n";
	cout << "Enter a balance for your saving's account: ";
	cin >> bal;

	cout << "Enter the interest rate: ";
	cin >> iRate;

	/* Create an object called acc2 of type SavingAccount. acc2 sends the values of 
	   iRate and bal to the constructor of SavingAccount. */
	SavingAccount acc2( iRate, bal );  

	cout << "\nThe Following Will Display Your Online Menu For Your Saving's Account\n\n";
	cout << "1. ADD MONEY TO YOUR ACCOUNT\n" << "2. WITHDRAW MONEY FROM YOUR ACCOUNT\n"
		<< "3. OPTAIN INTEREST RATE FOR SAVING ACCOUNT\n" << "4. DISPLAY BALANCE\n"
		<< "5. QUIT\n\n";

	do
	{
		cout << "\nPlease select an option between 1 - 5: ";
		cin >> option;

		while( option < 1 || option > 5 )
		{
			cout << "Error!!! Select an option between 1 - 5: ";
			cin >> option;
		}

		switch( option )
		{
		case OPTION1:
			cout << "How much money do you want to add to your account: ";
		    cin >> add;
			acc2.credit( add );
			break;
		case OPTION2:
			cout << "How much money do you want to withdraw: ";
			cin >> withdraw;
			acc2.debit( withdraw );
			break;
		case OPTION3:
			cout << "\nHere is interest rate for your savings account: $" <<acc2.calculateInterest() << endl << endl;
			break;
		case OPTION4:
			cout << "Current Balance is $" << acc2.getBalance() << endl << endl;
			break;
		case OPTION5:
			cout << "Ending Phase 2..." << endl;
		}
	}while( option != OPTION5 );

	
	//THE CODE BELOW DEALS WITH THE SECOND DERIVED CLASS CHECKINGACCOUNT.
	cout << "\n\n\tEntering the Checking Account Mode\n";
	cout << "Enter a balance for your checking account: ";
	cin >> bal;

	cout << "Enter the fee amount you will be charged with: ";
	cin >> charge;

	/* acc3 is an object of type CheckingAccount. acc3 sends the value of charge and bal 
	   to the constructor in CheckingAccount. */
	CheckingAccount acc3( charge, bal );

	cout << "\nThe Following Will Display The Online Menu For Your Checking Account\n\n";
	cout << "1. ADD MONEY TO YOUR ACCOUNT\n" << "2. WITHDRAW MONEY FROM YOUR ACCOUNT\n"
		<< "3. DISPLAY BALANCE\n" << "4. QUIT\n\n";

	do
	{
		cout << "\nPlease select an option between 1 - 4: ";
		cin >> option;

		while( option < 1 || option > 4 )
		{
			cout << "Error!!! Select an option between 1 - 4: ";
			cin >> option;
		}

		switch( option )
		{
		   case OPTION1:
			   cout << "How much money do you want to add to your account: ";
			   cin >> add;
			   acc3.credit2( add );
			   break;
		   case OPTION2:
			   cout << "How much money do you want to withdraw: ";
			   cin >> withdraw;
			   acc3.debit2( withdraw );
			   break;
		   case OPTION3:
			   cout << "Current Balance is $" << acc3.getBalance() << endl << endl;
			   break;
		   case OPTION4:
			   cout << "Ending Phase 3..." << endl;
			   break;
		}
	}while( option != OPTION4 );


	cout << "\nTHANK YOU AND ENJOY YOUR DAY!!!\n";

	// The system("pause") is to stop the executable from flashing. 
	system("pause"); 

	return 0;
}