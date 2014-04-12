#include "intset.h";
// default constructor
IntSet::IntSet(){
	set = new bool[1]; 

}

IntSet::IntSet(int a, int b, int c, int d, int e){
	set = new bool[findLarestParam(a, b, c, d, e)]; 
}

int findLarestParam(int a, int b, int c, int d, int e){
	int largest = a > b ? a : b; 
	largest = largest > c ? largest : c; 
	largest = largest > d ? largest : d; 
	largest = largest > e ? largest : e; 


	return largest; 
}