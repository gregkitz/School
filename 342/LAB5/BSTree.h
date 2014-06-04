#ifndef BSTREE_H
#define BSTREE_H

#include <iostream> 
using namespace std; 

#include "Client.h"
#include "TreeNode.h"

class BSTree {
public:
	/*BSTree();
	~BSTree();*/ // calls makeEmpty which deallocates all memory 
	// insert object into the tree, parameter holds pointer to object to insert 
	bool insert(Client*);
	// retrieve object, first parameter is object to retrieve 
	// second parameter holds pointer to found object, NULL if not found 
	bool retrieve(const Client&, Client*&)const;
	void display()const; //displays the contents of a tree to cout 
	void makeEmpty(); //empties the current tree, deallocates all memory 
	bool isEmpty()const; //returns true if tree is empty 
	
private:
	TreeNode * root; 

	
};

#endif 