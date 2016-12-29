//=========================================================
// HW#: HW3P3 extended
// Your name: Chris Banci
// Complier:  g++
// File type: slist header file
//===========================================================
#include "llist.h"

// This is a derived class which inherits all member functions
// and data members from the base class llist
class slist : public llist {
public:

	// constructors
	slist(); // Default constructor for slist.
	slist(const slist&); // The copy constructor to allow pass by value and return.

	// functions
	int search(el_t Key);            // searches for an element in a linked list.
	void replace(el_t Elem, int I);  // replaces the ith nodes element.

	// operation overloading
	slist& operator=(const slist&);  // This overloads the = operator to make slist object asignment work.
	friend bool operator==(const slist&, const slist&); // Extra credit - This overloads == operator to compare two slist objects.
};