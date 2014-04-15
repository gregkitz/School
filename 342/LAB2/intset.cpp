#include "intset.h";
// default constructor
//-----------------------------------------------------------------------------
IntSet::IntSet(){
	set = new bool[1]; 
	setSize = 1;
	initializeSet();
	

}
// one parameter constructor
//-----------------------------------------------------------------------------
IntSet::IntSet(int a){
	setSize = findLarestParam(a, 0, 0, 0, 0) + 1;
	set = new bool[setSize];
	initializeSet();
	insert(a);

}
// two parameter constructor
//-----------------------------------------------------------------------------
IntSet::IntSet(int a, int b){
	setSize = findLarestParam(a, b, 0, 0, 0) + 1;
	set = new bool[setSize];
	initializeSet();
	insert(a);
	insert(b);

}
// three parameter constructor
//-----------------------------------------------------------------------------
IntSet::IntSet(int a, int b, int c){
	setSize = findLarestParam(a, b, c, 0, 0) + 1;
	set = new bool[setSize];
	initializeSet();
	insert(a);
	insert(b);
	insert(c);

}
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
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
}
//-----------------------------------------------------------------------------
// Copy Constructor 
IntSet::IntSet(const IntSet& rhs){
	setSize = rhs.setSize;
	set = new bool[setSize];
	initializeSet();

	for (int currentNum = 0; currentNum < setSize; currentNum++){
		if (rhs.set[currentNum] == 1){
			insert(currentNum);
		}

	}

}
//-----------------------------------------------------------------------------
// Destructor 

IntSet::~IntSet(){
	delete [] set; 
	set = NULL;

}
//-----------------------------------------------------------------------------
// Insertion/Extraction operators

ostream& operator<<(ostream &output, const IntSet & rhs){
	output << "{";
	if (rhs.setSize <= 1){
		output << " }";
	}
	else{
		for (int toPrint = 0; toPrint < rhs.setSize; toPrint++){
			if (rhs.set[toPrint] != false){
				output << " " << toPrint;
			}

		}
		output << " }";
	}
	return output;
}
//-----------------------------------------------------------------------------
// insertion

istream& operator>>(istream &input, IntSet & rhs){
	cout << "Terminate with '-1' " << endl; 
	while (true){
		int x;
		input >> x;
		if (x == -1){
			break;
		}
		else if (x < 0){
			// do nothing
		}
		else{

			rhs.insert(x);
		}

	}
	return input;
}
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
// difference
IntSet IntSet::operator-(const IntSet& rhs) const {
	IntSet difference(setSize );
	difference.initializeSet();
	
	if (setSize > rhs.setSize){
		for (int currentNum = 0; currentNum < rhs.setSize; currentNum++){ // Compares values between two sets
			if (set[currentNum] == true && rhs.set[currentNum] == false){
				difference.insert(currentNum);
			}
			
		}
		for (int currentNum = rhs.setSize; currentNum < setSize; currentNum++){
			if (set[currentNum] == true){
				difference.insert(currentNum);
			}// Adds the rest of the values 

		}
	}

	
	else{
		for (int currentNum = 0; currentNum < setSize; currentNum++){ // Just compare the values
			if (set[currentNum] == true && rhs.set[currentNum] == false){
				difference.insert(currentNum);
			}

		}

	}
	return difference;

}
//-----------------------------------------------------------------------------
// intersection
IntSet IntSet::operator*(const IntSet& rhs) const {
	int smallerSize = setSize > rhs.setSize ? rhs.setSize : setSize;
	IntSet intersect(smallerSize -1);
	intersect.initializeSet();

	for (int currentNum = 0; currentNum < smallerSize; currentNum++){
		if (set[currentNum] == rhs.set[currentNum]  && set[currentNum] != 0){
			intersect.insert(currentNum);
		}
	}
	return intersect;

}


//-----------------------------------------------------------------------------
// Assignment operators

IntSet& IntSet::operator=(const IntSet& rhs){
	if (&rhs != this){
		delete[] set;
		setSize = rhs.setSize;
		set = new bool[setSize];

		initializeSet();

		for (int currentNum = 0; currentNum < rhs.setSize; currentNum++){
			if (rhs.set[currentNum] == 1){
				insert(currentNum);

			}

		}

	}
	return *this; 

}
//-----------------------------------------------------------------------------
//Intersection Assignment
IntSet IntSet::operator*=(const IntSet& rhs){
	*this = *this * rhs; 
	return *this; 
}
//-----------------------------------------------------------------------------
//Difference Assignmnet
IntSet IntSet::operator-=(const IntSet& rhs){
	*this = *this - rhs; 

	return *this; 
}
//-----------------------------------------------------------------------------
// Union Assignment

IntSet& IntSet::operator+=(const IntSet& rhs){

	*this = *this + rhs;
	return *this;

}
//-----------------------------------------------------------------------------
//Boolean Operators 

bool IntSet::operator==(const IntSet& rhs) const{
	bool isEqual = true; 
	if (setSize == rhs.setSize){
		for (int currentNum = 0; currentNum < setSize; currentNum++){
			if (set[currentNum] != rhs.set[currentNum]){
				return false;

			}
			else{
				isEqual = true; 
			}
		}

	}
	else {
		return false; 
	}
	return isEqual;
}

bool IntSet::operator!=(const IntSet& rhs) const{
	bool isEqual = *this == rhs;
	return !isEqual;
}
//-----------------------------------------------------------------------------
// Misc Methods
int IntSet::findLarestParam(int a, int b, int c, int d, int e){
	int largest = a > b ? a : b; 
	largest = largest > c ? largest : c; 
	largest = largest > d ? largest : d; 
	largest = largest > e ? largest : e; 


	return largest; 
}
//-----------------------------------------------------------------------------
// Insert
bool IntSet::insert(int toInsert){
	if (toInsert < 0){
		return false;
	}
	else {
		if (toInsert > setSize){
			IntSet newSet(toInsert);
			*this += newSet;

		}
		set[toInsert] = true; 
		return true;

	}
}
//-----------------------------------------------------------------------------
// remove

bool IntSet::remove(int toRemove){
	if (toRemove < 0){
		return false;
	}
	else if(toRemove > setSize){
		return false;
	}
	else {
		set[toRemove] = false; 
		return true; 
	}

}
//-----------------------------------------------------------------------------
void IntSet::printSet(){
	for (int toPrint = 0; toPrint < setSize; toPrint++){
		if (set[toPrint] != false){
			cout << " " << toPrint;
		}

	}

}
//-----------------------------------------------------------------------------
void IntSet::initializeSet(){
	for (int toInit = 0; toInit < setSize; toInit++){
		set[toInit] = 0; 

	}
}
//-----------------------------------------------------------------------------
bool IntSet::isEmpty(){
	

	return setSize > 1 ? false : true; 
}
//-----------------------------------------------------------------------------
bool IntSet::isInSet(int toCheck){
	if (toCheck > setSize){
		return false;
	}
	else if (toCheck < 0){
		return false;
	}
	else if (set[toCheck] == true){
		return true;
	}
	else {
		return false;
	}

}
