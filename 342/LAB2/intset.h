// 

#ifndef IntSet_H
#define IntSet_H
#include <iostream>
using namespace std; 


class IntSet {
	friend ostream& operator<<(ostream&, const IntSet&);
	friend istream& operator>>(istream&, IntSet&);

public: 
// default constructor 
	IntSet();
// overloaded constructors
	IntSet(int a);
	IntSet(int a, int b);
	IntSet(int a, int b, int c);
	IntSet(int a, int b, int c, int d);
	IntSet(int a, int b, int c, int d, int e);

// copy constructor 
	IntSet(const IntSet&);

// destructor 
	~IntSet(); 
// arithmetic operators
	IntSet operator+(const IntSet&) const; //union two sets
	IntSet operator-(const IntSet&) const; //difference two sets
	IntSet operator*(const IntSet&) const; //intersect

// assignment operators
	IntSet& operator=(const IntSet&); // assignment operator
	IntSet& operator+=(const IntSet&); //union assignment 
	IntSet operator-=(const IntSet&); //differnce assignment
	IntSet operator*=(const IntSet&); //intersect assignment

// boolean operators
	bool operator==(const IntSet&) const; 
	bool operator!=(const IntSet&) const; 
	
// Methods
	bool insert(int toInsert);
	bool remove(int toRemove);
	int findLarestParam(int a, int b, int c, int d, int e); // finds and returns the largest parameter passed
	void printSet(); 
	void initializeSet(); 
	bool isEmpty(); 
	bool isInSet(int toCheck);



private: 
	bool * set; 
	int setSize; 
	




};

#endif
