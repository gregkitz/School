#include "Account.h"

Account::Account(){
	

}

void Account::setNumBalance(int num, int bal){
	type = num; 
	balance = bal; 

}
void Account::setIniBalance(int toSet){
	balance = toSet; 
	initialBalance = toSet; 

}
void Account::setType(int typeOfAccount){
	type = typeOfAccount; 

}