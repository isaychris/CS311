// =======================================================
// CS 311 Fall 2016 Final Exam 2, Due: 12/16/2016
// Program: Find the k'th largest element from a AVL Tree
// 1. Complete the left & right rotation functions (80 pts)
// 2. Complete the kthLargest() and other functions (20 pts)
// Your name: Chris Banci
//=======================================================
#include <iostream>

using namespace std;
int tree_size;					// size of tree incremented through insertion of new nodes in tree.

// avl tree node structure
struct Node
{
	int key;					// the element inside node
	Node *left;					// left child node
	Node *right;				// right child node
	int height;					// height of node
};

// PURPOSE: Helper function that allocates a new node with the given key and NULL left and right pointers.
// PARAMETER: key = the value of the node.
struct Node* newNode(int key)
{
	Node* node = new Node;		// allocation of new node
	node->key = key;			// nodes key set to key.
	node->left = NULL;			// left child node set to 
	node->right = NULL;			// right child node set to null
	node->height = 1;			// new node is initially added at leaf

	return node;
};

// PURPOSE: A utility function to get height of the tree
// PARAMETER: N = the node in the avl tree that we are using to find the height.
int height(Node *N)
{
	// if node is null, return 0.
	if (N == NULL) 
		return 0;

	// else, return height of N.
	return N->height;
}

// PURPOSE: A utility function to get maximum of two integers
// PARAMETER: a = an integer to compare to b.
//			  b = an integer to compare to a.
int max(int a, int b)
{
	// compares two integers, and returns the greater one.
	return (a > b) ? a : b;
}

// PURPOSE: Does a right rotation on the node x.
// PARAMTER: x = The root node we are to rotating.
// ALGORITHM: x is rotated to the right and the heights are balanced.
Node* rightRotate(Node *x)
{
	Node *root = x->left;		// move x's left child up one level
	Node *R = root->right;		// set root's right child to R.

	root->right = x;			// set root;s right child to x.
	x->left = R;				// set R as x's left child.

	// update the heights of the nodes by calling max and adding 1.
	x->height = (max(height(x->left), height(x->right))) + 1; 
	root->height = (max(height(root->left), height(root->right))) + 1;

	return root;
}

// PURPOSE: Does a left rotation on the node x.
// PARAMTER: x = The root node we are to rotating.
// ALGORIHM: x is rotated to the left and heights are balanced.
Node* leftRotate(Node *x)
{
	Node *root = x->right;	// move x's right child up one level
	Node *L = root->left;	// set root's right child to L.

	root->left = x;			// set root's left child to x.
	x->right = L;			// set L as x's right child.

	// update the heights of the nodes by calling max and adding 1.
	x->height =  1 + (max(height(x->left), height(x->right)));
	root->height = 1 + (max(height(root->left), height(root->right)));

	return root;
}

// PURPOSE: Get Balance factor of node N
// PARAMETER: N = the node to get balance.
int getBalance(Node *N)
{
	// if node is null, return 0.
	if (N == NULL) 
		return 0;
	
	// else return the balance factor of N by subtracting the 
	// height of N's Left child and the hieght of N's Right child.
	return height(N->left) - height(N->right);
}

// PURPOSE: Recursive function to insert key in subtree rooted
//			with node and returns new root of subtree.
// PARAMETERS: node = node to insert key into
//			   key = key to insert node into.
// ALGORITHM: To insert nodes in the avl tree, we must stick to the rules of the bst property.
//			  To achieve that, there are two main rotations that must be made in order to balance the tree.
Node* insert(Node* node, int key)
{
	/* 1.  Perform the normal BST insertion */
	if (node == NULL) {
		tree_size++;
		return(newNode(key));
	}

	// if the current key is less key, set the new node as its left child.
	if (key < node->key)
		node->left = insert(node->left, key);

	// if current key is greater than key, set the new node as its right child.
	else if (key > node->key) 
		node->right = insert(node->right, key);

	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
		height(node->right));

	/* 3. Get the balance factor of this ancestor
	node to check whether this node became
	unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// PURPOSE: A utility function to print preorder traversal of the tree.
//			The function also prints height of every node
// PARAMETER: root = the current node.
// ALGORITHM: vist root, then visit left subtree then right subtree.
void preOrder(Node *root)
{
	// while root is not null
	if (root != NULL)
	{
		cout << root->key << " ";			// print key
		preOrder(root->left);				// visit left subtree
		preOrder(root->right);				// visit right subtree
	}
}

// PURPOSE: prints the tree from highest value to lowest value.
// PARAMETER: root = the current node.
// AGLORITHM: visit right subtree, print value, then vist left subtree.
void printReversal(Node *root)
{
	// while root is not null
	if (root != NULL)
	{
		printReversal(root->right);				// visit left subtree
		cout << root->key << " ";				// print key
		printReversal(root->left);				// visit right subtree
	}
}

// PURPOSE: Traverse list inorder in reverse.
// PARAMETERS: root = the current node visited
//			   counter = counter when visiting a node in the tree.
//			   k = kth largest in the tree.
// ALGORITHM: To reverse in order, right subtree subtree visted first then left subtree.
//			  The recursion stops when counter is equal to k.
void reverseInOrder(Node *root, int &counter, int k)
{
	// if root is null, return
	if (root == NULL) {
		return;
	}

	// traverse right subtree.
	reverseInOrder(root->right, counter, k);
	counter++;	// increment counter

	// if the counter is equal to k, then the kth largest element has been found.
	if (counter == k) {
		cout << " - the " << k << "th largest element is " << root->key << endl;
		return;
	}

	//traverse left subtree.
	reverseInOrder(root->left, counter, k);
}

// PURPOSE: Finds the kth largest element from an AVL tree.
// PARAMETERS: root = the current node.
//			   k = kth largest in the tree.
// ALGORITHM: Set a counter to 0 and do an inorder traversal of the avl tree in reverse til counter equals k.
void kthLargest(Node *root, int k)
{
	int counter = 0; // the number of elements read in the avl tree. set to 0.

	// error handling
	// if k is less than 1 or greater than size of tree, return error.
	if (k < 1 || k > tree_size) { // tree size accesed through global scope.
		cout << " - the " << k << "th largest element cannot be found." << endl;
		return;
	}

	// reverse in order traversal to get elements from highest to lowest inorder.
	reverseInOrder(root, counter, k);
}

// PURPOSE: To test the implementation of avl tree.
// ALGORITHM: create new node, insert multiple nodes with values into tree, 
//            then call kthlargest() function.
int main()
{
	cout << "// Name: Chris Banci" << endl;
	cout << "// Final Exam - AVL tree" << endl;
	cout << "// Date: 12/16/16" << endl << endl;

	Node *root = NULL;  // start with new node;

	/* The constructed AVL Tree would be
		30
	   /  \
	  20   40
	 /  \   \
	10   25  50
	*/

	/* Constructing tree given in the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	cout << "The AVL Tree:" << endl;
	cout << "    30" << endl;
	cout << "   /  \\ " << endl;
	cout << "  20   40 " << endl;
	cout << " /  \\   \\ " << endl;
	cout << "10   25  50" << endl << endl;

	cout << "Preorder traversal of the constructed AVL tree is:" << endl;
	preOrder(root);
	cout << endl << endl;

	cout << "Reverse in order traversal of the constructed AVL tree is:" << endl;
	printReversal(root);
	cout << endl << endl;

	cout << "Finding kth largest element:" << endl;
	kthLargest(root, 1);
	kthLargest(root, 2);
	kthLargest(root, 3);
	kthLargest(root, 6);

	return 0;
}