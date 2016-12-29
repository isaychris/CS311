//=========================================================
// HW#: HW3P3 extended
// Your name: Chris Banci
// Complier:  g++
// File type: slist implementation file
//===========================================================
#include "slist.h"

// PURPOSE: Default constructor for slist.
//		    llist constructor is called automatically to initilize rear, front and count.
//			Nothing to do here.
slist::slist() {
}

// PURPOSE: The copy constructor to allow pass by value and return.
//			The regular copy constructor does not work well with pointers
// PARAMETER: list = a reference that will be copied over to this object.
slist::slist(const slist& list) {

	// because the copy constructor has the same logic as = operation overloading,
	// the = assignment operator can be used to copy the contents of list to this object.
	*this = list;
}

// PURPOSE: searches for an element in a linked list.
// PARAMETER: Key = element to search.
// ALGORITHM: list is traversed until p points to null.
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
// ALGORITHM: list is traversed until pointer points to the ith node.
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

// PURPOSE: This method overloads the = operator. Note that OtherOne is being passed by reference
//			The resulting List will be returned by reference
// PARAMETER: Otherone = elements from this list will be copied over to this object.
// ALOGORHTM: Addresses of this object and other object compared.
//			  if they not the same, copy otherone to this object by first clearing this object, 
//			  then adding elements from other one to this objects list.
slist& slist::operator=(const slist& OtherOne) {
	el_t temp; // variable to hold removed element.

	// the two objects are compared by their addresses.
	// if the two objects are not the same.
	if (&OtherOne != this) {

		// this object needs to be cleared before being elements can be copied over.
		while (!this->isEmpty()) {
			this->deleteRear(temp);
		}

		Node* p = OtherOne.Front;  // local pointer for OtherOne that points to front.

		// this objects list is traveresed to copy elements from otherone.
		while (p != NULL) { 
			this->addRear(p->Elem);    
			p = p->Next;              
		}
	}   

	return *this; 
}


// PURPOSE: Extra credit - This overloads == operator to compare two slist objects.
// PARAMETERS: list1 = the slist object on the left of statement list1 == list2.
//			   list2 = the slist object on the right of statemenet list1 == list2.
// ALGORITHM: If the length of list1 is not the same as the length of list2, return false.
//			  Else, the lengths are the same, so next is to compare each elments of list1 and list2.
//		      If elements do not match, return false. else elements match return true.
bool operator==(const slist& list1, const slist& list2) {	
	// if lengths do not match, return false.
	if (list1.Count != list2.Count) {
		return false;
	}

	Node *p = list1.Front; // p pointing to the front of list1
	Node *q = list2.Front; // q pointing to the front of list2
	
	// list is traversed to find unmatched elements.
	while (p != NULL) {

		// if elements do not match, return false.
		if (p->Elem != q->Elem) {
			return false;
		}

		// update pointers
		p = p->Next;
		q = q->Next;
	}

	// elements do match, so return true.
	return true;
}

