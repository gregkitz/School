//-----------------------------------------------------------------------------
// CSS 342, Spring 2014
// Lab 4
// Greg Kitzmiller
//-----------------------------------------------------------------------------

// ADT which holds a prefix expression. Expression stored in an arry. 
// Contains an array for converting to a postfix expression. 
// Can evaluate the prefix expression. Assumed to be a correctly formatted. 

#include "prefix.h"

//-----------------------------------------------------------------------------
// constructor
// initialize the array to the empty string 
// char arrays are terminated with '\0' so operator<< works properly

Prefix::Prefix() {
   expr[0] = '\0'; 
} 

//-----------------------------------------------------------------------------
// setPrefix
// Set a prefix expression made of single digit operands, operators +,-,*,/
// and no blanks or tabs contained in a file. The expression is valid in
// that each operator has two valid operands.

void Prefix::setPrefix(ifstream& infile) { 
    infile >> expr;
}

//-----------------------------------------------------------------------------
// evaluatePrefix 
// Evaluate a prefix expr made of single digit operands and operators +,-,*,/

int Prefix::evaluatePrefix() const {
    if (expr[0] == '\0') 
        return 0;

    int index = -1;                               // to walk through expr
    return evaluatePrefixHelper(index);
}
//-----------------------------------------------------------------------------
// Recursive helper function. Evaluates a prefix expression. This function 
// reads a symbol and determines if it's a digit or not. If it's a digit it'll
// return otherwise it'll recursively call that symbol used as an operator
// on the next lefthand and righthand operands. 
// Index is passed by reference since it's used out of the scope of any one
// use of this function. 
int Prefix::evaluatePrefixHelper(int& index) const {
    char symbol = expr[++index];
	 //base case 
	if (isdigit(symbol)){
		return symbol - '0'; 
	}
	else if (symbol == '+'){
		return evaluatePrefixHelper(index) + evaluatePrefixHelper(index); 
	}
	else if (symbol == '-'){
		return evaluatePrefixHelper(index) - evaluatePrefixHelper(index);

	}
	else if (symbol == '*'){
		return evaluatePrefixHelper(index) * evaluatePrefixHelper(index);
	}
	else if (symbol == '/'){
		return evaluatePrefixHelper(index) / evaluatePrefixHelper(index);
	}
}

//-----------------------------------------------------------------------------
// outputAsPostfix, toPostfix
// Convert prefix expression to postfix and output

void Prefix::outputAsPostfix(ostream& out) const {
    if (expr[0] == '\0') 
        return;

    int index = -1;                           // to walk through expr
    int count = -1;                           // used to build postfix array
    char postfix[MAXSIZE+1];                  // holds postfix expression
    toPostfix(index, postfix, count);
    postfix[++count] = '\0';
    out << postfix;
}
//-----------------------------------------------------------------------------
// Recursive function which converts a given prefix expression to postfix. 
// Reads, if it's an operator writes in the needed operations then lists the
// operator which will reverse the expression. 
// Base case is if the expression is a digit. 
void Prefix::toPostfix(int& index, char postfix[], int& count) const {
	char symbol = expr[++index];
	//base case
	if (isdigit(symbol)){
		postfix[++count] = symbol; 
	}
	else{
		toPostfix(index, postfix, count); 
		toPostfix(index, postfix, count);	
		postfix[++count] = symbol;
	}


}




//-----------------------------------------------------------------------------
// operator<<
// display prefix expression as a string (char array)

ostream& operator<<(ostream& output, const Prefix& expression) {
    output << expression.expr;
    return output;
}

