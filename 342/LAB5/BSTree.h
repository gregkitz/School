#ifndef BSTREE_H
#define BSTREE_H

#include <iostream> 
using namespace std; 

#include "Client.h"
#include "TreeNode.h"

class BSTree {
public:
	BSTree();
	~BSTree();// calls makeEmpty which deallocates all memory 
	// insert object into the tree, parameter holds pointer to object to insert 
	bool insert(Client*);
	// retrieve object, first parameter is object to retrieve 
	// second parameter holds pointer to found object, NULL if not found 
	bool retrieve(const Client&, Client*&)const;
	void display(); //displays the contents of a tree to cout 
	void makeEmpty(); //empties the current tree, deallocates all memory 
	bool isEmpty(); //returns true if tree is empty 
	
private:
	TreeNode * root; 
	void displayHelper(const TreeNode&);
	bool retrieveHelper(const TreeNode*, const Client&, Client*&) const;

	
};

#endif 