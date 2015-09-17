/* MAT 373 Advanced Data Structures
   Project 2 
   By AbdulHameed Ahmed. */
#include "IntSLList.h"
#include <iostream>
using namespace std;

IntSLList::IntSLList()
{
	head = tail = 0;
}

IntSLList::~IntSLList() 
{
    for (IntSLLNode *p; !isEmpty(); ) 
	{
        p = head->next;
        delete head;
        head = p;
    }
}

int IntSLList::isEmpty()
{
	return head == 0;
}

void IntSLList::addToHead(int el) 
{
    head = new IntSLLNode(el,head);
    if (tail == 0)
       tail = head;
}

void IntSLList::addToTail(int el) 
{
    if (tail != 0) {      // if list not empty;
         tail->next = new IntSLLNode(el);
         tail = tail->next;
    }
    else head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead() 
{
    int el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail)     // if only one node on the list;
         head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}

int IntSLList::deleteFromTail() 
{
    int el = tail->info;
    if (head == tail) 
	{   // if only one node on the list;
         delete head;
         head = tail = 0;
    }
    else 
	{                // if more than one node in the list,
         IntSLLNode *tmp; // find the predecessor of tail;
         for (tmp = head; tmp->next != tail; tmp = tmp->next);
         delete tail;
         tail = tmp;      // the predecessor of tail becomes tail;
         tail->next = 0;
    }
    return el;
}

void IntSLList::deleteNode(int el) 
{
    if (head != 0)                     // if non-empty list;
         if (head == tail && el == head->info) 
		 { // if only one
              delete head;                       // node on the list;
              head = tail = 0;
         }
         else if (el == head->info) 
		 {  // if more than one node on the list
              IntSLLNode *tmp = head;
              head = head->next;
              delete tmp;              // and old head is deleted;
         }
         else 
		 {                        // if more than one node in the list
              IntSLLNode *pred, *tmp;
              for (pred = head, tmp = head->next; // and a non-head node
                   tmp != 0 && !(tmp->info == el);// is deleted;
                   pred = pred->next, tmp = tmp->next);
              if (tmp != 0) 
			  {
                   pred->next = tmp->next;
                   if (tmp == tail)
                      tail = pred;
                   delete tmp;
              }
         }
}

bool IntSLList::isInList(int el) const 
{
    IntSLLNode *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}

void IntSLList::printAll() const 
{
    for (IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next)
        cout << tmp->info << " ";
	cout << endl;
}


//Functions that I implemented and added to the already existing class IntSLList...

/* The reverse function takes in no arguments. It simply prints the current list in reverse order.
   It traverses the list to find the last node, once it does that it prints the content inside the last
   node, then has that node point to end, then we execute the while condtion again this time, traversing
   to the new last node, onces it reaches its destination it will print the content inside the new last
   node. This process will contiinue until we finally reach the head node and print its content. */
void IntSLList::reverse()
{
	if( head == 0 )
		cout << "ERROR!!! THE LIST DOES NOT EXIST!\n";
	else
	{
		IntSLLNode *end = tail->next;
		
		while( end != head )
		{
			IntSLLNode *current = head;
			while( current->next != end )
			current = current->next;

			cout << current->info << " ";
			end = current;
		}
	}
}


/* This function simply takes and integer value and literally multiplies all of the content
   inside the list by that value, then prints the output. */
void IntSLList::multiply(int el)
{
  IntSLLNode *tmp;

  for( tmp = head; tmp != 0; tmp = tmp->next )
     cout << ( tmp->info * el ) << " ";

  cout << endl;
}

/* The frequency function takes in an interger arguments, and finds out how many times the
   argument appear inside the list, then prints the result. */
void IntSLList::frequency( int el )
{
  int counter = 0;

  if( head == 0 )
      cout << "ERROR!!! THE LIST DOES NOT EXIST!!!\n";
  else
  {
    IntSLLNode *tmp = head;

    while( tmp != 0 )
	{
         if( el == tmp->info )
			 counter++;

		 tmp = tmp->next;
	}

     cout << el << " appears " << counter << " times in the list!\n";
  }
}

// The listCount member function simply returns the number of node inside the current singly linked list.
int IntSLList::listCount()
{
   IntSLLNode *tmp;

   int count = 0;

   for(tmp = head; tmp != 0; tmp = tmp->next)
	   count++;

   return count;
}

/* The sortList functions takes in a integer value, of either 0 or 1. If you want to sort the list
   in ascending order then enter the value 0. However if you want to sort the list in descending order then 
   enter the value 1. For this sort function, I've decided to use the bubble sort algorithm because it is
   the simplest to implement. */
void IntSLList::sortList(int el)
{
	if( head == 0 )
		cout << "CANNOT SORT AN EMPTY LIST!!!\n";

	if(el == 0)
	{
		IntSLLNode *tmp = head;
		int holder = listCount();
		int temp;
		
		for(int j = 0; j < holder; j++)
		{
			while(tmp->next)
			{
				if(tmp->info > tmp->next->info)
				{
					temp = tmp->info;
					tmp->info = tmp->next->info;
					tmp->next->info = temp;
					tmp = tmp->next;
				}
				else
					tmp = tmp->next;
			}
			tmp = head;
		}
	}

	if(el == 1)
    {
		IntSLLNode *tmp = head;
		int holder = listCount();
		int temp;
		
		for(int j = 0; j < holder; j++)
		{
			while(tmp->next)
			{
				if(tmp->info < tmp->next->info)
				{
					temp = tmp->info;
					tmp->info = tmp->next->info;
					tmp->next->info = temp;
					tmp = tmp->next;
				}
				else
					tmp = tmp->next;
			}
			tmp = head;
		}
	}
}


//The deleteAll function simply delete's all the nodes inside the list.
void IntSLList::deleteAll()
{
	if(head == 0)
		cout << "ERROR!!! LIST1 IS EMPTY!\n";
	else if(head == tail)
	{
		IntSLLNode *tmp = head;
		head = tail = 0;
		delete tmp;
	}
	else
	{
		IntSLLNode *temp, *temp2;
		temp = head;
		while(temp != 0)
		{
			head = head->next;
			temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
	}
}

/* The appendList function takes an object of IntSLList as an argument in the parameter.
   In order the for the appending of the list to be permanent we must use pass by reference
   using the & operator. It first checks to see if both list1 and list2 are empty. If they
   are then print an error message.If list1 is empty we print and error message and display
   the current list 2. If list2 happens to be empty then we print a error message and display 
   the current list1 content, this indicates that NOTHING was appended. Finally if the first 
   two conditions fail, then we execute the else which simply takes the head of the second 
   list and appends it to the tail of the first list. We keep looping until all nodes of the 
   second list are appended to the first list.*/
void IntSLList::appendList(IntSLList &L2)
{
	
	
	if(head == 0 && L2.head == 0)
		cout << "ERROR!!! Both List1 and list 2 are empty!!!\n";
	else if(head == 0)
	{
		cout << "Error!!! Cannot append because list1 is empty!\n";
		cout << "Display2: ";
		L2.printAll();
	}
	else if(L2.head == 0)
	{
		cout << "Error!!! Cannot append because list2 is empty!\n";
		cout << "Display list1: ";
		printAll();
	}
	else
	{
		while(L2.head != 0)
		{
			tail->next = L2.head;
			tail = tail->next;
			L2.head = L2.head->next;
		}
		L2.head = 0;

		cout << "\nNow list1 contains: ";
		printAll();

		cout << "\nlist2 Node Count: " << L2.listCount() << endl;
	} 
}

/* The function removeNodes takes in two integer arguments. The objective
   of this function is to delete a range of nodes, starting from position
   n through the last position k. We first set an if condition to make sure
   the list is not empty, if it is we issue an error message. The else condition
   will execute if the list is not empty. We set a condition to make sure both n 
   and k are the correct values for this operation to be successful.
   Finally we create 3 pointers of type IntSLLNode. The first for loop
   tries to find a position before the nth node. we set an if condition
   assuming the user wants to remove the first node within his range. The
   second for loop determines the range between n and k and begin to delete
   all nodes from n to k. */
void IntSLList::removeNodes(int n, int k)
{
	if(head == 0)
		cout << "Error!!! Cannot use the function \"removeNodes\" because list1 is empty!!!\n";
	else
	{
		while(n > k || k < n || n < 1 || k > listCount() || n == k )
		{
			cout << "Error!!! Re-enter the values: ";
			cin >> n >> k;
		}
		
		IntSLLNode *start = head, *current, *removal;
		
		for(int i = 0; i < n - 2; i++)
			start = start->next;
		
		if(n == 1)	
			removal = start;
		else 
			removal=start->next;

		current = removal->next;
	
		for(int i = 0; i < k - n; i++)
		{
			delete removal;
			removal = current;
			current = current->next;
		}
		
		delete removal;
		
		if(n == 1)
		{
			head = current;
			start = NULL;
		}
		else 
			start->next = current;

		current = NULL;
		removal = NULL;
	}
}