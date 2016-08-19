//Elias Muche 
// 4/15/16
//Program 2:Binary Search Tree

#include "bintree.h"
#include <iostream>
using namespace std;

	//-------- initialize -------
	//Takes an array of NodeData pointers and initializes their value to NULL
	//Pre-conditions: the length of the array must be no greater than 100
	//Post-conditions: the value of each pointer in the array will be NULL;
	void initialize(NodeData *Data[]){
		for(int i=0;i<100;i++){
			Data[i]=NULL;
		}
	}
	int main(){
		
		//testing default constructor 
		BinTree t;
		cout<<"After creating an empty tree, t is:"<<t<<endl;
		
		//testing insert for t
		NodeData *data=new NodeData("house");
		t.insert(data);
		data=new NodeData("car");
		t.insert(data);
		data=new NodeData("town");
		t.insert(data);
		data=new NodeData("acorn");
		t.insert(data);
		data=new NodeData("thunder");
		t.insert(data);
		data=new NodeData("lightning");
		t.insert(data);
		data=new NodeData("school");
		t.insert(data);
		data=new NodeData("boat");
		t.insert(data);
		data=new NodeData("zebra");
		t.insert(data);
		t.displaySideways();
		
		//displaying t
		cout<<"t in order is:    "<<t<<endl<<endl;
		
		//testing retrieve for t (data that is in the tree and data that is not in the tree)
		NodeData *retrieve;
		NodeData seek("house");
		cout<<"The variable:"<<seek<<" retrieved?  "<<t.retrieve(seek,retrieve)<<endl;
		cout<<"The variable retrieve is now:"<<*retrieve<<endl;
		NodeData seek2("castle");
		cout<<"The variable:"<<seek2<<" retrieved?  "<<t.retrieve(seek2,retrieve)<<endl;
		cout<<"The variable retrieve is now:"<<*retrieve<<endl<<endl;
		
		//testing get height for t(data that is in the tree and data that is not in the tree)
		NodeData boat("boat");
		NodeData zebra("zebra");
		NodeData town("town");
		NodeData house("house");
		NodeData notPresent("mansion");
		cout<<"The height of boat is:"<<t.getHeight(boat)<<endl;
		cout<<"The height of zebra is:"<<t.getHeight(zebra)<<endl;
		cout<<"The height of town is:"<<t.getHeight(town)<<endl;
		cout<<"The height of house is:"<<t.getHeight(house)<<endl;
		cout<<"The height of mansion is:"<<t.getHeight(notPresent)<<endl<<endl;


		//testing the copy constructor
		BinTree t2(t);

		//displaying t2
		cout<<"After making the copy of t using the copy constructor, t2 sideways is:"<<endl;
		t2.displaySideways();
		cout<<endl<<"t2 in order is:    "<<t2<<endl<<endl;
		
		//testing makeEmpty for t2
		t2.makeEmpty();
		cout<<endl<<"After emptying, t2 is:    "<<t2;

		//testing = for t2;
		t2=t2;
		cout<<"After doing t2=t2, t2 is:    "<<t2<<endl<<endl;
		t2=t;
		cout<<"After doing t2=t, t2 sideways is:"<<endl<<endl;
		t2.displaySideways();
		cout<<"t2 in order is:    "<<t2<<endl<<endl;

		//testing == and !=
		cout<<"t==t2 is: "<<(t==t2)<<endl;
		cout<<"t!=t2 is: "<<(t!=t2)<<endl<<endl;


		//adding a third tree 
		BinTree t3;
		data= new NodeData("dog");
		t3.insert(data);
		data=new NodeData ("giraffe");
		t3.insert(data);
		data=new NodeData("tiger");
		t3.insert(data);
		data=new NodeData("aardvark");
		t3.insert(data);
		data=new NodeData("moose");
		t3.insert(data);
		data=new NodeData("lion");
		t3.insert(data);
		data=new NodeData("cheetah");
		t3.insert(data);
		data=new NodeData("snail");
		t3.insert(data);
		data=new NodeData("sea lion");
		t3.insert(data);
		data=new NodeData("cow");
		t3.insert(data);
	
		//displaying t3
		cout<<"After adding some data, t3 sideways is:"<<endl;
		t3.displaySideways();
		cout<<endl<<"t3 in order is:    "<<t3<<endl<<endl;

		//adding an extremely unbalanced tree
		BinTree t4;
		data=new NodeData("Atlanta");
		t4.insert(data);
		data=new NodeData("Boston");
		t4.insert(data);
		data=new NodeData("Cleveland");
		t4.insert(data);
		data=new NodeData("Houston");
		t4.insert(data);
		data=new NodeData("Los Angeles");
		t4.insert(data);
		data=new NodeData("Montgomery");
		t4.insert(data);
		data=new NodeData("Seattle");
		t4.insert(data);

		//displaying t4
		cout<<"After adding some data, t4 sideways is:"<<endl;
		t4.displaySideways();
		cout<<endl<<"t4 in order is:    "<<t4<<endl;


		//comparing all of the trees
		
		cout<<"Going to compare all of the trees"<<endl<<endl;
		cout<<"Right now t in order is:    "<<t<<endl;
		cout<<"Right now t2 in order is:    "<<t2<<endl;
		cout<<"Right now t3 in order is:    "<<t3<<endl;
		cout<<"Right now t4 in order is:    "<<t4<<endl;
	
		//self comparison
		cout<<"t==t is: "<<(t==t)<<endl;
		cout<<"t2==t2 is: "<<(t2==t2)<<endl;
		cout<<"t3==t3 is: "<<(t3==t3)<<endl;
		cout<<"t4==t4 is: "<<(t4==t4)<<endl;
		cout<<"t!=t is: "<<(t!=t)<<endl;
		cout<<"t2!=t2 is: "<<(t2!=t2)<<endl;
		cout<<"t3!=t3 is: "<<(t3!=t3)<<endl;
		cout<<"t4!=t4 is: "<<(t4!=t4)<<endl<<endl;

		//non self comparison
		cout<<"t==t3 is: "<<(t==t3)<<endl;
		cout<<"t!=t3 is: "<<(t!=t3)<<endl;
		cout<<"t==t4 is: "<<(t==t4)<<endl;
		cout<<"t!=t4 is: "<<(t!=t4)<<endl;
		cout<<"t3==t4 is: "<<(t3==t4)<<endl;
		cout<<"t!=t4 is: "<<(t3!=t4)<<endl<<endl;
		
		//array declaration
		NodeData *Data[100];
		

		cout<<"Going to balance each tree by calling bsTreeToArray and arrayToBSTree"<<endl<<endl;
		
		//balancing 
		initialize(Data);
		cout<<"Before the balancing, t was:    "<<endl<<endl;
		t.displaySideways();
		cout<<endl<<endl;
		t.bstreeToArray(Data);
		t.arrayToBSTree(Data);
		cout<<"After balancing t is now:"<<endl<<endl;
		t.displaySideways();
		cout<<endl<<endl;

		cout<<"Not going to balance t2 because t and t2 have the same data (used the = operator earlier)"<<endl<<endl;

		//balancing t3
		initialize(Data);
		cout<<"Before the balancing, t3 was:    "<<endl<<endl;
		t3.displaySideways();
		cout<<endl<<endl;
		t3.bstreeToArray(Data);
		t3.arrayToBSTree(Data);
		cout<<"After balancing t3 is now:"<<endl<<endl;
		t3.displaySideways();
		cout<<endl<<endl;


		//balancing t4
		initialize(Data);
		cout<<"Before the balancing, t4 was:    "<<endl<<endl;
		t4.displaySideways();
		cout<<endl<<endl;
		t4.bstreeToArray(Data);
		t4.arrayToBSTree(Data);
		cout<<"After balancing t4 is now:"<<endl<<endl;
		t4.displaySideways();
	

		return 0;
	
	}
	
	
	