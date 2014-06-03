#ifndef Client_H
#define Client_H

#include <iostream>
#include "ClientInfo.h"
#include "Account.h"
using namespace std;
class Client {
public: 
	Client(); 
	Client(ifstream& inFile); 
	bool operator<(const Client&) const;
private: 
	int clientID; 
	ClientInfo info; 
	const int MAX_ACCOUNT = 10;
	Account accounts[];
	
	 
	
	
};

#endif