#include "Firm.h"
#include "ClientInfo.h"
#include <iostream> 
#include <fstream>
#include <string> 
//const string clientList = "lab4data.txt"; 
static const int MAX_ACCOUNT = 10; 
firm::firm(){
	ifstream inFile("lab5data.txt"); 
	if (!inFile)  {
		cout << "File could not be opened." << endl;
		}
	addClients(inFile); 

}

bool firm::addClients(ifstream& clientFile){
	
	//read file into client object with accounts 
	
	if (!clientFile)  {
		cout << "File could not be opened." << endl;
		
	}
	string lastName; 
	string firstName; 
	int idNum; 
	while (true){
		clientFile >> lastName >> firstName >> idNum; 
		cout << idNum << endl; 
		ClientInfo newClientInfo(lastName, firstName); 
		Client * newClient = new Client(idNum); 
		newClient->setClientInfo(newClientInfo); 
		
		//create array of accounts then pass into client 
		Account balances[MAX_ACCOUNT]; 
		for (int i = 0; i < MAX_ACCOUNT; i++){
			int newBalance = 0; 
			clientFile >> newBalance; 
			balances[i].setIniBalance(newBalance);  // set balance
			balances[i].setType(i);
			}
		// pass new array to client 
		newClient->setAccounts(balances); 
		delete newClient;
		if (clientFile.eof()) break;


	}
	return true; 
	//insert client object into tree

}
