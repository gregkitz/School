#include "intset.h";
// default constructor
IntSet::IntSet(){
	set = new bool[1]; 

}
// one parameter constructor
IntSet::IntSet(int a){
	set = new bool[findLarestParam(a, 0, 0, 0, 0) + 1];
	insert(a);

}
// two parameter constructor
IntSet::IntSet(int a, int b){
	set = new bool[findLarestParam(a, b, 0, 0, 0) + 1];
	insert(a);
	insert(b);

}
// three parameter constructor
IntSet::IntSet(int a, int b, int c){
	set = new bool[findLarestParam(a, b, c, 0, 0) + 1];
	insert(a);
	insert(b);
	insert(c);

}
// four parameter constructor
IntSet::IntSet(int a, int b, int c, int d){
	set = new bool[findLarestParam(a, b, c, d, 0) + 1];
	insert(a);
	insert(b);
	insert(c);
	insert(d);

}
// five parameter constructor
IntSet::IntSet(int a, int b, int c, int d, int e){
	int largestParam = findLarestParam(a, b, c, d, e);
	cout << "Largest param is: " << largestParam << endl;
	set = new bool[findLarestParam(a, b, c, d, e) + 1]; 
	insert(a);
	insert(b);
	insert(c);
	insert(d);
	insert(e);
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

