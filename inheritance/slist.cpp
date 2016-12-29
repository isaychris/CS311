//=========================================================
// HW#: HW3P2 slist
// Your name: Chris Banci
// Complier:  g++
// File type: slist implementation file
//===========================================================
#include "slist.h"

// PURPOSE: Default constructor for slist.
// llist constructor is called automatically to initilize rear, front and count.
// Nothing to do here.
slist::slist() {
}

// PURPOSE: searches for an element in a linked list.
// PARAMETER: Key = element to search.
// Algorithm: list is traversed until p points to null.
//			  If the node's element pointed by p equals to key,
//			  search was successful, so return its position
//			  If not, search was not sucess, so return -1;
int slist::search(el_t Key) {
	Node *p = Front;   // set a pointer to front.
	int position = 1;  // current position.

	// traversed list until p points to null.
	while (p != NULL) {
		// if current nodes element equals key, return the position.
		if (p->Elem == Key) {
			return position;
		}
		p = p->Next;
		position++;
	}

	//  else, key was not found, so return 0.
	return 0;
}

// PURPOSE: replaces the ith nodes element.
// PARAMETER: Elem = ith nodes element is replaced with this variable.
//			  I = ith node in the list.
// Algorithm: list is traversed until pointer points to the ith node.
//			  The nodes element is then replaced with Elem.
void slist::replace(el_t Elem, int I) {
	Node *p = Front;   // set a pointer to front.
	int position = 1;  // current position

	// if I is greater Count OR I is less than 1,
	// then I is out of bounds. throw exception.
	if (I > Count || I < 1) {
		throw OutOfRange();
	}

	// traverse list until current position equals I.
	// when while loops breaks, p now points to Ith node.
	while (position != I) {
		p = p->Next;

		position++;
	}

	cout << " - Element " << p->Elem << " replaced with " << Elem << endl;
	p->Elem = Elem;  // p's element replaced by elem.
}