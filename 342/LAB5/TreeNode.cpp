#include "TreeNode.h"

TreeNode::TreeNode(){
	left = NULL; 
	right = NULL; 
	client = NULL; 

}

TreeNode::~TreeNode(){
	delete client; 
	delete left; 
	delete right; 
	client = NULL; 
	left = NULL; 
	right = NULL; 
}