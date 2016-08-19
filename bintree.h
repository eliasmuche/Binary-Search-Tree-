//Elias Muche 
//4-6-16
//Program 2 Binary Search Tree

#pragma once 
#include "nodedata.h"
class BinTree {				// you add class/method comments and assumptions
	//-------------- <<Overload --------------
	//Overloads the << operator
	//Will call inOrderHelper() to print out the tree in order 
	//Pre-conditions:the tree object must not be null 
	//Post-conditions: the param will not be changed 
	friend ostream& operator<< (ostream& out, const BinTree& tree);
public:
	//------------------------- Default Constructor ---------------------------------
	//Initializes the tree to be empty
    //Pre-conditions: none 
    //Post-conditions: root will be null 
	BinTree();							

	//------------------------- Copy Constructor ---------------------------------
	//Takes in a BinTree and creates a deep copy of it
	//Pre-conditions: the parameter's root must not be null
	//Post-conditions: The trees should match (number of nodes, location of nodes, and node data)
	BinTree(const BinTree &tree);		

	//----------------------- Destructor --------------------
	//De-Allocates the nodes in a the current tree 
	//Pre-conditions: none 
	//Post-condition: there should be no nodes including the root	
	~BinTree();				

	//--------------------- IsEmpty ----------------
	//Checks if the tree is empty 
	//Returns true if it's empty, false otherwise 
	//Pre-conditions:none
	//Post-conditions: true or false will be returned and this won't be changed 					
	bool isEmpty() const;					

	//-------------- makeEmpty --------------------
	//Removes all of the nodes in the tree 
	//Pre-conditions: root must not be null
	//Post conditions: there should be nodes except root
	void makeEmpty();						

	//----------------- =Overload ------------------
	//Overloads the = operator
	//Takes another BinTree and creates deep copy of it
	//Pre-conditions: none
	//Post-conditions: both trees should have the same data (value, and location)
	BinTree& operator=(const BinTree & tree);

	//------------- ==Overload ----------------
	//Takes two BinTrees and checks if they are equal in value 
	//Returns true if they're equal, false otherwise 
	//Pre-conditions: none
	//Post-conditions: true or false will be returned and the param and this won't be changed 
	bool operator==(const BinTree &tree) const;

	//------------- !=Overload ----------------
	//Takes two BinTrees and checks if they are not equal in value 
	//Returns true if they're not equal, false otherwise 
	//Pre-conditions: both roots must not be null
	//Post-conditions: true or false will be returned and the param and this won't be changed 
	bool operator!=(const BinTree &tree) const;

	//------------ Insert --------------
	//Takes a NodeData as a param and inserts  a new node into the tree with the param as the data 
	//Returns true if a new node was inserted, false otherwise
	//Pre-conditions: the param must not be null 
	//Post-conditions: a new node may or may not be inserted 
	bool insert(NodeData*);

	//------------------ Retrieve ----------------------
	//Method takes 2 NodeData parameters 
	//First is the data that is being retrieved
	//Second is initially empty but will contain the data being searched for if it is found
	//Returns true if the data was found, returns false otherwise
	//Pre-conditions: none
	//Post-conditions: true or false is returned and the second param might contain the data if its retrieved and this will remain unchanged
	bool retrieve(const NodeData &data, NodeData *&retrieved) const;

	//------------------------- DisplaySideways ---------------------------------
	// Displays a binary tree as though you are viewing it from the side;
	// Hard coded displaying to standard output.
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void displaySideways() const;			

	//------------ getHeight ---------------
	//Gets the height of a node of the tree  
	//Returns the height of that node 
	//Pre-conditions: none
	//Post-conditions: an integer will be returned and the tree will remain unchanged as well was the param
	int getHeight (const NodeData &) const;

	//----------- BstreeToArray -------------
	//This method takes in an array of NodeData objects and fills it with the nodes in the tree in order 
	//Clears the tree as the nodes are being transferred
	//Pre-conditions: none 
	//Post-conditions: there should be no more nodes left in the tree and the array should have the tree's nodes in order
	void bstreeToArray(NodeData* a[]); 

	//---------- ArrayToBstree --------------
	//This method takes in an array of NodeData objects and creates a balanced tree based off of its elements
	//Pre-conditions: the pointers of the array should not be null
	//Post-conditions: there should be no elements left in the array and the tree should have the elements as nodes 
	void arrayToBSTree(NodeData* a[]);
	
private:
	struct Node {
		NodeData* data=NULL;						// pointer to data object
		Node* left=NULL;							// left subtree pointer
		Node* right=NULL;						    // right subtree pointer
	};
	Node* root=NULL;								        // root of the tree

    // utility functions  

	//------------- InorderHelper ----------------
	//Private helper recursive method
	//Displays the tree using an in order traversal
	//Pre-conditions: none 
	//Post-conditions: the tree must be unchanged 
    void inorderHelper( Node *rooot,ostream &out) const;

	//---------------------------- Sideways -------------------------------------
	// Helper method for displaySideways
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
    void sideways(Node*, int) const;			

	//------------ Insert Overload ----------------
	//Overload of the insert method
	//Takes a Node (the current node) and a NodeData(passed in by the other insert method)
	//The method is recursive
	//Adds a new new node with the param as its data if the data wasn't already in the tree 
	//Returns true if a new node was added, false otherwise(data was already in the tree)
	//Pre-conditions: the data must not be null 
	//Post-conditions: a new term will be added or nothing is changed (true or false is returned)
    bool insert(Node *&root,NodeData *data);

	//-------- Equals -----------
	//Private recursive method that checks if two trees are equal
	//Will be called by ==
	//Returns true if the trees are equal, returns false otherwise 
	//Pre-conditions: none 
	//Post-conditions: true or false will be returned and both trees will remain unchanged
    bool equals(Node *&thisNode, Node *&rhs)const;

	//------------ getToNode --------------
	//Private recursive helper method that will be called from getHeight(original not overloaded)
	//Takes in a node that will be used to traverse the tree
	//Takes a node that will store the node in the tree being searched for
	//Takes a NodeData that will be used to determine if the correct node has been reached
	//Pre-conditions: none
	//Post-condistions: the tree will remain unchanged 
	void getToNode(Node *&node, Node *&returnVal, const NodeData &)const;

	//------------ getHeight Overload ---------------
	//Overload of getHeight
	//Is private and recursive
	//Takes a parent node as a parameter
	//Returns the height of the subtree of that node 
	//Pre-conditions: none
	//Post-conditions:an integer will be returned and the tree will remain unchanged
	int getHeight(Node *&node)const;

	//------------ getHeight Overload ---------------
	//Overload of getHeight
	//Is private and recursive
	//Takes a parent node as a parameter
	//Returns the height of the subtree of that node 
	//Pre-conditions: none
	//Post-conditions:an integer will be returned and the tree will remain unchanged
	void clear(Node *&parent);

	//-------------- AssignEq ------------------
	//Private recursive helper method will be used by =
	//Takes two nodes (from two different trees) and creates a copy of the first param 
	//Pre-conditions: none
	//Post-conditions: The nodes of this should match the nodes of the rhs tree (value and location)
	void assignEq(Node *rhs, Node*&mine);

	//--------- AddToArray ------------
	//Private recursive helper method 
	//Will be called from bstreeToArray
	//Takes in a current node, an array and an index 
	//Adds the current node into the array
	//Pre-conditions: root must not be null
	//Post-conditions: the tree will be empty and the array will be filled with the tree's data
	void addToArray(Node *node,NodeData *a[], int &index);

	//--------- addToTree -----------
	//Private recursive helper method
	//Will be called from arrayToBSTree
	//Takes in a sorted array containing DataNodes, the first index, and last index of the current range 
	//Creates a balanced tree based off content of the array  
	//Pre-conditions: none
	//Post-conditions: The tree will be balanced and contain the content of the array if the array wasn't empty
	void addToTree(NodeData *a[], int first, int last);
		
};

