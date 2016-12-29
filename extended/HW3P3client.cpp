//=========================================================
// HW#: HW3P3 extended
// Your name: Chris Banci
// Complier:  g++
// File type: slist client program (tester)
//===========================================================

using namespace std;
#include <iostream>
#include "slist.h"

//PURPOSE: This function simply tests the copy constructor of the slist class
//		   and adds 6 to a the rear of copiedList and displays the list.
//PARAMETER: copieddList = list passed by value becomes copiedList.
void CopyTest(slist copiedList) {
	copiedList.addRear(6);
	cout << "- Element 6 added to the rear of copied list" << endl;

	copiedList.displayAll();
}

// PURPOSE: This program tests = operation overloading and copy constructor.
// ALGORITHM: Elements are added into L1 and L2. a copy of L1 is made by calling copyTest(), 
//			  which simply tests the copy constructor and adds 6 to the copied list. The
//			  elements of L1 is displayed and it should show that no change was made to the list.
//			  The elements of L1 is then copied over to the L2 object. A node is removed from L1
//			  and L2 is displayed to show it had no effect on the L2 list. L1 and L2 are 
//			  completely different, not references of each other.
int main() {

	cout << "// Author: Chris Banci" << endl;
	cout << "// Assignment: HW3P3" << endl;
	cout << "// Date: 10/22/16" << endl << endl;

	slist L1, L2; // my slist objects.
	int temp; // variable to hold removed elements
	int counter = 1; // counter that increments.

	//1.Create a 5 element list with  1,2,3,4,5 (L1)
	cout << "Test " << counter++ << endl;
	L1.addRear(1);
	L1.addRear(2);
	L1.addRear(3);
	L1.addRear(4);
	L1.addRear(5);
	cout << " - Element 1 added to the rear of L1" << endl;
	cout << " - Element 2 added to the rear of L1" << endl;
	cout << " - Element 3 added to the rear of L1" << endl;
	cout << " - Element 4 added to the rear of L1" << endl;
	cout << " - Element 5 added to the rear of L1" << endl;
	cout << endl;

	//2.Pass the list to a client function called CopyTest to 
	//test your copy constructor.
	cout << "Test " << counter++ << endl;
	CopyTest(L1);
	cout << endl;

	cout << "-------------- After copytest --------------" << endl;

	//3.Display L1 (this should still be a 5 element list)
	cout << "Test " << counter++ << endl;
	L1.displayAll();
	cout << endl;

	cout << "------- Testing operator overloading -------" << endl;

	//4.Do L1 = L1;
	cout << "Test " << counter++ << endl;
	L1 = L1;
	cout << " - L1 = L1" << endl;
	cout << endl;

	//5.Display L1    (this should still be 1 2 3 4 5)
	cout << "Test " << counter++ << endl;
	L1.displayAll();
	cout << endl;

	//6.Create a 4 element list L2 with 7,8,9,10.
	cout << "Test " << counter++ << endl;
	L2.addRear(7);
	L2.addRear(8);
	L2.addRear(9);
	L2.addRear(10);
	cout << " - Element 7 added to the rear of L2" << endl;
	cout << " - Element 8 added to the rear of L2" << endl;
	cout << " - Element 9 added to the rear of L2" << endl;
	cout << " - Element 10 added to the rear of L2" << endl;
	cout << endl;

	//7.Display L2
	cout << "Test " << counter++ << endl;
	L2.displayAll();
	cout << endl;

	//8.Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
	cout << "Test " << counter++ << endl;
	L2 = L1;
	cout << " - L2 = L1" << endl;
	cout << endl;

	//9.Display L2.
	cout << "Test " << counter++ << endl;
	L2.displayAll();
	cout << endl;

	//10.Remove a rear node from L1. (This should not affect L2).
	cout << "Test " << counter++ << endl;
	L1.deleteRear(temp);
	cout << " - Rear node removed from L1" << endl;
	cout << endl;

	//11.Display L1.   (L1 is 1,2,3,4)
	cout << "Test " << counter++ << endl;
	L1.displayAll();
	cout << endl;

	//12.Display L1 again. (4 elements . just to make sure)
	cout << "Test " << counter++ << endl;
	L1.displayAll();
	cout << endl;

	//13.Display L2 again. (still 5 elements 1,2,3,4,5)
	cout << "Test " << counter++ << endl;
	L2.displayAll();
	cout << endl;

}//end of program

