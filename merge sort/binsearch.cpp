//===========================================================
// HW#: HW2P1 Algorithm analysis 
// Your name: Chris Banci
// Compiler: g++
// File type: binarysearch client program
//===========================================================

#include <vector>
#include <iostream>

using namespace std;

// PURPOSE: This function does a binary search on an arraylist.
// PARAMETERS: data = the array list
//			   search = the number being searched.
//			   low = the lower bound of array.
//			   high = the upper bound of array.
// ALGORITHM: With binary search, we can search a number in an ordered arraylist
//			  using recursion. This implementation of binary search works by
//			  first setting the lower and upper bound of the arraylist. Then,
//			  a mid point is found. We than make a comparsion between searched number
// 			  and mid point. It can go either two ways: If the number we are searching is
//			  less than the mid point, then we decrement the upperbound pointer by minus 1.
//			  If the number we are searching is greater than the mid point, then we increment
//			  lowerbound pointer by plus 1. This is all done until the value in mid equals
//			  the searched number or when lowerbound is equal or less than upperbound.
int binarySearch(int data[], int search, int low, int high) {
	//if lowerbound is greater than upperbound, that means number couldnt be found.
	if (low > high) {
		return -1;
	}

	// calcuates midpoint to split search in half.
	int mid = low + (high - low) / 2;

	// if the value in data indexed at mid is equal to the search number, position is returned.
	if (data[mid] == search) {
		return mid + 1;
	}

	//else if search number is greater than midpoint, update lowerbound.
	else if (data[mid] < search) {
		low = mid + 1;
	}

	//else if search number isless than midpoint, update upperbound.
	else if (data[mid] > search) {
		high = mid - 1;
	}

	//recursion
	binarySearch(data, search, low, high);
}


// PURPOSE: This drives the program to test binary search.
// ALGORITHM: Program prompts user to search a number.
//			  The searched number and other variables are passed to binary search method.
//		      If binary search returns -1, number was not found, else number was found
int main() {
	int dataset[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 }; //the set of data
	int search = 0; // variable that holds the number to be searched.
	int position = 0; // variable that holds the position of searched number.

	cout << "Enter number to search: ";
	cin >> search;

	// checks validity of input.
	while (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Invalid input, enter again: ";
		cin >> search;

		if (isdigit(search)) {
			break;
		}
	}
	cout << endl;

	// calling the binarysearch function.
	position = binarySearch(dataset, search, 0, 9);

	// if binarysearch returns -1, number cannot be found.
	if (position == -1) {
		cerr << "The number " << search << " cannot be found." << endl;
		return -1;
	}

	// else, the number was found.
	cout << "The number " << search << " is at position: " << position << endl;

	return 0;
}