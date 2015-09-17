#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
public:
	Account();
	Account(double);
	void setAccount(double);
	void credit(double);
	void debit(double);
	double getBalance();
private:
	double accountBalance;
};

#endif


