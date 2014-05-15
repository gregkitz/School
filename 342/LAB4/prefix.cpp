
// You add all other appropriate comments.

// While I have done much of this for you, make sure you understand it all.
// Make sure you understand why the parameters are pass by reference
// in evaluatePrefixHelper and toPostfix.

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

