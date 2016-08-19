//Elias Muche 
//4-6-16
//Program 2 Binary Search Tree

#include "bintree.h"
#include <iostream>
using namespace std;

	//-------------- <<Overload --------------
	//Overloads the << operator
	//Will call inOrderHelper() to print out the tree in order 
	//Pre-conditions:the tree object must not be null 
	//Post-conditions: the param will not be changed 
	ostream& operator<< (ostream& out, const BinTree& tree){
		if(tree.root==NULL){//print empty and stop if the tree is empty 
			out<<"Empty"<<endl;
			return out;
		}
		tree.inorderHelper(tree.root,out);//print the tree in order 
		out<<endl;
		return out;
	}

	//------------------------- Default Constructor ---------------------------------
	//Initializes the tree to be empty
    //Pre-conditions: none 
    //Post-conditions: root will be null 
	BinTree::BinTree(){
		
	}
	
	//------------------------- Copy Constructor ---------------------------------
	//Takes in a BinTree and creates a deep copy of it
	//Pre-conditions: the parameter's root must not be null
	//Post-conditions: The trees should match (number of nodes, location of nodes, and node data)
	BinTree::BinTree(const BinTree& tree){
		if(tree.root==NULL){//if the tree is empty, stop
			return;
		}
		*this=tree;//use the equals operator 
	}

	//----------------------- Destructor --------------------
	//De-Allocates the nodes in a the current tree 
	//Pre-conditions: none 
	//Post-condition: there should be no nodes including the root
    BinTree::~BinTree(){
		if(root==NULL){//if the tree is empty, do nothing
			return;
		}
		clear(root);//clear all the nodes 
	}

	//--------------------- IsEmpty ----------------
	//Checks if the tree is empty 
	//Returns true if it's empty, false otherwise 
	//Pre-conditions:none
	//Post-conditions: true or false will be returned and this won't be changed 
	bool BinTree::isEmpty()const{
	    return root==NULL;
	}

	//-------------- makeEmpty --------------------
	//Removes all of the nodes in the tree 
	//Pre-conditions: root must not be null
	//Post conditions: there should be nodes except root
	void BinTree::makeEmpty(){
		clear(root);//call the clear helper method
		
	}

	//----------------- =Overload ------------------
	//Overloads the = operator
	//Takes another BinTree and creates deep copy of it
	//Pre-conditions: none
	//Post-conditions: both trees should have the same data (value, and location)
	BinTree& BinTree::operator=(const BinTree& tree){
		if(this==&tree){//if self assignment was used
			return *this;//just return this 
		}
	
		//at this point self assignment wasn't used
		clear(root);//clear the tree 
		Node *rhs=tree.root;//start at the root of the param's tree
		assignEq(rhs,root);//call the helper method 
		rhs=NULL;//memory leaks 
		return *this;
	}

	//------------- ==Overload ----------------
	//Takes two BinTrees and checks if they are equal in value 
	//Returns true if they're equal, false otherwise 
	//Pre-conditions: none
	//Post-conditions: true or false will be returned and the param and this won't be changed 
	bool BinTree:: operator==(const BinTree& tree)const{
	    Node *mine=root;//will examine *this nodes 
        Node *rhs=tree.root;//will examine the param's nodes 
		bool equal=equals(mine,rhs);//call the private helper method
		mine=NULL;//memory leaks 
		rhs=NULL;//memory leaks
	    return equal;
	} 

	//------------- !=Overload ----------------
	//Takes two BinTrees and checks if they are not equal in value 
	//Returns true if they're not equal, false otherwise 
	//Pre-conditions: both roots must not be null
	//Post-conditions: true or false will be returned and the param and this won't be changed 
	bool BinTree:: operator!=(const BinTree& tree)const{
	    return !(*this==tree);//return the negation of ==
	} 

	//------------ Insert --------------
	//Takes a NodeData as a param and inserts  a new node into the tree with the param as the data 
	//Returns true if a new node was inserted, false otherwise
	//Pre-conditions: the param must not be null 
	//Post-conditions: a new node may or may not be inserted 
	bool BinTree:: insert(NodeData *data){
		if(data==NULL){//stop if the param is null
			return false;
		}
		if(root==NULL){//if the root has no data 
			root=new Node;//create a new node
			root->left=NULL;//initialize
			root->right=NULL;//initialize
		    root->data=data;//set the data 
			return true;//success 
		}
		//at this point root already has data 
		if(*(root->data)>*data){//if roots data is bigger than the param 
			return insert(root->left,data);//call the recursive insert using the left subtree
		}
		else if(*(root->data)<*data){//if root's data is smaller than the param 
			return insert(root->right, data);//call the recursive insert using the right subtree 
		}
		else{//root's data was equal to the param so do nothing (no duplicates)
	    	return false;

		}
	}

	//------------------ Retrieve ----------------------
	//Method takes 2 NodeData parameters 
	//First is the data that is being retrieved
	//Second is initially empty but will contain the data being searched for if it is found
	//Returns true if the data was found, returns false otherwise
	//Pre-conditions: none
	//Post-conditions: true or false is returned and the second param might contain the data if its retrieved and this will remain unchanged
	bool BinTree::retrieve(const NodeData &data, NodeData *&retrieved)const{
	    Node *search=root;//create a search node 
	   	while(search!=NULL){//while the end of the tree hasn't been reached 
			if(*(search->data)==data){//if the data was found 
				retrieved=search->data;//save it
				search=NULL;//memory leaks 
				return true;//success
			}
			else if(*(search->data)>data){//if the current node's data is bigger than the param 
			    search=search->left;//move left

			}
			else{//if the current node's data is smaller than the param
				search=search->right;//move right
			}
		}
		//at this point the data wasn't in the tree
		search=NULL;//for memory leaks 
		return false;

	}


	
	//------------------------- DisplaySideways ---------------------------------
	// Displays a binary tree as though you are viewing it from the side;
	// Hard coded displaying to standard output.
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void BinTree::displaySideways() const {
		sideways(root, 0);
	}

	//---------------------------- Sideways -------------------------------------
	// Helper method for displaySideways
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void BinTree::sideways(Node* current, int level) const {
		
		if (current != NULL) {
			level++;
			sideways(current->right, level);

			// indent for readability, 4 spaces per depth level 
			for (int i = level; i >= 0; i--) {
				cout << "    ";
			}

			cout << *current->data << endl;        // display information of object
			sideways(current->left, level);
		}

	}

	//------------ Insert Overload ----------------
	//Overload of the insert method
	//Takes a Node (the current node) and a NodeData(passed in by the other insert method)
	//The method is recursive
	//Adds a new new node with the param as its data if the data wasn't already in the tree 
	//Returns true if a new node was added, false otherwise(data was already in the tree)
	//Pre-conditions: the data must not be null 
	//Post-conditions: a new term will be added or nothing is changed (true or false is returned)
	bool BinTree::insert(Node *&rooot, NodeData *data){
		if(rooot==NULL){//if the param is null, this is the right location to insert 
			rooot=new Node;//create a new node
			rooot->data=data;//set the data
			rooot->left=NULL;//initialize 
			rooot->right=NULL;//initialize 
			return true;//success 
		}
		else if(*(rooot->data)>*data){//if rooot's data is bigger than the param 
			return insert(rooot->left, data);//go left 
		
		}

		else if(*(rooot->data)<*data){//if rooot's data is samller than the param  
			return insert(rooot->right, data);//go right
		}

		
		//the data is equal so return false because duplicates aren't allowed
		return false;//couldn't insert

	}

	//-------- Equals -----------
	//Private recursive method that checks if two trees are equal
	//Will be called by ==
	//Returns true if the trees are equal, returns false otherwise 
	//Pre-conditions: none 
	//Post-conditions: true or false will be returned and both trees will remain unchanged
	bool BinTree:: equals(Node *&thisNode, Node *&rhs)const{
		if(thisNode==NULL && rhs==NULL){//if both nodes are null
		    return true;//they are equal
		}
		else if(thisNode!=NULL && rhs!=NULL){//if both nodes aren't null 
		    if(*(thisNode->data)==*(rhs->data)){//if both nodes have the same data 
			    bool left=equals(thisNode->left,rhs->left);//check the left subtree 
				bool right=equals(thisNode->right,rhs->right);//check the right subtree 
				return (left && right);//if both subtrees are equal return true 
			}
			else{//the data in the nodes aren't equal so return false
			    return false;
			}
		}
		//at this point only one node is null so they aren't equal
		return false;
	
	} 


	//------------ getHeight ---------------
	//Gets the height of a node of the tree  
	//Returns the height of that node 
	//Pre-conditions: none
	//Post-conditions: an integer will be returned and the tree will remain unchanged as well was the param
	int BinTree:: getHeight(const NodeData &data)const{
		if(root==NULL){
			return 0;
		}
		Node *temp=root;//will start at root and will be used to find the right node to call the private getHeight
		Node *temp2=root;//will store the node(if it exists) that will be used as a param for the private getHeight 
		getToNode(temp,temp2, data);//find the node that has the correct data
		if(*(temp2->data)!=data){//if the correct node doesn't exist
			temp=NULL;//memory leaks 
			return 0;//stop and return 0 (indicates that the data wasn't in the tree)
		}
		//at this point, the node exists 
		int height=getHeight(temp2);//get the height of subtree that starts at temp2
		temp=NULL;//memory leaks
		temp2=NULL;//memory leaks
		return height;
	}

	//------------ getHeight Overload ---------------
	//Overload of getHeight
	//Is private and recursive
	//Takes a parent node as a parameter
	//Returns the height of the subtree of that node 
	//Pre-conditions: none
	//Post-conditions:an integer will be returned and the tree will remain unchanged
	int BinTree::getHeight(Node *&node)const{
		if(node==NULL){//if there's no nodes left in this subtree stop
			return 0;
		}	
		int left=1+getHeight(node->left);//get the height of the left subtree
		int right=1+getHeight(node->right);//get the height of the right subtree
		
 
		return (left>=right)? left:right;//return the height of the subtree that's longer
	}
	
	//------------ getToNode --------------
	//Private recursive helper method that will be called from getHeight(original not overloaded)
	//Takes in a node that will be used to traverse the tree
	//Takes a node that will store the node in the tree being searched for
	//Takes a NodeData that will be used to determine if the correct node has been reached
	//Pre-conditions: none
	//Post-condistions: the tree will remain unchanged 
	void BinTree::getToNode(Node *&node, Node *&returnVal, const NodeData &data )const{
		if(node==NULL){//if the node is null stop 
			return;
		}
		if(*(node->data)==data){//if we are at the right node 
			returnVal=node;//change the value of the second param to remember it and stop 	
			return;
		}
		//at this point we have to search the subtrees 
		getToNode(node->left,returnVal,data);//search the left subtree
		if(*(returnVal->data)==data){//if it was in the left subtree 
			return;//do not search the right subtree 
		}	
		//at this point it wasnt in the left subtree
		getToNode(node->right,returnVal,data);//search the right subtree
	}

	
	//------------ Clear ------------
	//Private recursive helper method
	//Will be used by the destructor and by makeEmpty to empty the tree
	//Pre-conditions: none
	//Post-conditions: there will be no nodes as well as nodedatas  
	void BinTree::clear(Node*&parent){
		if(parent==NULL){//if the param is null 
			return;//stop
		}
		clear(parent->left);//othwerise go all the way left
		clear(parent->right);//and go all the way right 
		
		delete parent->data;//delete the parents data 
		parent->data=NULL;//memory leaks
		
		delete parent;//delete it
		parent=NULL;//memory leaks
		
	}

	//-------------- AssignEq ------------------
	//Private recursive helper method will be used by =
	//Takes two nodes (from two different trees) and creates a copy of the first param 
	//Pre-conditions: none
	//Post-conditions: The nodes of this should match the nodes of the rhs tree (value and location)
	void BinTree:: assignEq(Node *rhs, Node*&mine){
    	if(rhs==NULL){//if the param is null, stop
			return;
		}
		if(mine==NULL){//if the right location has been reached
			mine=new Node;//create a new node 
			mine->data=new NodeData(*rhs->data);//set the data 
			mine->left=NULL;//initialize 
			mine->right=NULL;//initialize
		}   
		else if(*(mine->data)>*(rhs->data)){//if the param's data is smaller than the current node's data
	    	assignEq(rhs,mine->left);//go left

		}

		else if(*(mine->data)<*(rhs->data)){//if the param's data is bigger than the current node's data
			assignEq(rhs,mine->right);//go right
		}

		
		assignEq(rhs->left,root);//repeat this process for the param's left subtree 
		assignEq(rhs->right,root);//repeat this process for the param's right subtree
			
		
	}

	//------------- InorderHelper ----------------
	//Private helper recursive method
	//Displays the tree using an in order traversal
	//Pre-conditions: none 
	//Post-conditions: the tree must be unchanged 
	void BinTree::inorderHelper( Node *rooot, ostream &out) const{
		if(rooot==NULL){//stop if there's no node 
			return;
		}
		inorderHelper(rooot->left,out);//print the left subtree first 
		out<<*(rooot->data)<<"    ";//print this 
		inorderHelper(rooot->right,out);//then print the right subtree

	}

	//----------- BstreeToArray -------------
	//This method takes in an array of NodeData objects and fills it with the nodes in the tree in order 
	//Clears the tree as the nodes are being transferred
	//Pre-conditions: none 
	//Post-conditions: there should be no more nodes left in the tree and the array should have the tree's nodes in order
	void BinTree::bstreeToArray(NodeData *a[]){
		if(root==NULL){//if the tree is empty, stop
			return;
		}
		int i=0;//will be used as an index
		addToArray(root,a,i);//call the helper method to put the items into the array in order
	}
	
	//---------- ArrayToBstree --------------
	//This method takes in an array of NodeData objects and creates a balanced tree based off of its elements
	//Pre-conditions: the pointers of the array should not be null
	//Post-conditions: there should be no elements left in the array and the tree should have the elements as nodes 
	void BinTree::arrayToBSTree(NodeData *a[]){
		int last=0;//will store the index of the last non-null item of the array 
		for(int i=0;i<100;i++){//loop through the entire array
			if(a[i]!=NULL){//if theres data in the current element
				last=i;//save the index
			}
		}
		clear(root);
		addToTree(a,0,last);
	}

	//--------- AddToArray ------------
	//Private recursive helper method 
	//Will be called from bstreeToArray
	//Takes in a current node, an array and an index 
	//Adds the current node into the array
	//Pre-conditions: root must not be null
	//Post-conditions: the tree will be empty and the array will be filled with the tree's data 
	void BinTree::addToArray(Node *node,NodeData *a[],int &index){
		if(node==NULL){//if there's no current node, stop
			return;
		}
		addToArray(node->left,a,index);//add the left first
		a[index]=node->data;/////change
		node->data=NULL;
		index+=1;
		addToArray(node->right,a,index);//then add the right last
	
	}

	//--------- addToTree -----------
	//Private recursive helper method
	//Will be called from arrayToBSTree
	//Takes in a sorted array containing DataNodes, the first index, and last index of the current range 
	//Creates a balanced tree based off content of the array  
	//Pre-conditions: none
	//Post-conditions: The tree will be balanced and contain the content of the array if the array wasn't empty 
	void BinTree::addToTree(NodeData *a[], int first, int last){
		if(last<first || first>last){
			return;
		}
		int root=(first+last)/2;
		insert(a[root]);
		a[root]=NULL;
		addToTree(a,first,root-1);
		addToTree(a,root+1,last);

	}






	