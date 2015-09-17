/* MAT 373 Advanced Data Structures
   Project 2 
   By AbdulHameed Ahmed. */
#ifndef INTSLLIST_H
#define INTSLLIST_H

#include "IntSLLNode.h"

class IntSLList
{
public:
	IntSLList();
	~IntSLList();
	int isEmpty();
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead(); // delete the head and return its info;
	int deleteFromTail(); // delete the tail and return its info;
	void deleteNode(int);
	bool isInList(int) const;
	void printAll() const;
	// Functions that I implemented.
	void reverse(); // This function reverses the singly linked list.
	void multiply(int); // This function takes an integer value and multiplies all the content inside the list.
	void frequency(int); // This function takes and intger value and finds out how many times it appears inside the list.
	int listCount(); // This function returns the number of nodes that exists inside the list.
	void sortList(int); // This function sorts the singly linked list.
	void deleteAll(); // This function delete's all nodes inside the list.
	void appendList(IntSLList &); // This function appends the second list to the first one.
	void removeNodes(int, int); // This function remove a range of nodes.
private:
	IntSLLNode *head, *tail;
};

#endif

