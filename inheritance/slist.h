//=========================================================
// HW#: HW3P2 slist
// Your name: Chris Banci
// Complier:  g++
// File type: slist header file
//===========================================================
#include "llist.h"

// This is a derived class which inherits all member functions
// and data members from the base class llist
class slist : public llist {
	public:
		slist(); // Default constructor for slist.
		int search(el_t Key);            // searches for an element in a linked list.
		void replace(el_t Elem, int I);  // replaces the ith nodes element.
};