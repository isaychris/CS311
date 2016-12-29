//===========================================================
// HW#: HW2P1 Algorithm analysis 
// Your name: Chris Banci
// Compiler: g++
// File type: combine client program
//===========================================================

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// PURPOSE: This function displays the contents of a vector.
// PARAMETER: v = a vector passed by reference used for displaying its contents.
void displayVector(vector<int> &v) {
	cout << "[ ";

	// iterating through a vector to display its contents
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}

	cout << "]" << endl;
}

// PURPOSE: This function combines two vector lists into one called L3.
// PARAMETER: The vector lists passed by reference used for combining into one.
//			  A = vector to combine
//			  B = vector to combine
//			  R = vectors are combined into this vector.
// ALGORITHM: The algorithm works by passing three vectors into the combine function.
//			  The combine function combines two vectors into one. To achieve this,
//			  first, the values of the two vectors are reversed so they can be popped in
//			  ascending order. Next, in a while loop, until vector A or B runs out of element
//		      the back element of vector A and B are compared and the smallest value gets 
//			  pushed to the new vector. Once vector a or b runs out of elements, if any
//			  of the vectors still contains elements, they are pushed into the new vector until empty.
//			  This process should combine vector A and vector B and vector R by ascending order.
void combine(vector<int>& A, vector<int>& B, vector<int>& R) {
	// reverses the vectors so they their values are in ascending order when popped.
	// [1 2 3] turns into [3 2 1]
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	//Until vector A or vector B runs out of elements, make comparisons.
	while (!A.empty() && !B.empty()) {

		// comparsion for when last element of vector A is less than B.
		// push last element of vector A to vector R.
		if (A.back() < B.back()) {
			R.push_back(A.back());
			A.pop_back();
		}

		// comparsion for when last element of vector A is greater than B.
		// push last element of vector A to vector R.
		else {
			R.push_back(B.back());
			B.pop_back();
		}

		cout << " - comparison!" << endl;
	}

	// If there are any remaining elements in either vector A or B, pop until empty.
	// case 1: vector A is not empty
	if (!A.empty()) {
		while (!A.empty()) {
			R.push_back(A.back()); // update vector R.
			A.pop_back();
		}
	}

	// case 2: vector B is not empty.
	// push last element of vector A
	else if (!B.empty()) {
		while (!B.empty()) {
			R.push_back(B.back()); // update vector R.
			B.pop_back();
		}
	}

}

// PURPOSE: This is the driver that tests the combine function.
// ALGORITHM: The program first prompts user to set vector size.
//			  This is done because two vectors must be the same size to combine.
//			  Then prompts user to enter the vectors integers in ascesending 
//			  order into their respective vectors. Vector L1, L2, and L3 
//			  are passed into the combine function to combine L1 and L2 into L3.
//			  At the end, the contents of L3 are displayed.
int main() {
	vector<int> L1; // vector used in combine function.
	vector<int> L2; // vector used in combine function.
	vector<int> L3; // combined vector list, the result.

	int vector_size = 0; // variable to hold vector size;
	int temp = 0; // variable to temp hold inputted integers.

				  // this will set the max number of integers that can be entered for a vector.
	cout << "Enter size of vector: ";
	cin >> vector_size;

	// error handling if user types in invalid size for vector.
	while (vector_size < 1) {
		cout << "[Error] invalid size, enter again: ";
		cin >> vector_size;
	}

	// enter the integers for vector L1.
	cout << endl << "Enter integers into increasing order for L1 vector: " << endl;
	for (int i = 0; i < vector_size; i++) {
		cout << " - element " << i + 1 << ": ";
		cin >> temp;
		L1.push_back(temp);
	}

	// display contents of L1
	cout << "L1 = ";
	displayVector(L1);

	// enter the integers for vector L2.
	cout << endl << "Enter integers into increasing order for L2 vector: " << endl;
	for (int i = 0; i < vector_size; i++) {
		cout << " - element " << i + 1 << ": ";
		cin >> temp;
		L2.push_back(temp);
	}

	// display contents of L2
	cout << "L2 = ";
	displayVector(L2);

	// combine function called here.
	cout << endl << "Combining vector lists L1 & L2..." << endl;
	combine(L1, L2, L3);

	// displays contents of L3
	cout << endl << "L3 = ";
	displayVector(L3);

	return 0;
}