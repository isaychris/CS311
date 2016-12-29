//=========================================================
// HW#: HW3P2 slist
// Your name: Chris Banci
// Complier:  g++
// File type: client program (tester)
//===========================================================
using namespace std;

#include <iostream>
#include "slist.h"

// PURPOSE: This function prints if the element was found or not.
//			If pos == 0, then element was not found.
//			else, element was found.
// PARAMETERS: search = number that was searched.
//			   pos = position from calling search function.
void printMsg(int search, int pos) {
	if (pos == 0) {
		cout << " - Element " << search << " not found" << endl;
	}
	else {
		cout << " - Element " << search << " found in position " << pos << endl;
	}
}

// PURPOSE: This program tests the impelmentation of inherited link list.
int main() {
	cout << "// Author: Chris Banci" << endl;
	cout << "// Assignment: HW3P2" << endl;
	cout << "// Date: 10/14/16" << endl << endl;

	slist L;          // the list
	int foundPos;     // to hold the found position
	int counter = 1;  // used to display test line number

	try {
		// 1) add to front once (element 4)
		cout << "Test " << counter++ << endl;
		L.addFront(4);
		cout << " - Element 4 added to front" << endl;
		cout << endl;

		// 2) add to rear 3 times (elements 6,7,8)
		cout << "Test " << counter++ << endl;
		L.addRear(6);
		L.addRear(7);
		L.addRear(8);
		cout << " - Element 6 added to rear" << endl;
		cout << " - Element 7 added to rear" << endl;
		cout << " - Element 8 added to rear" << endl;
		cout << endl;

		// 3) displayAll    - 4 6 7 8
		cout << "Test " << counter++ << endl;
		L.displayAll();
		cout << endl;

		// 4) search for 6, report the result  - found in pos 2
		cout << "Test " << counter++ << endl;
		foundPos = L.search(6);
		printMsg(6, foundPos);
		cout << endl;

		// 5) replace the 6 with 0 using the search result
		cout << "Test " << counter++ << endl;
		L.replace(0, 2);
		cout << endl;

		// 6) search for 8 and report the result . found in pos 4
		cout << "Test " << counter++ << endl;
		foundPos = L.search(8);
		printMsg(8, foundPos);
		cout << endl;

		// 7) replace the 8 with 2 using the search result
		cout << "Test " << counter++ << endl;
		L.replace(2, 4);
		cout << endl;

		// 8) displayAll                       - 4 0 7 2
		cout << "Test " << counter++ << endl;
		L.displayAll();
		cout << endl;

		// 9) search for 5 and report the result   - not found
		cout << "Test " << counter++ << endl;
		foundPos = L.search(5);
		printMsg(5, foundPos);
		cout << endl;

		// 10) replace postion 7 with 10
		cout << "Test " << counter++ << endl;
		L.replace(10, 7);
		cout << endl;
	}
	// exception handling.
	catch (llist::OutOfRange) {
		cerr << " - Error: Out Of Range. Bad position was given" << endl << endl;
	}
}  // end of program