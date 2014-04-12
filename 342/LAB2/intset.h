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
// overloaded constructor
	IntSet(int a, int b, int c, int d, int e);
// arithmetic operators
	IntSet operator+(const IntSet&) const; //union two sets
	IntSet operator-(const IntSet&) const; //difference two sets
	IntSet operator*(const IntSet&) const; //intersect

// assignment operators
	IntSet operator=(const IntSet&); // assignment operator
	IntSet operator+=(const IntSet&); //union assignment 
	IntSet operator-=(const IntSet&); //differnce assignment
	IntSet operator*=(const IntSet&); //intersect assignment

// boolean operators
	IntSet operator==(const IntSet&) const; 
	IntSet operator!=(const IntSet&) const; 

// Methods
	bool insert(int toInsert);
	int findLarestParam(int a, int b, int c, int d, int e); // finds and returns the largest parameter passed

private: 
	bool * set; 
	




};

#endif