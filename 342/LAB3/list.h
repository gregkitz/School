/////////////////////////  listtemplate.h file  //////////////////////////////
// Simple linked list, uses Node as linked list node

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
using namespace std;

//--------------------------  class List  ------------------------------------
// ADT List: finite, ordered collection of zero or more items.
//           The ordering is determined by operator< of T class.
//          
// Assumptions:  
//   -- Control of <, printing, etc. of T information is in the T class.  
//   -- There is no dummy head node, head points to first node.  
//      If the list is empty, head is NULL.
//   -- The insert allocates memory for a Node, ptr to the data is passed in.
//      Allocating memory and setting data is the responsibility of the caller.
//
// Note this definition is not a complete class and is not fully documented.
//----------------------------------------------------------------------------

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
   List();                               // default constructor
   // ~List();                           // destructor
   // List(const List&);                 // copy constructor
   bool insert(T*);                      // insert one Node into list
   bool isEmpty() const;                 // is list empty?
   void buildList(ifstream&);            // build a list from datafile

   // needs many more member functions to become a complete ADT

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

   Node* ptr= new Node;
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

#endif

