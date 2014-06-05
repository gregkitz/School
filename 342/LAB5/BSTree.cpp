#include "BSTree.h"
BSTree::BSTree(){
	root = NULL; 
}

BSTree::~BSTree(){

	delete root; 
	root = NULL; 
}

bool BSTree::insert(Client* dataptr) {
	TreeNode* ptr = new TreeNode;
	if (ptr == NULL) return false;            // out of memory
	ptr->client = dataptr;
	ptr->left = ptr->right = NULL;
	if (isEmpty()) {
		root = ptr;
	}
	else {
		TreeNode* current = root;                           // walking pointer
		bool inserted = false;                          // whether inserted yet

		// if item is less than current item, insert in left subtree,
		// otherwise insert in right subtree
		while (!inserted) {
			if (*ptr->client < *current->client) {
				if (current->left == NULL) {              // insert left
					current->left = ptr;
					inserted = true;
				}
				else
					current = current->left;               // one step left
			}
			else {
				if (current->right == NULL) {             // insert right
					current->right = ptr;
					inserted = true;
				}
				else
					current = current->right;              // one step right
			}
		}
	}
	return true;
}

void BSTree::display(){
	if (root != NULL){
		displayHelper(*root); 
	}

}

void BSTree::displayHelper(const TreeNode& node){
	node.client->displayID(); 
	if (node.left != NULL){
		displayHelper(*node.left);
	}
	
	if (node.right != NULL){
		displayHelper(*node.right);
	}

}
bool BSTree::isEmpty() {
	bool izEmpty = (root == NULL);
	return (root == NULL) ? true : false; 
}