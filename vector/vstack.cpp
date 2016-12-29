//=========================================================
// HW#: HW1P2 vector
// Your name: Chris Banci
// Compiler:  g++
// File type: vstack implementation file
//=========================================================

#include <iostream>
#include "vstack.h"

using namespace std;

// PURPOSE:  Constructor must initialize top to be -1 to begin with.
vstack::vstack()
{
	top = -1; //stack initiated with top intialized as -1, meaning stack is empty.
}

// PURPOSE: Dellocates memory by calling vector function clear().
vstack::~vstack()
{
	el.clear();
}

// PURPOSE:	checks top and returns true if empty, false otherwise.
//			stack is empty when top points to -1
bool vstack::isEmpty()
{
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

// PURPOSE: for stacks: checks top and returns true if full, false otherwise.
//			stack is full when top points to MAx - 1;
//			for vectors: it always returns false.
bool vstack::isFull()
{
	return false;
}

// PURPOSE: calls isFull and if true, throws an exception (Overflow)
//			Otherwise, adds an element to el after incrementing top.
// PARAMETER: pass the element (elem) to be pushed
void vstack::push(el_t& elem)
{
	top++;
	el.push_back(elem);
}

// PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//			Otherwise, removes an element from el and gives it back.
// PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void vstack::pop(el_t& elem)
{
	if (isEmpty()) {
		throw Underflow();
	}

	elem = el.at(el.size() - 1);
	el.pop_back();
	top--;
}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//			Otherwise, gives back the top element from el.
// PARAMETER: provide a holder (elem) for the element (pass by ref)
void vstack::topElem(el_t& elem)
{
	if (isEmpty()) {
		throw Underflow();
	}

	elem = el.size() - 1;
}

// PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//			Otherwise, diplays the elements vertically.
void vstack::displayAll()
{
	if (isEmpty()) {
		cout << "[empty]" << endl;
	}

	for (int i = top; i >= 0; i--) {
		cout << el.at(i) << endl;
	}

	cout << "--------------" << endl;
}

// PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
void vstack::clearIt()
{
	int temp; // temp variable to pop elements from stack.

	while (!isEmpty()) {
		el.pop_back();
	}
}
