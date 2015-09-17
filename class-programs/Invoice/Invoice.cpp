//Exercise 9.10 from Chapter 9.
//By AbdulHameed Ahmed.
#include "Invoice.h"//Header file Invoice.

Invoice::Invoice() { }

Invoice::Invoice(string n, string d, int qitem, int pitem)
{
	setNumber(n);
	setdescription(d);
	setquantity(qitem);
	setprice(pitem);
}

void Invoice::setNumber(string n)
{
	number = n;
}

string Invoice::getNumber()
{
	return number;
}

void Invoice::setdescription(string d)
{
	description = d;
}

string Invoice::getdescription()
{
	return description;
}

void Invoice::setquantity(int qitem)
{
	if(qitem < 0)
		qitem = 0;
	quantity_item = qitem;
}

int Invoice::getquantity()
{
	return quantity_item;
}

void Invoice::setprice(int pitem)
{
	if(pitem < 0)
		pitem = 0;
	price_pitem = pitem;
}

int Invoice::getprice()
{
	return price_pitem;
}

int Invoice::getInvoiceAmount()
{
	return getquantity() * getprice();
}