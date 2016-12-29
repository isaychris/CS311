// ===============================================================
// HW#: HW5 heap
// Your name: Chris Banci
// Complier:  g++
// File type: heap implementation & client file.
//================================================================
#include "hw5.h"

// PURPOSE:	Constructor which copies array contents into a vector and heapifies it.
// PARAMETER: array = the array to turn to heap.
//			  length = size of the heap.
// ALGORITHM: Using a for-loop, contents in arraylist are copied into vector.
MinHeap::MinHeap(int* array, int length) : _vector(length) { 

	// copies contents of array to vector.
	for (int i = 0; i < length; ++i) {
		_vector[i] = array[i];
	}

	Heapify(); 										// makes sure each node has the heap property.
}

// PURPOSE:	Constructor which heapifies vector
// PARAMETER: vector = vector to turn into heap.
// ALGORITHM: Heapified using heapify function.
MinHeap::MinHeap(const vector<int>& vector) : _vector(vector) {
	Heapify(); 										// makes sure each node has the heap property.
}

// PURPOSE: Default constructor.
MinHeap::MinHeap() {
}

// PURPOSE:	Heapifies vector by making sure each node has heap property.
// ALGORITHM: To heapify, each node in the tree is bubbled down to corrent position using bubbledown() function.
void MinHeap::Heapify() {

	/////////////////////////////////////

	// bubble down each node to correct position.
	for (int i = _vector.size() - 1; i >= 0; --i) {
		BubbleDown(i);
	}

}

// PURPOSE: Bubbles down the node to correct position in the tree using recursion.
// PARAMETER: index = node at [index] to bubble down.
// ALGORITHM: A node in the heap is bubbled down to correct position by comparing
//			  the left and right child of the vertex at [index]. 
//			  If leftchild or right child is smaller than value at index, swap places.
//			  This is done to each node
void MinHeap::BubbleDown(int index) {
	int length = _vector.size();					// size of vector
	int leftChildIndex = 2 * index + 1;				// the left child index.
	int rightChildIndex = 2 * index + 2;			// the right child index.

	// if the left child at index is greater than the size of vector..
	if (leftChildIndex >= length)
		return;										// index is a leaf

	int minIndex = index;							// the smaller node.

	// if node at [index] is greater than the node at [index] left child
	if (_vector[index] > _vector[leftChildIndex]) {
		minIndex = leftChildIndex;					// the smaller node is the left child.
	}

	// if the right child at [index] is less than vector size
	// and the node at [minindex] is greater than the right child node of [index]
	if ((rightChildIndex < length) && (_vector[minIndex] > _vector[rightChildIndex])) {
		minIndex = rightChildIndex;					// the smaller node is the rightchild.
	}

	// if minIndex is not equal to index, then swap because minIndex is smaller.
	if (minIndex != index) {
		//need to swap
		////////////////////////////////////

		int temp = _vector[index];					// temp variable to hold value at index
		_vector[index] = _vector[minIndex];			// set index to minindex.
		_vector[minIndex] = temp;					// then restore minindex from temp.
		BubbleDown(minIndex);						// bubble down minindex recursively
	}
}

// PURPOSE: Bubbles up the node to correct position in the tree using recursion.
// PARAMETER: index = node at index to bubble up.
// ALGORITHM: A node in the heap is bubbled up to correct position by comparing
//			  the node at index and its parent node. 
//			  If the parent node is greater than its child node, swap places.
//			  This is done to each node
void MinHeap::BubbleUp(int index) {

	//if index is at 0, no need to bubble up.
	if (index == 0) {
		return;
	}

	int parentIndex = (index - 1) / 2;				// parents of node at index

	// if node at [parentindex] is greater than node at[index]
	if (_vector[parentIndex] > _vector[index]) {

		//swap places [parentindex] and [index] by...
		int tmp = _vector[parentIndex];				// temp variable to hold value at index
		_vector[parentIndex] = _vector[index];		// set parentindex to index.
		_vector[index] = tmp;						// then restore parentindex to index.
		BubbleUp(parentIndex);						// then check if parent index is in the correct position recursively.
	}
}

// PURPOSE: Inserts new value into heap.
// PARAMETER: newValue = the new value to insert into heap.
// ALGORITHM: Add new value to the end of vector, then bubble up the new value.
void MinHeap::Insert(int newValue) {

	////////////////////////////////

	_vector.push_back(newValue);					// adding new value to the end of _vector.
	BubbleUp(_vector.back());						// bubbling up the last node in the tree to correct position.
}

// PURPOSE: Returns smallest value from the root.
int MinHeap::GetMin() {
	return _vector.front();							// value at root.
}

// PURPOSE: Deletes the min value at root.
// ALGORITHM: First, vector is checked if empty. if empty return, if not empty
//			  set the front of vector to the back of vector, then delete back of vector.
//			  Then lastly, the node at root is bubbled down.
void MinHeap::DeleteMin() {

	///////////////////////////////

	// if vector is empty, nothing needs to be done, so return.
	if (_vector.empty()) {
		return;
	}

	// else, if vector is not empty,
	_vector.front() = _vector.back(); 				// set root to last node.
	_vector.pop_back();								// delete last node.

	BubbleDown(0); 									// bubble down the node at root to correct position.
}

// PURPOSE: Main tests out the heap implementation.
// ALGORITHM: Arraylist of 6 values is created, then heapified using minheap constructor.
//			  To get the 3 smallest values, a for loop is used; 
//			  getmin() function is called then deletionmin().
int main() {
	cout << "// Name: Chris Banci" << endl;
	cout << "// Assignment: HW5 - Heap" << endl;
	cout << "// Date: 11/4/16" << endl << endl;

	int array[] = { 10, 4, 5, 30, 3, 300 };			// initilaze array with these values.

	MinHeap minHeap(array, 6);						// create instance of minheap.

	//get the 3 smallest values using for loop by calling getmin() then deletemin().
	for (int i = 0; i< 3; ++i) {
		cout << minHeap.GetMin() << "  ";
		minHeap.DeleteMin();
	}

	cout << endl;

	return 0;
}