/* 
   MAT 373 Advanced Data Structures
   Project 5
   By AbdulHameed Ahmed.
*/
#include "genBST.h"
#include <iostream>

using namespace std;

int main()
{
	BST<int> tree;
	int number = 0;

	while(number != -1)
	{
		cout << "Enter a value to store in the tree or (-1 to quit): ";
		cin >> number;

		if(number == -1)
			break;

		tree.insert(number);
	}


	cout << "\n\n\nThe tree currently contains: ";
	for(int i = 0; i < 100; i++)
	{
		int *ptr = tree.search(i);
		if(ptr != 0)
		{
			cout << i << " ";
		}
	}

	cout << "\n\n\nThe number of nodes in the tree is: " << tree.nodeCount() << endl;
	cout << "\nThe number of leaves in the tree is: " << tree.leaveCount() << endl;
	cout << "\nDisplaying the mirror of the tree: ";
	tree.mirrorImage();
	cout << endl;
	
	system("pause");
	return 0;
} 