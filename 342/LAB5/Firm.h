#ifndef FIRM_H 
#define FIRM_H
#include <iostream> 
#include <fstream>
#include "BSTree.h"
#include "ClientInfo.h"
#include "Transaction.h"
#include <queue>
using namespace std; 
class firm {
private: 
	BSTree clients; 
	queue<Transaction> transactions; 
	int totalClients; 
	static const string clientList;
	static const string transactionsList;
	
public: 
	bool addClients(ifstream& clientFile);
	bool addTransactions(ifstream& transactionsFile); //reads transaction file 
						           //to transaction object and puts into queue
	firm();
	~firm(); 

	bool validateFrom(int from); 
	bool validateTo(int to); 
	bool validateType(int type); 

	void processTransactions(); 

};
#endif 

