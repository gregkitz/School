#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;
class Account{
public: 
	int getBalance(); 
	Account();
	void setNumBalance(int num, int bal); 
	void setType(int typeOfAccount); 
	void getInitialBalance(); 
	void setIniBalance(int toSet); 
	void deposit(); 
	void withdraw(); 

private: 
	int type; 
	int balance; 
	int initialBalance; 
};
#endif 