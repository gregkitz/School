#ifndef Client_H
#define Client_H

#include <iostream>
#include "ClientInfo.h"
#include "Account.h"
using namespace std;
class Client {
public: 
	Client(); 
	~Client(); 
	Client(ifstream& inFile); 
	Client(const int& idNumber); 
	bool operator<(const Client&) const;
	static const int MAX_ACCOUNT = 10;
	void setClientInfo(const ClientInfo& toSet); 
	void setAccounts(Account toSet[]); 
	void displayID();
private: 
	int clientID; 
	ClientInfo info; 
	
	Account accounts[MAX_ACCOUNT];
	
	 
	
	
};

#endif