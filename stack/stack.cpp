//=========================================================
// HW#: HW1P1 stack
// Your name: Chris Banci
// Compiler:  g++
// File type: stack implementation file
//=========================================================

#include <iostream>
#include "stack.h"

using namespace std;

// PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{
	top = -1; //stack initiated with top intialized as -1, meaning stack is empty.
}

// PURPOSE: Destructor does not have to do anything since this is a static array.
stack::~stack()
{
}

// PURPOSE:	checks top and returns true if empty, false otherwise.
//			stack is empty when top points to -1
bool stack::isEmpty()
{
	if (top == -1)
		return true;

	else
		return false;
}

// PURPOSE: checks top and returns true if full, false otherwise.
//			stack is full when top points to MAx - 1;
bool stack::isFull()
{
	if (top == MAX - 1)
		return true;

	else
		return false;
}

// PURPOSE: calls isFull and if true, throws an exception (Overflow)
//			Otherwise, adds an element to el after incrementing top.
// PARAMETER: pass the element (elem) to be pushed
void stack::push(el_t elem)
{
	if (isFull()) {
		throw Overflow();
	}

	top++;
	el[top] = elem;
}

// PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//			Otherwise, removes an element from el and gives it back.
// PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{
	if (isEmpty()) {
		throw Underflow();
	}

	elem = el[top];
	top--;
}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//			Otherwise, gives back the top element from el.
// PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{
	if (isEmpty()) {
		throw Underflow();
	}

	elem = el[top];
}

// PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//			Otherwise, diplays the elements vertically.
void stack::displayAll()
{
	if (isEmpty()) {
		cout << "[empty]" << endl;
	}

	for (int i = top; i >= 0; i--) {
		cout << el[i] << endl;
	}

	cout << "--------------" << endl;
}

// PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
	int temp; // temp variable to pop elements from stack.

	while (!isEmpty()) {
		pop(temp);
	}
}
