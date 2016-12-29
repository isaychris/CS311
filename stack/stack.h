//=======================================================
// HW#: HW1P1 stack
// Your name: Chris Banci
// Compiler:  g++
// File type: stack header file
//=======================================================

//----- Globally setting up the aliases ----------------
const int MAX = 10;   // The MAX number of elements for the stack
					  // MAX is unknown to the client

typedef int el_t;     // the el_t type is int for now
					  // el_t is unknown to the client
//-------------------------------------------------------

class stack {
private: 
	el_t     el[MAX];       // el is  an array of el_t's
	int      top;           // top is index to the top of stack

public:
	stack();   // constructor to create an object
	~stack();  // destructor  to destroy an object

	// exception class cases.
	class Overflow {};   // thrown when the stack overflows
	class Underflow {};  // thrown when the stack underflows

	// PURPOSE: if not full, enters an element at the top;
	//          otherwise throws an exception - Overflow
	// PARAMETER: pass the element to be pushed
	void push(el_t);

	// PURPOSE: if not empty, removes and gives back the top element;
	//          otherwise throws an exception - Underflow
	// PARAMETER: provide variable to receive the popped element (pass by ref)
	void pop(el_t&);

	// PURPOSE: if not empty, gives the top element without removing it;
	//          otherwise, throws an exception - Underflow
	// PARAMETER: ***
	void topElem(el_t&);

	// PURPOSE:	checks top and returns true if empty, false otherwise.
	//			stack is empty when top points to -1
	bool isEmpty();

	// PURPOSE: checks top and returns true if full, false otherwise.
	//			stack is full when top points to MAx - 1;
	bool isFull();

	// PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
	//			Otherwise, diplays the elements vertically.
	void displayAll();

	// PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
	void clearIt();
};
