/* MAT 373 Advanced Data Structures
   Project 2 
   By AbdulHameed Ahmed. */
#include "IntSLLNode.h"

IntSLLNode::IntSLLNode()
{
	next = 0;
}

IntSLLNode::IntSLLNode( int el, IntSLLNode *ptr )
{
	info = el;
	next = ptr;
}