#include "intset.h";
// default constructor
IntSet::IntSet(){
	set = new bool[1]; 
	initializeSet();
	setSize = 1; 

}
// one parameter constructor
IntSet::IntSet(int a){
	setSize = findLarestParam(a, 0, 0, 0, 0) + 1;
	set = new bool[setSize];
	initializeSet();
	insert(a);

}
// two parameter constructor
IntSet::IntSet(int a, int b){
	setSize = findLarestParam(a, b, 0, 0, 0) + 1;
	set = new bool[setSize];
	initializeSet();
	insert(a);
	insert(b);

}
// three parameter constructor
IntSet::IntSet(int a, int b, int c){
	setSize = findLarestParam(a, b, 0, 0, 0) + 1;
	set = new bool[setSize];
	initializeSet();
	insert(a);
	insert(b);
	insert(c);

}
// four parameter constructor
IntSet::IntSet(int a, int b, int c, int d){
	setSize = findLarestParam(a, b, c, d, 0) + 1;
	set = new bool[setSize];
	initializeSet(); 
	insert(a);
	insert(b);
	insert(c);
	insert(d);

}
// five parameter constructor
IntSet::IntSet(int a, int b, int c, int d, int e){
	setSize = findLarestParam(a, b, c, d, e) + 1; 
	set = new bool[setSize]; 
	initializeSet(); 
	insert(a);
	insert(b);
	insert(c);
	insert(d);
	insert(e);
	printSet(); 
}

// Arithmatic operators
IntSet IntSet::operator+(const IntSet& rhs) const{
	int newSize = rhs.setSize > setSize ? rhs.setSize : setSize;
	IntSet unioned(newSize - 1);

	for (int currentNum = 0; currentNum < rhs.setSize; currentNum++){
		if (rhs.set[currentNum] == 1){
			unioned.insert(currentNum);
		}

	}
	for (int currentNum = 0; currentNum < setSize; currentNum++){
		if (set[currentNum] == 1){
			unioned.insert(currentNum);

		}

	}

	return unioned;
}

// Assignment operators

IntSet IntSet::operator=(const IntSet& rhs){
	IntSet assignmentSet(rhs.setSize - 1);
	for (int currentNum = 0; currentNum < rhs.setSize; currentNum++){
		if (rhs.set[currentNum] == 1){
			assignmentSet.insert(currentNum);

		}

	}

	delete this;
	*this = assignmentSet;
	return *this; 

}


int IntSet::findLarestParam(int a, int b, int c, int d, int e){
	int largest = a > b ? a : b; 
	largest = largest > c ? largest : c; 
	largest = largest > d ? largest : d; 
	largest = largest > e ? largest : e; 


	return largest; 
}

bool IntSet::insert(int toInsert){
	if (toInsert < 0){
		return false;
	}
	else {
		set[toInsert] = true; 
		return true;

	}
}

void IntSet::printSet(){
	for (int toPrint = 0; toPrint < setSize; toPrint++){
		if (set[toPrint] != false){
			cout << "To print: " << toPrint << "Boolean value: " << set[toPrint] << endl; 
		}

	}

}

void IntSet::initializeSet(){
	for (int toInit = 0; toInit < setSize; toInit++){
		set[toInit] = 0; 

	}
}

