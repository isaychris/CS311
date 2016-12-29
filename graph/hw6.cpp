// ===============================================================
// HW#: HW6 graph
// Your name: Chris Banci
// Complier:  g++
// File type: graph implementation & client file.
//================================================================

#include <iostream>
#include <iterator>
#include <list>
#include <stack>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph {
	int V;										// No. of vertices
	list<int> *adj;								// Pointer to an array containing adjacency lists
	void DFSUtil(int v, bool visited[]);		// A function used by DFS_recursive

public:
	Graph(int V);								// Constructor
	void addEdge(int v, int w);					// function to add an edge to graph
	void BFS(int s);							// prints BFS traversal from a given source s
	void DFS_recursive(int v);					// DFS traversal of the vertices reachable from v by using recursions
	void DFS(int v);							// DFS traversal of the vertices reachable from v by using iterations
};

// PURPOSE: Constructor for graph.
// PARAMETER: V = number of vertices initialize graph with.
Graph::Graph(int V) {
	///////////////////////////////////////////////////////

	this->V = V;						// set number of vertices.
	adj = new list<int>[V];				// initiliaze list with 5 int containers.
}

// PURPOSE: function to add an edge to graph
// PARAMTERS: v = the vertice an edge is added to.
//			  w = the edge to add to vertice.
void Graph::addEdge(int v, int w) {
	///////////////////////////////////////////////////////

	adj[v].push_back(w);				// to add an edge to a vertice, simply add w to v's list.
}

// PURPOSE: prints BFS traversal from a given source s
// PARAMETER: s = vertice to start bfs traversal at.
// ALGORITHM: Visit vertex, then push its adjacent vertices to the queue and mark as visted.
//			  Deque the front to make it the source vertex, then add its adjacent vertices
//			  that havent been visited yet. Repeat until all vertices in queue are dequed and visted.
void Graph::BFS(int s) {
	bool *visited = new bool[V];		// create array of booleans with V size.

	// Mark all the vertices as not visited
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	// Create a queue for BFS
	list<int> queue;					// list with int containers.

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// 'i' will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;				// iteratator for list of ints containers.

	// while the queue is not empty, do this..
	while (!queue.empty()) {
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s
		for (i = adj[s].begin(); i != adj[s].end(); ++i) {

			// If a adjacent has not been visited, then mark it visited and enqueue it
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

// PURPOSE: A function used by DFS_recursive
// PARAMETERS: v = current vertice to visit.
//			   visited[] = array of booleans which tells which vertice was visited
// ALGORITHM: Mark the current vertex as visited, then check the adjacent vertices of current vertex.
//			  if an adjacent vertice has not been visted yet, call DFSUTil() recursively, to set it as visted.
//			  The recusion ends when all vertices have been visted.
void Graph::DFSUtil(int v, bool visited[]) {
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";
	
	// 'i' will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;				// iteratator for list of int containers.

	// Recur for all the vertices adjacent to this vertex
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {

		// If a adjacent has not been visited, mark it visted by recursion.
		if (!visited[*i]) {
			DFSUtil(*i, visited);
		}
	}
}

// PURPOSE: DFS traversal of the vertices reachable from v by using recursions. 
//			This implemntation of DFS uses recursion by calling DFSUtil().
// PARAMETER: v = vertice to start recursive dfs traversal at.
// ALGORITHM: The source vertex is set to visted, then the adjacent vertices of source 
//			  are visted using recursion by calling DFSUtil().
void Graph::DFS_recursive(int v) {
	bool *visited = new bool[V];		// create array of booleans with V size.
	
	// Mark all the vertices as not visited
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	// Call the recursive helper function to print DFS traversal
	DFSUtil(v, visited);
}

// PURPOSE: DFS traversal of the vertices reachable from v by using iterations.
//			This implementation of DFS uses iteration by using a stack.
// PARAMETER: s = vertice to iterative dfs start traversal at.
// ALGORITHM: Visit current vertex, mark as visted then push to stack.
//			  Pop the stack, and check the adjacent vertices of popped vertex.
//			  Adjacent vertices of popped vertex are added to the stack in reverse.
//			  The process is repeated until all vertices are visited.
void Graph::DFS(int s) {
	bool *visited = new bool[V];		// create array of booleans with V size.

	// Mark all the vertices as not visited
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	// This implementation uses a stack.
	stack<int> stack;					// stack with int containers.

	// Mark the current node as visited and push to stack.
	visited[s] = true;
	stack.push(s);

	// 'i' will be used to get all adjacent vertices of a vertex.
	//  To make the iterative DFS yield the same result as the recursive one,
	//  the adjacent vertices of the vertex needs to be added to the stack in reverse order,
	//	using reverse iterator.
	list<int>::reverse_iterator i;		// iteratator for list of int containters.

	// while the stack is not empty, do this..
	while (!stack.empty()) {

		// Pop a vertex from stack and print it
		s = stack.top();
		stack.pop();
		cout << s << " ";

		// adjacents of vertices are iterated in reversed order.
		// for each vertex, insert its last child first, and its first child last.
		for (i = adj[s].rbegin(); i != adj[s].rend(); ++i) {

			// if an adjacent has not been visited, mark it visited then push to stack.
			if (!visited[*i]) {
				visited[*i] = true;
				stack.push(*i);
			}
		}
	}
}

// PURPOSE: Driver program to test methods of graph class
// ALGORITHM: First, six edges are added between 4 vertices. Next bfs is tested using queue, 
//			  then recursive implementation of dfs is tested. Lastly, iterative implementation 
//			  of dfs is tested.
int main() {
	cout << "// Name: Chris Banci" << endl;
	cout << "// Assignment: HW6 - graph" << endl;
	cout << "// Date: 11/18/16" << endl << endl;


	// Adjacency List
	// |0|1|2|3| 
	// ---------
	// |1|2|0|3|
	// |2| |3| |

	// Create a graph given in the above diagram
	Graph g(4);					// graph object with 4 vertices.
	g.addEdge(0, 1);		
	g.addEdge(0, 2);		
	g.addEdge(1, 2);		
	g.addEdge(2, 0);		
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal(starting from vertex 2) \n";
	g.BFS(2);					// iterative implentation of BFS using queue.
	cout << endl;

	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
	g.DFS_recursive(2);			// recursive implementation of DFS.
	cout << endl;

	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
	g.DFS(2);					// iterative implementation of DFS using stack.
	cout << endl;

	return 0;
}