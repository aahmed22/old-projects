/* MAT 373 Advanced Data Structures
   Project 2 
   By AbdulHameed Ahmed. */
#ifndef INTSLLNODE_H
#define INTSLLNODE_H

class IntSLLNode
{
public:
	IntSLLNode();
	IntSLLNode( int el, IntSLLNode* = 0 );
	int info;
	IntSLLNode *next;
};

#endif