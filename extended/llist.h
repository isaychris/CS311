// ====================================================
// HW#: HW3P1 llist
// Your name: Chris Banci
// Compiler:  g++
// File type: llist header file
//=====================================================
#include <iostream>
using namespace std;

typedef int el_t; // typedef called el_t set to int.

				  // list node is defined here as a struct Node
struct Node
{
	el_t Elem;   // elem is the element stored
	Node *Next;  // next is the pointer to the next node
};

// I could have done class Node and add the data members under public
// but it will use too much space
class llist
{
protected:
	Node *Front;       // front  pointer 
	Node *Rear;        // rear   pointer
	int  Count;        // counter for the number of elements

public:
	class Underflow {};	// exception when underflow.
	class OutOfRange {}; // exception when out ofrange.

	llist(); // default constructor  
	~llist(); // destructor

			  // This checks if the link list is empty or not.
	bool isEmpty();

	// This displays all the nodes in a link list.
	void displayAll();

	// This adds a new node to the front of the linked list.
	void addFront(el_t NewNum);

	// This adds a new node to the rear of the linked list.
	void addRear(el_t NewNum);

	// Purpose: This deletes a node in front of the linked list.
	void deleteFront(el_t& OldNum);

	// This deletes a node at the rear of a linked list.
	void deleteRear(el_t& OldNum);

	// This deletes a node at the ith position in the linked list.
	void deleteIth(int I, el_t& OldNum);

	// This adds a node before the ith position in the linked list.
	void addbeforeIth(int I, el_t newNum);

};