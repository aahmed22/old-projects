/* MAT 373 Advanced Data Structures
   Project 2
   By AbdulHameed Ahmed. */
#include <iostream>
#include "IntSLList.h"
using namespace std;

int main()
{
    // list1 and list2 are objects of type IntSLList.
	// number1 and number2 are of type int and initialize to zero.
	IntSLList list1, list2;
	int number1 = 0, number2 = 0;
	
	//Entering values for list1.
	while(number1 != -1)
	{
		cout << "Enter as many numbers as you want into list1. (Enter -1 to quit): ";
		cin >> number1;
		
		if(number1 == -1)
		   break;
	
		list1.addToTail(number1);
	}
	
	cout << "\nDisplaying list1: ";
	list1.printAll();

	// Using listCount member function.
	cout << "\nThe current number of nodes in list1 is: " << list1.listCount() << endl;

	//Now test running the frequency member function.
	cout << "\n\nEnter a number to test it's frequency in the list: ";
	cin >> number1;
	list1.frequency(number1);

	// Using reverse member function.
	cout << "\n\nNow displaying list1 in reverse order: " << endl;
	list1.reverse();
	
	//Using the multiply member function.
	cout << "\n\nEnter a number to multiply the list: ";
	cin >> number1;
	list1.multiply(number1);
	
	//Using the sort member function. 
	cout << "\n\nEnter either 0 or 1 to sort list1: ";
	cin >> number1; 
	//Set a condition in case the user enters an invalid number.
	while(number1 < 0 || number1 > 1)
	{
		cout << "Error!!! Enter either 0 or 1 to sort: ";
		cin >> number1;
	}
	list1.sortList(number1);
	cout << "Displaying newly sorted list1: ";
	list1.printAll();
	
	cout << endl << endl;

	//Now entering values for list2.
	while(number2 != -1)
	{
		cout << "Enter as many numbers as you want into list2. (Enter -1 to quit): ";
		cin >> number2;
		
		if(number2 == -1)
			break;
		
		list2.addToTail(number2);
	}
	// Using appendList member function.
	list1.appendList(list2);
	
	//Using removeNodes member function.
	cout << "\n\nEnter the range of nodes you want to delete: ";
	cin >> number1 >> number2;
	list1.removeNodes(number1, number2); 
	
	cout << "\nCurrent list1 node count is: " << list1.listCount() << endl;
	cout << "\nNow displaying updated list1: ";
	list1.printAll();
	
	//Using the deleteAll member function.
	cout << "\n\nNow deleting all nodes inside list1..." << endl;
	list1.deleteAll();
	
	cout << "\n\nlist1 final node count is: " << list1.listCount() << endl;
	
	
	system("pause");
	return 0;
}