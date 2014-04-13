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
}

// Copy Constructor 
IntSet::IntSet(const IntSet& rhs){
	//cout << "IN COPY CONSTRUCTOR!!!" << *this << endl;
	setSize = rhs.setSize;
	set = new bool[setSize];

	for (int currentNum = 0; currentNum < setSize; currentNum++){
		if (rhs.set[currentNum] == 1){
			insert(currentNum);
		}

	}

}
// Destructor 

IntSet::~IntSet(){
	delete [] set; 
	set = NULL;

}

// Insertion/Extraction operators

ostream& operator<<(ostream &output, const IntSet & rhs){
	output << "{";
	if (rhs.setSize == 1){
		output << " ";
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

// += operator

IntSet& IntSet::operator+=(const IntSet& rhs){
	
	*this = *this + rhs; 
	return *this;

}

// Assignment operators

IntSet& IntSet::operator=(const IntSet& rhs){
	delete[] set; 
	setSize = rhs.setSize;
	set = new bool[setSize];
	
	initializeSet();

	for (int currentNum = 0; currentNum < rhs.setSize; currentNum++){
		if (rhs.set[currentNum] == 1){
			insert(currentNum);

		}

	}

	
	return *this; 

}

// Misc Methods
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
		if (toInsert > setSize){
			IntSet newSet(toInsert);
			*this += newSet;

		}
		set[toInsert] = true; 
		return true;

	}
}

void IntSet::printSet(){
	for (int toPrint = 0; toPrint < setSize; toPrint++){
		if (set[toPrint] != false){
			cout << " " << toPrint;
		}

	}

}

void IntSet::initializeSet(){
	for (int toInit = 0; toInit < setSize; toInit++){
		set[toInit] = 0; 

	}
}

bool IntSet::isEmpty(){
	

	return setSize > 1 ? false : true; 
}

bool IntSet::isInSet(int toCheck){
	if (toCheck > setSize){
		return false;
	}
	else if (set[toCheck] == true){
		return true;
	}
	else {
		return false;
	}

}
