//===========================================================
// HW#: HW1P1 queue
// Your name: Chris Banci
// Compiler: g++
// File type: queue implementation file
//===========================================================

#include <iostream>
#include "queue.h"

using namespace std;

// PURPOSE: constructor to create an object initalizing front rear and count.
queue::queue()
{
	front = 0; // front points to 0;
	rear = -1; // rear points to -1 in this case.
	count = 0; // empty queue.
}

// PURPOSE: destructor to destroy an object
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
	if (count == 0) {
		return true;
	}

	return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
	if (count == MAX_SIZE) {
		return true;
	}

	return false;
}

// PURPOSE: if full, throws an exception Overflow
//			if not full, enters an element at the rear
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
	if (isFull()) {
		throw Overflow();
	}

	rear = (rear + 1) % MAX_SIZE;
	el[rear] = newElem;
	count++;
}

// PURPOSE: if empty, throw Underflow
//			if not empty, removes the front element to give it back
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
	if (isEmpty()) {

		throw Underflow();
	}

	removedElem = el[front];
	front = (front + 1) % MAX_SIZE;
	count--;

	// if empty, reset front and rear.
	if (count == 0) {
		front = 0;
		rear = -1;
	}
}

// PURPOSE: if empty, throws an exception Underflow
//			if not empty, give back the front element (but does not remove it)
// PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
	if (isEmpty()) {
		throw Underflow();
	}

	theElem = el[front];
}

// PURPOSE: returns the current size to make it accessible to the client caller
int queue::getSize()
{
	return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
	if (count == 0) {
		cout << "[ empty ]";
	}

	else {
		// displays elements in queue.
		// since its possible rear can be behind front, this must be done.
		// [i % MAX_SIZE] is used to wrap around.
		for (int i = front; i < (front + count); i++) {
			cout << "[ " << el[i % MAX_SIZE] << " ]";
		}
	}
}

// PURPOSE: moves front element to the rear.
//			if empty, throws an exception Underflow
//			if queue has just 1 element, does nothing
//			if queue has more than 1 element, moves the front one to the rear by doing remove followed by add.
void queue::goToBack()
{
	if (isEmpty()) {
		throw Underflow(); 
	}

	// if count larger than 1, do remove add operation.
	if (count > 1) {
		el_t tmp; // variable
		remove(tmp);
		add(tmp);
	}
}
