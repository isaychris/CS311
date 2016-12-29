// ===============================================================
// HW#: HW4 BST
// Your name: Chris Banci
// Complier:  g++
// File type: binstree implementation file
//================================================================
#include <iostream>
#include "binstree.h"

using namespace std;

// PURPOSE: constructor  initializes Root
BST::BST() {
	Root = NULL;										// This is an empty tree
}

// PURPOSE: destructor must completely destroy the tree
BST::~BST() {
	dtraverse(Root);									// traverse to delete all vertices in post order
	Root = NULL;										// This is an empty tree
}

// PURPOSE: Does Post Order traversal of the tree and deletes each vertex recurisvely.
// PARAM:   V = a pointer to the vertex to be deleted
// ALGORITHM: post order traversal consist of: traverse left, traverse right then visit root.
void BST::dtraverse(Vertex* V) {

	// traverse list until v is null recursively.
	if (V != NULL) {
		dtraverse(V->Left);								// visit left sub tree of V
		dtraverse(V->Right);							// visit right sub tree of V
		delete V;										// deletes V
	}
}

// PURPOSE: Show elements in IN order traversal from the Root
void BST::ShowInOrder() {
	cout << "Elements in the IN order: " << endl;
	INorderTraversal(Root);								// start in-order traversal from the root
}

// PURPOSE: Does IN order traversal from V recursively
// PARAM:	V is te pointer to the vertex to visit right now
// ALGORITHM: in order traversal consist of: travere left, visit root, then traverse right.
void BST::INorderTraversal(Vertex* V) {

	// traverse list until v is null recursively.
	if (V != NULL) {								
		INorderTraversal(V->Left); 						// ** traverse left sub-tree of V recursively - done
		cout << "V = " << V->Elem << endl; 				// ** display V's element and do endl; - done
		INorderTraversal(V->Right); 					// ** traverse right sub-tree of V recursively - done
	}
}

// PURPOSE: Show elements in PRE order traversal from the Root
//			This is the same as Depth First Traversal
void BST::ShowPreOrder() {
	cout << "Elements in the PRE order:" << endl;
	PREorderTraversal(Root);							// start pre-order traversal from the root
}

// PURPOSE: Does PRE order traversal from V recursively
// PARAM:	V = the pointer to the vertex to be visited now
// ALGORITHM: pre order traversal consist of: visit root, traverse left then traverse right.
void BST::PREorderTraversal(Vertex* V) {

	// traverse list until v is null recursively.
	if (V != NULL) {
		cout << "V = " << V->Elem << endl;				// ** display V's element and do endl; - done
		PREorderTraversal(V->Left);						// ** traverse left sub-tree of V recursively - done
		PREorderTraversal(V->Right);					// ** traverse right sub-tree of V recursively - done
	}
}

// PURPOSE: Adds a vertex to the binary search tree for a new element
// PARAM:	E = the new element 
// ALGORITHM: We will do this iteratively (not recursively) to demonstrate the algorithm that is in the notes
//    - smaller than the current -> go to the left
//    - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::Insertvertex(elem_t E) {
	Vertex* N;											// N will point to the new vertex to be inserted
	N = new Vertex;										// a new vertex is created
	N->Left = NULL;										// make sure it does not
	N->Right = NULL;									// point to anything
	N->Elem = E;										// put element E in it

	cout << "Trying to insert " << E << endl;

	// Case 1: tree is empty.
	if (Root == NULL) {
		Root = N;										// point root to N.
		cout << "...adding " << E << " as the root" << endl;
	}

	// Case 2: tree not empty.
	else {												
		Vertex* V;										// V will point to the current vertex
		Vertex* Parent;									// Parent will point to V's parent
		V = Root;										// start with the root as V

		// traverse list until V is null.
		while (V != NULL) {	

			// element already exists
			if (N->Elem == V->Elem) {					
				cout << "...error: the element already exists" << endl;
				return;
			}

			// element does not exist.
			else {

				// vertex N is smaller than current.
				if (N->Elem < V->Elem) {				
					cout << "...going to the left" << endl;
					Parent = V;							 // ** change Parent to be V to go down - done
					V = V->Left;						 // ** change V to be V's Left - done
				}

				// vertex N is bigger than current
				else {									
					cout << "...going to the right" << endl;
					Parent = V;							// ** change Parent to be V to go down - done.
					V = V->Right;						// ** change V to be V's Right - done.
				}
			}
		}  

		// reached NULL -- Must add N as the Parent's child
		// vertex N is smaller than parent vertex.
		if (N->Elem < Parent->Elem) {
			cout << "...adding " << E << " as the left child of " << Parent->Elem << endl;
			Parent->Left = N;							// ** Parent's Left should point to the same place as N - done.
		}

		// vertex N is bigger than parent vertex.
		else {
			cout << "...adding " << E << " as the right child of " << Parent->Elem << endl;
			Parent->Right = N; 							// ** Parent's Right should point to the same place as N - done.
		}
	}  
}  

// PURPOSE: Deletes a vertex that has E as its element.
// PARAM:	E = Element to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E) {
	Vertex* V;											// the current vertex
	Vertex* Parent = NULL;								// its parent

	cout << "Trying to delete " << E << endl;

	// Case 1: root only
	// current vertex is root when root left & right is equal to null.
	if ((E == Root->Elem) && (Root->Left == NULL && Root->Right == NULL)) {
		cout << "...deleting the lonely root" << endl;
		delete Root;
		Root = NULL;
		return;
	} 

	// Case 2: root with one child
	//** if what you want to delete is the root with one child
	else if ((E == Root->Elem) && (Root->Left == NULL || Root->Right == NULL)) {

		// root with right child
		if (Root->Left == NULL) {
			cout << "...deleting root with right child" << endl;
			V = Root->Right;
			delete Root;
			Root = V;									// ** change the root to the child and return - done
			return;
		}
		
		// root with left child
		else if (Root->Right == NULL) {
			cout << "...deleting root with left child" << endl;
			V = Root->Left;
			delete Root;
			Root = V;
			return;
		}  
	} 

	// Case 3: Otherwise deleting something else
	V = Root; // start traversal at root.
	while (V != NULL) {

		// elem found
		if (E == V->Elem) {
			cout << "...removing " << V->Elem << endl;
			remove(V, Parent);								// ** call remove here to remove V - done
			return;
		}

		// elem not found
		else {

			// E is smaller than current vertex.
			if (E < V->Elem) {
				cout << "...going to the left" << endl;
				Parent = V;									// ** update Parent and V here to go down - done
				V = V->Left;
			}

			// E is larger than current vertex.
			else {
				cout << "...going to the right" << endl;
				Parent = V;									// ** update Parent and V here to go down - done
				V = V->Right;
			}
		}
	}

	// reached NULL  -- did not find it
	cout << "Did not find the key in the tree." << endl;		
} 

// PURPOSE: Removes vertex pointed to by V
// PARAM:	V = vertex to remove.
//			P = parent pointer of v.
// ALGORITHM:
//		- Case 1: it is a leaf, delete it
//		- Case 2: it has just one child, bypass it
//		- Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex* V, Vertex* P) {

	// Case 1: leaf.
	// ** if V is a leaf (case 1) - done.
	if ((V->Left == NULL) && (V->Right == NULL)) {

		// ** if V is a left child of P - done
		if (P->Left == V) {
			cout << "... removing a left leaf" << endl;
			delete V;										// ** delete V and also make Parent's left NULL - done
			P->Left = NULL;
		}

		// V is a right child of P
		else {
			cout << "... removing a right leaf" << endl;
			delete V;										// ** delete V and also make Parent's right NULL - done
			P->Right = NULL;
		}
	} 

	// Case 2: V has left or right child.
	// ** if V has just the left child or right (case 2) - done
	else if ((V->Left == NULL && V->Right != NULL) || (V->Right == NULL && V->Left != NULL)) {

		// V has left child.
		if (V->Left != NULL) {
			cout << "...removing a vertex with just the left child" << endl;

			// ** Make Parent left or right point to the left child and delete V
			// (You need if then else to determine left or right)

			// parent right points to v.
			if (P->Right == V) {
				P->Right = V->Left;
				delete V;
			}

			// parent left points to v.
			else if (P->Left == V) {
				P->Left = V->Left;
				delete V;
			}
		}  

		// V has right child.
		else if (V->Right != NULL) {
			cout << "...removing a vertex with just the right child" << endl;

			// ** Make Parent left or right point to the right child and delete V
			// (You need if then else to determine left or right)

			// parent right points to v.
			if (P->Right == V) {
				P->Right = V->Right;
				delete V;
			}

			// parent left points to v.
			else if (P->Left == V) {
				P->Left = V->Right;
				delete V;
			}
		}
	}

	// Case 3:  V has two children 
	else if (V->Left != NULL && V->Right != NULL) {
		cout << "...removing an internal vertex with children" << endl;
		cout << ".....find the MAX of its left sub-tree" << endl;

		elem_t Melem;									// variable to hold max element
		Melem = findMax(V);

		cout << ".....replacing " << V->Elem << " with " << Melem << endl;
		V->Elem = Melem;								// ** Replace V's element with Melem here - done.
	}  
}  

// PURPOSE: Finds the Maximum element in the left sub-tree of V
// PARAM:	V = a vertex to traverse.
// ALGORITHM: start at left subtree. traverse vertex right until null.
//			  once loop ends, your left with max element, so return.
elem_t BST::findMax(Vertex* V) {
	Vertex* Parent = V;									// parent pointed to V.
	V = V->Left;  										// start with the left child of V

	while (V->Right != NULL) {							// ** while the right child of V is still available - done
		Parent = V; 									// ** update Parent and V to go to the right - done
		V = V->Right;
	}

	// reached NULL Right  -- V now has the MAX element
	elem_t X = V->Elem;									// variable that holds max element
	cout << ".....Max is " << X << endl;

	remove(V, Parent);  								// remove the MAX vertex
	return X;           								// return the MAX element
}  
