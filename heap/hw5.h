// ===============================================================
// HW#: HW5 heap
// Your name: Chris Banci
// Complier:  g++
// File type: heap header file
//================================================================
#include <vector>
#include <iostream>

using namespace std;

class MinHeap {
private:
	vector<int> _vector;					// My vector
	void BubbleDown(int index);				// Bubbles down the node at index to correct position in the tree using recursion.
	void BubbleUp(int index);				// Bubbles up the node at index to correct position in the tree using recursion.
	void Heapify();							// Heapifies vector by making sure each node has heap property.

public:
	MinHeap(int* array, int length);		// Constructor which copies array contents into a vector and heapifies it
	MinHeap(const vector<int>& vector);		// Constructor which heapifies vector
	MinHeap();								// Default constructor

	void Insert(int newValue);				// Inserts new value into heap.
	int GetMin();							// Returns smallest value from the root.
	void DeleteMin();						// deletes the min value at root.
};