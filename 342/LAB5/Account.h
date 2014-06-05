#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string> 
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
	void setName(string nameToSet); 
	string getName();

private: 
	string name; 
	int type; 
	int balance; 
	int initialBalance; 
};
#endif 