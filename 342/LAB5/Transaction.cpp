#include "Transaction.h"

Transaction::Transaction(){

}

Transaction::~Transaction(){

}

char Transaction::getType(){
	return type;
}
int Transaction::getAmount(){
	return amount;
}
int Transaction::getFirstClientID(){
	return firstClientID;
}
int Transaction::getFirstAccountType(){
	return firstAccountType;
}
int Transaction::getSecondClientID(){
	return secondClientID;
}
int Transaction::getSecondAccountType(){
	return secondAccountType;
}

void Transaction::setFromAccount(int from){
	firstClientID = from; 
}
void Transaction::setToAccount(int to){
	secondClientID = to; 
}
void Transaction::setFromAccountType(int type){
	firstAccountType = type; 
}
void Transaction::setToAccountType(int type){
	secondAccountType = type; 
}
void Transaction::setAmount(int setAmount){
	amount = setAmount; 
}

void Transaction::setType(char toSet){
	type = toSet; 
}