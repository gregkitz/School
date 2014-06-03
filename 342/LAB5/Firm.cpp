#include "Firm.h"
#include "ClientInfo.h"
#include <iostream> 
#include <fstream>
#include <string> 
const string clientList = "lab4data.txt"; 

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
	while (true){
		clientFile >> lastName >> firstName; 
		ClientInfo * newClientInfo = new ClientInfo(lastName, firstName);

		if (clientFile.eof()) break;


	}
	//insert client object into tree

}
