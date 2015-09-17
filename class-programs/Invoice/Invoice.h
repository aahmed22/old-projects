//Exercise 9.10 from Chapter 9
//By AbdulHameed Ahmed.
#ifndef INVOICE_H
#define INVOICE_H
#include <string>
using namespace std;

class Invoice
{

	private://Declare four data members.
	string number;
	string description;
	int quantity_item;
	int price_pitem;
public:
	Invoice();//Default Constructor.
	Invoice(string, string, int, int);//Constructor for assigning values to the four data members.
	void setNumber(string);//set the item number.
	string getNumber();//get the item number.
	void setdescription(string);//set the description for the item.
	string getdescription();//retrieves the description for the item.
	void setquantity(int);//set the quantity of the item.
	int getquantity();//get the quantity of the item.
	void setprice(int);//set the price per item.
	int getprice();//get the price for the item.
	int getInvoiceAmount();//get the invoice amount for the item.
};




#endif