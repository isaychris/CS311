//=======================================================
// HW#: HW1P2 vector
// Your name: Chris Banci
// Compiler:  g++
// File type: vstack header file
//=======================================================

#include <vector>

using namespace std;

//----- Globally setting up the aliases ----------------

typedef int el_t;    // the el_t type is int for now
					 // el_t is unknown to the client

//-------------------------------------------------------


class vstack {
private:
	vector <el_t>    el;     // el is vector of el_t's (ints).
	int      top;           // top is index to the top of stack

public:
	vstack();   // constructor to create an object.
	~vstack();  // destructor  to destroy an object.  vector function clear() is called to deallocate memory.

	// exception class cases.
	class Overflow {};   // thrown when the stack overflows
	class Underflow {};  // thrown when the stack underflows

	// PURPOSE: if not full, enters an element at the top;
	//          otherwise throws an exception - Overflow
	// PARAMETER: pass the element to be pushed
	void push(el_t&);

	// PURPOSE: if not empty, removes and gives back the top element;
	//          otherwise throws an exception - Underflow
	// PARAMETER: provide variable to receive the popped element (pass by ref)
	void pop(el_t&);

	// PURPOSE: if not empty, gives the top element without removing it;
	//          otherwise, throws an exception - Underflow
	// PARAMETER: provide variable to receive the top element (pass by ref)
	void topElem(el_t&);

	// PURPOSE:	checks top and returns true if empty, false otherwise.
	//			stack is empty when top points to -1
	bool isEmpty();

	// PURPOSE: for stacks: checks top and returns true if full, false otherwise.
	//			stack is full when top points to MAx - 1;
	//			for vectors: it always returns false.
	bool isFull();

	// PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
	//			Otherwise, diplays the elements vertically.
	void displayAll();

	// PURPOSE: removes all elements from the vector which are then destroyed.
	void clearIt();
};
