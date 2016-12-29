// ====================================================
// HW#: HW3P1 llist
// Your name: Chris Banci
// Compiler:  g++
// File type: llist implementation file
//=====================================================
using namespace std;

#include <iostream>
#include "llist.h" 

// PURPOSE: Default constructor for llist. Front & Rear intialized to NULL, and Count set to 0.
llist::llist() {
	Front = NULL;
	Rear = NULL;
	Count = 0;
}

// PURPOSE: Deconstructor for llist. List is cleared by deleting elements from the front until list is empty.
llist::~llist() {
	el_t temp; // variable to hold deleted nodes element.

	cout << "~ Calling the llist deconstructor ~" << endl;
	
	//while not empty, delete from front.
	while (!isEmpty()) {
		deleteFront(temp);
	}

	cout << "=====================================" << endl << endl;
}

// PURPOSE: This checks if the link list is empty or not.
bool llist::isEmpty() {
	// if front equals null and rear equals null and count equals 0, list is empty, return true
	if ((Front == NULL) && (Rear == NULL) && (Count == 0)) {
		return true;
	}
	
	//else list is not empty, return false.
	else {
		return false;
	}
}


// PURPOSE: This displays all the nodes in a link list.
// ALGORITHM: if list is empty, print empty. if not, traverse list by using while loop,
//			  where while pointer does not point to null, print element, then update pointer
//			  to point to next node.
void llist::displayAll() {
	Node *p = Front; // pointer to traverse list.

	//if list empty, show empty.
	if (isEmpty()) {
		cout << " - [ empty ]" << endl;
	}

	//if list is not empty.
	else {
		cout << " - ";

		//traverse list until p is null and print.
		while (p != NULL) {
			cout << "[ " << p->Elem << " ]";

			p = p->Next;
		}
		cout << endl;
	}
}

// PURPOSE: This adds a new node to the front of the linked list.
// PARAMETER: NewNum = element to assign to  the new node.
// ALGORITHM: Two cases need to be checked.
//		- 1) Special case: 
//				if this is going to be the very first node, you must
//				create a new node and make Front and Rear point to it.
//				place NewNum and Count is updated.
//		- 2) Regular: 
//				add a new node to the front of the list and Count is updated.
void llist::addFront(el_t NewNum) {

	// 1) special case
	// new node created, then element is set. front and rear points to mynode.
	// lastly rear points to null.
	if (Count == 0) {
		Node *mynode = new Node; // creates new node
		mynode->Elem = NewNum;
		Front = mynode;
		Rear = mynode;
		Rear->Next = NULL;
		Count++;
	}

	// 2) regular case
	// new node created, then element is set. mynode next set to front, then front points mynode.
	else {
		Node *mynode = new Node; // creates new node
		mynode->Elem = NewNum;
		mynode->Next = Front;
		Front = mynode;
		Count++;
	}
}

// PURPOSE: This adds a new node to the rear of the linked list.
// PARAMETER: NewNum = element to assign to the new node.
// ALGORITHM: Two cases need to be checked.
//		- 1) Special case: if this is going to be the very first node, you must
//				create a new node and make Front and Rear point to it.
//				Place NewNum and Count is updated.
//		- 2) Regular : 
//				adds a new node at the rear and puts NewNum in the Elem field
//				of this new node. Count is updated.
void llist::addRear(el_t NewNum) {
	// 1) special case
	// new node called mynode is created then its element is set.
	// front and rear pointed to my node. then rear next points to null.
	if (Count == 0) {
		Node *mynode = new Node; // creates new node.
		mynode->Elem = NewNum;
		Front = mynode;
		Rear = mynode;
		Rear->Next = NULL;
		Count++;
	}

	// 2) regular case
	// new node called mynode is created then its element is set.
	// rear next points to mynode. rear points to my node, then rear next point to null.
	else {
		Node *mynode = new Node; // creates new node.
		mynode->Elem = NewNum;
		Rear->Next = mynode;
		Rear = mynode;
		Rear->Next = NULL;
		Count++;
	}
}

// PURPOSE: This deletes a node in front of the linked list.
// PARAMETER: OldNum = variable to hold deleted nodes element.
// ALGORITHM: Three cases need to be checked.
//		- 1) Error case: 
//				if the List is empty, throw Underflow
//		- 2) Special case: 
//				if currently only one Node, give back the front node element through 
//				OldNum(pass by reference) and make sure both Front and Rear become NULL. 
//				Count is updated.
//		- 3)Regular : 
//				give back the front node element through OldNum(pass by reference)
//				and also removes the front node.Count is updated.
void llist::deleteFront(el_t& OldNum) {
	// 1) error case
	// if empty, throw underflow.
	if (isEmpty()) {
		throw Underflow();
	}
	
	// 2) special case
	// fronts element held in oldNum varaible. then front is deleted.
	// front and rear set to null.
	else if (Count == 1) {
		OldNum = Front->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}

	// 3) regular case
	// fronts element held in OldNum variable.
	// second points to node next to front and front is deleted.
	// second is now the front.
	else {
		OldNum = Front->Elem;
		Node* second = Front->Next; // pointer points to node after front.
		delete Front;
		Front = second;
		Count--;
	}
}

// PURPOSE: This deletes a node at the rear of a linked list.
// PARAMETER: OldNum = variable to hold deleted nodes element.
// ALGORITHM: Three cases must be checked.
//		- 1) Error case: 
//				if empty, throw Underflow
//		- 2) Special case:
//				if currently only one node, give back the rear node element through 
//				OldNum(pass by reference) and make sure both Front and Rear become NULL.
//				Count is updated.
//		- 3) Regular: 
//				give back the rear node element through OldNum(pass by reference)
//				and also remove the rear node. Count is updated.
void llist::deleteRear(el_t& OldNum) {
	// 1) error case
	// if empty throw underflow
	if (isEmpty()) {
		throw Underflow();
	}

	// 2) special case
	// OldNum holds rears element, then rear is deleted.
	// front and rear set to null.
	else if (Count == 1) {
		OldNum = Rear->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}

	// 3) regular case
	// OldNum holds rears element. new pointer p points to front.
	// list is traversed to point to node before rear. rear is then deleted.
	// rear is set to bide before rear. rear next is set to point to null.
	else {
		OldNum = Rear->Elem;
		Node *p = Front; // pointer to traverse list.

		// loop to point to node before rear.
		while (p->Next != Rear) {
			p = p->Next;
		}

		delete Rear;
		Rear = p;
		Rear->Next = NULL;
		Count--;
	}
}

// PURPOSE: This deletes a node at the ith position in the linked list.
// PARAMETER: OldNum = variable to hold deleted nodes element.
//			  I = position to delete node.
// ALGORITHM: Four cases must be checked. 
//		- 1) Error case:
//				If I is an illegal value(i.e. > Count or < 1) throw OutOfRange.
//		- 2) Special cases: 
//				this should simply call deleteFront when I is 1.
//		- 3) Special cases: 
//				this should simply call deleteRear when I is Count.
//		- 3) Regular: 
//				delete the Ith node(I starts out at 1).Count is updated.
void llist::deleteIth(int I, el_t& OldNum) {
	// 1) error case
	// if out of range, throw outofrange.
	if (I > Count || I < 1) {
		throw OutOfRange();
	}

	// 2) special case
	// if I equals 1, call deleteFront.
	else if (I == 1) {
		deleteFront(OldNum);
	}

	// 3) special case
	// if I equal Count, call deleteRear.
	else if (I == Count) {
		deleteRear(OldNum);
	}

	// 4) regular case
	// loop is used to point to ith node and get lag pointer.
	// node before p is lag pointer. lag pointer set to point to the node next to p.
	// Oldnum holds p's element, then p is deleted.
	else {
		Node *p = Front; // lead pointer to traverse list
		Node *lag = new Node; //lag pointer

		// loop to point to ith node.
		for(int k = 1; k <= I - 1; k++)
		{
			lag = p;
			p = p->Next;
		}

		lag->Next = p->Next;
		OldNum = p->Elem;
		delete p;
		Count--;
	}
}
// PURPOSE: This adds a node before the ith position in the linked list.
// PARAMETER: newNum = element to assign to the new node.
//			  I = position to add new node.
// ALGORITHM: Four cases much be checked.
//		- 1) Error case:
//				If I is an illegal value(i.e. > Count + 1 or < 1) throw OutOfRange.
//		- 2) Special cases:
//				this should simply call addFront when I is 1.
//		- 3) Special cases:
//				this should simply call addRear when I is Count + 1.
//		- 4) Regular : 
//				add right before the Ith node. Cout if updated.
void llist::addbeforeIth(int I, el_t newNum) {
	// 1) error case
	// if out of range, throw outofrange.
	if (I > Count + 1 || I < 1) {
		throw OutOfRange();
	}

	// 2) special case
	// if I equals 1, call addFront.
	else if (I == 1) {
		addFront(newNum);
	}

	// 3) special case
	// if I equals count + 1, call addRear.
	else if (I == Count + 1) {
		addRear(newNum);
	}

	// 4) regular case
	// lead and lag pointer created. loo is used to point to the node before Ith.
	// lag next set to point to new node. new nodes element set to newNum.
	// then new node next points to p.
	else {
		Node *myNode = new Node; // new node to add
		Node *p = Front; // lead pointer to traverse list
		Node *lag = new Node; // lag pointer

		//loop to point to the node before I
		for (int k = 1; k <= I - 1; k++)
		{
			lag = p;
			p = p->Next;
		}

		lag->Next = myNode;
		myNode->Elem = newNum;
		myNode->Next = p;
		Count++;
	}
}