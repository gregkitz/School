#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;
class Account{
public: 
	int getBalance(); 
	Account();
	void getInitialBalance(); 
	void setBalance(int toSet); 
	void deposit(); 
	void withdraw(); 

private: 
	int type; 
	int balance; 
	int initialBalance; 
};
#endif 