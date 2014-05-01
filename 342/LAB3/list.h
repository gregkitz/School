// Greg Kitzmiller
// Zander 342
// Spring 14
// This templated class creates an ordered linked list. This class has 
// member functions which will allow the merging of two sorted lists 
// of the same type, finding the intersection of two sorted lists
// and standard linked list members (build, insert, isEmpty). 
// Additionally, this class has the functionality of passing a data
// item to the list for either removal from the list or retrieval, 
// where both of these member functions will return with a bool 
// value for if the data item was in the list. 
// Assumptions:  
//   -- Control of <, printing, etc. of T information is in the T class.  
//   -- There is no dummy head node, head points to first node.  
//      If the list is empty, head is NULL.
//   -- The insert allocates memory for a Node, ptr to the data is passed in.
//      Allocating memory and setting data is the responsibility of the caller.
//----------------------------------------------------------------------------

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
using namespace std;


template <typename T>
class List {

	// output operator for class List, print data, 
	// responsibility for output is left to object stored in the list
	friend ostream& operator<<(ostream& output, const List<T>& thelist) {
		Node* current = thelist.head;
		while (current != NULL) {

			output << *current->data;
			current = current->next;
		}

		return output;
	}

public:
	List();                             // default constructor
	~List();							// destructor
	List(const List&);                  // copy constructor
	bool insert(T*);                    // insert one Node into list
	bool isEmpty() const;               // is list empty?
	void buildList(ifstream&);          // build a list from datafile
	void makeEmpty();					// empties out a list
	bool remove(T, T*&);				// find a node in a list and remove it
	bool retrieve(T, T*&);				// find a node in the list 
	void merge(List&, List&);			// merges two sorted lists
	void intersect(const List&, const List&); //finds alike nodes
	
	//operators

	List& operator=(const List &);

	//boolean operators
	bool operator==(const List&) const;
	bool operator!=(const List&) const;


private:
	struct Node {            // the node in a linked list
		T* data;              // pointer to actual data, operations in T
		Node* next;
	};

	Node* head;              // pointer to first node in list
};


//----------------------------------------------------------------------------
// Constructor 
template <typename T>
List<T>::List() {
	head = NULL;
}

//----------------------------------------------------------------------------
// Destructor
// Preconditions: A list object is declared in memory 
// Iterates through a list and clears the data and node memory
template <typename T>
List<T>::~List(){
	this->makeEmpty();

}

//----------------------------------------------------------------------------
// Copy Constructor
// Parameter list must be an object of type List
// function iterates through the parameter list and creates a new list
// using the same data members
template <typename T>
List<T>::List(const List& toCopy){
	if (toCopy.isEmpty() != true){
		Node * rhsTransverse = toCopy.head;
		head = new Node;
		Node* lhsTransverse = head;

		while (rhsTransverse != NULL){
			lhsTransverse->data = new T;
			*lhsTransverse->data = *rhsTransverse->data;
			if (rhsTransverse->next == NULL){
				lhsTransverse->next = NULL;
				break;
			}
			Node * ptr = new Node;
			lhsTransverse->next = ptr;


			lhsTransverse = lhsTransverse->next;
			rhsTransverse = rhsTransverse->next;

		}



	}

}
//----------------------------------------------------------------------------
// make empty
// Empties out a list by looping through it and deleting the data 
// and node objects. 
template <typename T>
void List<T>::makeEmpty(){
	if (head != NULL){
		Node* current = head;
			while (current != NULL) {    //exits at the null item at the end
			Node* next = current->next;
			delete current->data;
			current->data = NULL;
			delete current;
			current = next;
		}
		
		head = NULL;

	}
}
//----------------------------------------------------------------------------
// isEmpty 
// check to see if List is empty as defined by a NULL head
template <typename T>
bool List<T>::isEmpty() const {
	return head == NULL;
}

//----------------------------------------------------------------------------
// insert 
// insert an item into list; operator< of the T class
// has the responsibility for the sorting criteria
template <typename T>
bool List<T>::insert(T* dataptr) {

	Node* ptr = new Node;
	if (ptr == NULL) return false;                 // out of memory, bail
	ptr->data = dataptr;                           // link the node to data

	// if the list is empty or if the node should be inserted before 
	// the first node of the list
	if (isEmpty() || *ptr->data < *head->data) {
		ptr->next = head;
		head = ptr;
	}

	// then check the rest of the list until we find where it belongs 
	else {
		Node* current = head->next;          // to walk list
		Node* previous = head;               // to walk list, lags behind

		// walk until end of the list or found position to insert
		while (current != NULL && *current->data < *ptr->data) {
			previous = current;                  // walk to next node
			current = current->next;
		}

		// insert new node, link it in
		ptr->next = current;
		previous->next = ptr;
	}
	return true;
}

//----------------------------------------------------------------------------
// buildList 
// continually insert new items into the list
template <typename T>
void List<T>::buildList(ifstream& infile) {
	T* ptr;
	bool successfulRead;                            // read good data
	bool success;                                   // successfully insert
	for (;;) {
		ptr = new T;
		successfulRead = ptr->setData(infile);       // fill the T object
		if (infile.eof()) {
			delete ptr;
			break;
		}

		// insert good data into the list, otherwise ignore it
		if (successfulRead) {
			success = insert(ptr);
		}
		else {
			delete ptr;
		}
		if (!success) break;
	}
}
//----------------------------------------------------------------------------
// operator=
// Assigns the righthand object to the lefthand object
// Tests for self-assignment and doesn't run if it is a  self-assignment. 
// Empties out the current list then makes a deep copy
template <typename T>
List<T>& List<T>::operator=(const List<T>& toCopy){
	if (&toCopy != this){


		if (toCopy.isEmpty() != true){
			this->makeEmpty();
			Node * rhsTransverse = toCopy.head;
			head = new Node;
			Node* lhsTransverse = head;

			while (rhsTransverse != NULL){ // while the right list isn't empty
				lhsTransverse->data = new T;
				*lhsTransverse->data = *rhsTransverse->data; //memberwise-copy
				if (rhsTransverse->next == NULL){
					lhsTransverse->next = NULL;
					break; //ends the inserting and caps off new list
				}
				Node * ptr = new Node;
				lhsTransverse->next = ptr;
				lhsTransverse = lhsTransverse->next;
				rhsTransverse = rhsTransverse->next;

			}



		}
	}
	return *this; //returns the address of the newly copied list
}
//----------------------------------------------------------------------------
// operator ==
// Boolean comparison for if the lists are equal. 
// Loops through both lists and returns false if a mismatch is find, 
// otherwise, returns true. 
template <typename T>
bool List<T>::operator==(const List& rhs) const{
	Node * rhsIterator = rhs.head;
	Node * lhsIterator = head;
	while (rhsIterator != NULL){
		if (*rhsIterator->data != *lhsIterator->data){ //tests for mismatch
			return false;
		}
		rhsIterator = rhsIterator->next;
		lhsIterator = lhsIterator->next;
	}
	return true;
}
//----------------------------------------------------------------------------
// opearator !=
// Reuses the code from == and returns the opposite. 
template <typename T>
bool List<T>::operator!=(const List& rhs) const{
	return *this == rhs ? false : true;

}

//----------------------------------------------------------------------------
// remove
// returns boolean value for whether the wanted item is in the list
// checks the head first. Otherwise, steps through and returns true if 
// found, otherwise false. 

template <typename T>
bool List<T>::remove(T toFind, T*& found){
	Node * next = head->next;
	if (*head->data == toFind){
		found = head->data;
		if (head->next != NULL){
			head = head->next;
		}
		
		return true; //if the data is the head, return true
	}
	while (next != NULL){ //otherwise, step through looking for it
		if (*next->data == toFind){
			found = next->data;
			return true;

		}

		
		next = next->next;

	}
	found = NULL;  //if it's not in the list null out the second parameter
	return false; 

}

//----------------------------------------------------------------------------
// retrieve
// steps through a list looking for the desired value
// if it's found it sets the found pointer to point to the object
// and returns a boolean value of true
// otherwise, returns a boolean value of false
template <typename T>
bool List<T>::retrieve(T toFind, T*& found){
	Node * current = head;

	while (current != NULL){
		if (*current->data == toFind){
			found = current->data;
			return true;
		}
		current = current->next;
	}
	return false;
}
//----------------------------------------------------------------------------
// merge
// Takes two sorted lists and merges them into one, then clears out the 
// two sorted lists unless one of them is itself. 
// The method of doing this is comparing the lists from left to right and 
// inserting the smaller, or arbirarily the left if they're equal and 
// continuing to insert the smaller of the two. 


template <typename T>
void List<T>::merge(List& lhs, List& rhs){
	if (this != &lhs && this != &rhs){ //only make empty if neither are this 
		this->makeEmpty();
	}


	Node * iterator = NULL;
	Node * iteratorInsert = NULL;
	Node * lhsTransverse = lhs.head;
	Node * rhsTransverse = rhs.head;
	bool first = true; 

	//keep merging while either are not null
	while (lhsTransverse != NULL || rhsTransverse != NULL){
		if (lhsTransverse != NULL && rhsTransverse != NULL){ //if they're both
															// not null
			if (*lhsTransverse->data < *rhsTransverse->data){
				if (first){
					iterator = lhsTransverse; 
					iteratorInsert = iterator; 
					lhsTransverse = lhsTransverse->next; 
					first = false; 
				}
				else{
					iterator->next = lhsTransverse;
					lhsTransverse = lhsTransverse->next;
					iterator = iterator->next;
				}
			

			}
			//if the righthand list is smaller 
			else if (*lhsTransverse->data > *rhsTransverse->data){
				if (first){
					iterator = lhsTransverse;
					iteratorInsert = iterator;
					lhsTransverse = lhsTransverse->next;
					first = false;
				}
				else{
					iterator->next = rhsTransverse;
					rhsTransverse = rhsTransverse->next;
					iterator = iterator->next;
				}
			}
			else {
				if (first){
					iterator = lhsTransverse;
					iteratorInsert = iterator;
					lhsTransverse = lhsTransverse->next;
					first = false;
				}
				else{
					iterator->next = lhsTransverse;
					lhsTransverse = lhsTransverse->next;
					iterator = iterator->next;
				}
			}
		}
		//if only the left hand list is null
		else if (lhsTransverse == NULL && rhsTransverse != NULL){
			if (first){
				iterator = rhsTransverse;
				rhsTransverse = rhsTransverse->next; 
				iteratorInsert = iterator;
				first = false;
			}
			else{
				iterator->next = rhsTransverse;
				rhsTransverse = rhsTransverse->next;
				iterator = iterator->next;
			}
		}
		// otherwise, if only the righthand list is null
		else{
			if (first){
				iterator = lhsTransverse;
				iteratorInsert = iterator;
				lhsTransverse = lhsTransverse->next;
				first = false;
			}
			else{
				iterator->next = lhsTransverse;
				lhsTransverse = lhsTransverse->next;
				iterator = iterator->next;
			}
		}

	}
	lhs.head = NULL;
	rhs.head = NULL;
	head = iteratorInsert;
	

}
//----------------------------------------------------------------------------
//intersect
//creates a new list of the the current list which has the common elements
//between the two parameter lists. 
// Algorithm is comparing the lists from left to right and iterating 
// what comes out smaller of the two comparisons or if they're equal
// arbitrarily iterating one of the the lists. 
template <typename T>
void List<T>::intersect(const List& lhs, const List& rhs){

	if (this != &lhs && this != &rhs){ //only make empty if *this list
		this->makeEmpty();			   //is not involved
	}

	Node * intersectList = new Node; 
	intersectList->data = new T; 
	Node * tempHead = intersectList; 
	Node * lhsIterator = lhs.head;
	Node * rhsIterator = rhs.head; 
	bool first = false; 
	//if one of them is empty then there can't be an intersect
	while (lhsIterator != NULL && rhsIterator != NULL){
		if (*lhsIterator->data == *rhsIterator->data){
			
			intersectList->next = new Node;
			intersectList = intersectList->next;
			intersectList->data = new T;
			*intersectList->data = *lhsIterator->data;
			
			
		}
		//increment the smaller of the two lists
		if (*lhsIterator->data < *rhsIterator->data){
			lhsIterator = lhsIterator->next; 
		}
		else{
			rhsIterator = rhsIterator->next; 

		}
	}
	
	intersectList->next = NULL; 
	head = tempHead->next; 
	delete tempHead->data; 
	delete tempHead; 



}
#endif
