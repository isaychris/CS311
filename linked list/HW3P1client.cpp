// ====================================================
// HW#: HW3P1 llist
// Your name: Chris Banci
// Compiler:  g++
// File type: llist client program
//=====================================================
using namespace std;

#include <iostream>
#include "llist.h"

// PURPOSE: This is the first case test.
void caseOne()
{
	llist L; // linked list L
	int x; // to hold a removed element

	cout << "=============== CASE 1 ==============" << endl;

	//1 check empty and report the result
	cout << "Test " << 1 << endl;
	if (L.isEmpty()) {
		cout << " - The linked List is empty." << endl;
	}
	else {
		cout << " - The linked List is not empty." << endl;
	}
	cout << endl;

	//2 display the list
	cout << "Test " << 2 << endl;
	L.displayAll();
	cout << endl;

	//3 add 4 integers 1,2,3,4
	cout << "Test " << 3 << endl;
	L.addRear(1);
	L.addRear(2);
	L.addRear(3);
	L.addRear(4);
	cout << endl;

	//4 display the list
	cout << "Test " << 4 << endl;
	L.displayAll();
	cout << endl;

	//5 remove from front twice (and display the elements removed)
	cout << "Test " << 5 << endl;
	L.deleteFront(x);
	cout << " - Element " << x << " has been removed." << endl;
	L.deleteFront(x);
	cout << " - Element " << x << " has been removed." << endl;
	cout << endl;

	//6 display the list
	cout << "Test " << 6 << endl;
	L.displayAll();
	cout << endl;

	//7 check empty and report the result
	cout << "Test " << 7 << endl;
	if (L.isEmpty()) {
		cout << " - The linked List is empty." << endl;
	}
	else {
		cout << " - The linked List is not empty." << endl;
	}
	cout << endl;

	//8 remove from the rear twice (display the element removed)
	cout << "Test " << 8 << endl;
	L.deleteRear(x);
	cout << " - Element " << x << " has been removed." << endl;
	L.deleteRear(x);
	cout << " - Element " << x << " has been removed." << endl;
	cout << endl;

	//9 check empty again and report the result
	cout << "Test " << 9 << endl;
	if (L.isEmpty()) {
		cout << " - The linked List is empty." << endl;
	}
	else {
		cout << " - The linked List is not empty." << endl;
	}
	cout << endl;

} //end of case 1

// PURPOSE: This is the second case test.
void caseTwo()
{
	llist L2; // linked list L2
	int x; // to hold the removed element
	int c = 1; // displayed step number

	cout << "=============== CASE 2 ==============" << endl;

	// 1.add to front once   (element 5)
	cout << "Test " << c++ << endl;
	L2.addFront(5);
	cout << endl;

	// 2.add to front again  (element 4)
	cout << "Test " << c++ << endl;
	L2.addFront(4);
	cout << endl;

	// 3.delete Front
	cout << "Test " << c++ << endl;
	L2.deleteFront(x);
	cout << endl;

	// 4.add to rear 3 times (elements 6,8,9)
	cout << "Test " << c++ << endl;
	L2.addRear(6);
	L2.addRear(8);
	L2.addRear(9);
	cout << endl;

	// 5. display all
	cout << "Test " << c++ << endl;
	L2.displayAll();
	cout << endl;

	// 6.add before the 1st  (element 4) . 4 5 6 8 9
	cout << "Test " << c++ << endl;
	L2.addbeforeIth(1, 4);
	cout << endl;

	// 7.add before the 4th  (element 7) . 4 5 6 7 8 9
	cout << "Test " << c++ << endl;
	L2.addbeforeIth(4, 7);
	cout << endl;

	// 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
	cout << "Test " << c++ << endl;
	L2.addbeforeIth(7, 10);
	cout << endl;

	// 9.add before the 9th  (element 12) . error (out of range)
	cout << "Test " << c++ << endl;
	try {
		L2.addbeforeIth(9, 12);
	}
	catch (llist::OutOfRange) {
		cerr << " - Error, out of range." << endl;
	}
	cout << endl;

	// 10.add before the 0th (element 0) . error (out of range)
	cout << "Test " << c++ << endl;
	try {
		L2.addbeforeIth(0, 0);
	}
	catch (llist::OutOfRange) {
		cerr << " - Error, out of range." << endl;
	}
	cout << endl;

	// 11.displayAll
	cout << "Test " << c++ << endl;
	L2.displayAll();
	cout << endl;

	// 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
	cout << "Test " << c++ << endl;
	L2.deleteIth(1, x);
	cout << endl;

	// 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9
	cout << "Test " << c++ << endl;
	L2.deleteIth(6, x);
	cout << endl;

	// 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
	cout << "Test " << c++ << endl;
	L2.deleteIth(3, x);
	cout << endl;

	// 15.delete Ith I==5 . error (out of range)
	cout << "Test " << c++ << endl;
	try {
		L2.deleteIth(5, x);
	}
	catch (llist::OutOfRange) {
		cerr << " - Error, out of range." << endl;
	}
	cout << endl;

	// 16.delete Ith I==0 . error (out of range)
	cout << "Test " << c++ << endl;
	try {
		L2.deleteIth(0, x);
	}
	catch (llist::OutOfRange) {
		cerr << " - Error, out of range." << endl;
	}
	cout << endl;

	// 17.displayAll
	cout << "Test " << c++ << endl;
	L2.displayAll();
	cout << endl;

	// 18.delete from rear until it is empty (indicate the elements removed)
	cout << "Test " << c++ << endl;
	while (!L2.isEmpty()) {
		L2.deleteRear(x);
		cout << " - Element " << x << " has been removed." << endl;
	}
	cout << endl;

	// 19.displayAll
	cout << "Test " << c++ << endl;
	L2.displayAll();
	cout << endl;

} //end of case 2


// PURPOSE: This is the third case test.
void caseThree()
{
	llist L3; // linked list L3
	int x; // to hold the removed element

	cout << "=============== CASE 3 ==============" << endl;

	// 1.add before the 0th . error (out of range)
	cout << "Test " << 1 << endl;
	try {
		L3.addbeforeIth(0, 4);
	}
	catch (llist::OutOfRange) {
		cerr << " - Error, out of range." << endl;
	}
	cout << endl;

	//2.delete front . error (underflow)
	cout << "Test " << 2 << endl;
	try {
		L3.deleteFront(x);
	}
	catch (llist::Underflow) {
		cerr << " - Error, Underflow." << endl;
	}
	cout << endl;

} //end of case 3


// PURPOSE: This is the fourth case test.
void caseFour()
{
	llist L4; // linked list L4
	int x; // to hold the removed element

	cout << "=============== CASE 4 ==============" << endl;

	//1.delete 2nd . error (out of range)
	cout << "Test " << 1 << endl;
	try {
		L4.deleteIth(2, x);
	}
	catch (llist::OutOfRange) {
		cerr << " - Error, out of range." << endl;
	}
	cout << endl;

	//2.delete rear . error (underflow)
	cout << "Test " << 2 << endl;
	try {
		L4.deleteRear(x);
	}
	catch (llist::Underflow) {
		cerr << " - Error, Underflow." << endl;
	}
	cout << endl;

} // end of case 4

  // PURPOSE: This program tests the implementation of linked lists.
  // ALGORITHM: Four case tests are split into four functions. A menu is used to select which case to test.
int main()
{
	cout << "//Author: Chris Banci" << endl;
	cout << "//Assignment: HW3P1" << endl;
	cout << "//Date: 10/13/16" << endl << endl;

	int selection; // this will indicate what the user wants to do

	do {
		cout << "-------------------------------------" << endl;
		cout << "//             MENU                // " << endl;
		cout << "-------------------------------------" << endl;
		cout << " - [1] Case 1  " << endl;
		cout << " - [2] Case 2  " << endl;
		cout << " - [3] Case 3  " << endl;
		cout << " - [4] Case 4 " << endl;
		cout << " - [0] to quit " << endl;
		cout << endl;

		cout << "Select [?]: ";
		cin >> selection;

		// checks validity of input.
		while (cin.fail() || selection < 0 || selection > 4) {
			cin.clear();
			cin.ignore(25, '\n');

			cout << "Invalid selection, enter again: ";
			cin >> selection;
		}

		cout << "---------------------------------------" << endl << endl;

		//switch statement to switch to different cases.
		switch (selection) {
			case 1:
				caseOne();
				break;
			case 2:
				caseTwo();
				break;
			case 3:
				caseThree();
				break;
			case 4:
				caseFour();
				break;
		}
	} while (selection != 0); 	//menu loop ends when user enters 0.

} // end of main
