#include "Firm.h"
#include "ClientInfo.h"
#include <iostream> 
#include <fstream>
#include <string> 
#include <math.h>
#include <cmath>
#include <ctype.h>
static const string clientList = "lab5data.txt";
static const string transactionsList = "lab5command.txt";
static const int MAX_ACCOUNT = 10; 
firm::firm(){
	ifstream inFile("lab5data.txt"); 
	if (!inFile)  {
		cout << "File could not be opened." << endl;
		}
	else{
		addClients(inFile);
	}
	ifstream inFileCommands("lab5command.txt");
	if (!inFileCommands) {
		cout << "File could not be opened." << endl; 
	}
	else{
		addTransactions(inFileCommands);
	}
	processTransactions(); 
}

firm::~firm(){

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
		//insert client object into tree

		totalClients++; 
		clients.insert(newClient); 
		
		//delete newClient;
		if (clientFile.eof()) break;


	}
	
	return true; 


}


bool firm::addTransactions(ifstream& transactionsFile){

	if (!transactionsFile)  {
		cout << "File could not be opened." << endl;
	}
	char type; 
	int accountNumber; 
	int to, from, amount; 
	//declare new transaction object 
	Transaction newTransaction;
	while (true){

		//read in first char (type of transaction) 
		transactionsFile >> type; 
		//enter 4-part if statement 
		if (type == 'm' || type == 'M'){
			transactionsFile >> from >> amount >> to; 
			//validate from, and to (use separate validation functions)
			if (validateFrom(from / 10) && validateTo(to / 10)){
			//end validation 
				newTransaction.setType('M');
				newTransaction.setFromAccount(from / 10);
				newTransaction.setFromAccountType(from % 10);
				newTransaction.setAmount(amount);
				newTransaction.setToAccount(to / 10);
				newTransaction.setToAccountType(to % 10);
				transactions.push(newTransaction);
			}
			else{
				cout << "Invalid from or to account number: " << to << from << endl; 
			}
		}
		else if (type == 'd' || type == 'D'){
			transactionsFile >> to >> amount; 
			//validate to and amount (use separate validation functions)
			if (validateTo(to / 10)){
				//end validate
				newTransaction.setType('D');
				newTransaction.setToAccountType(to % 10);
				newTransaction.setToAccount(to / 10);
				newTransaction.setAmount(amount);
				transactions.push(newTransaction);
			}
			else{
				cout << "Invalid to account number: " << to << endl;
			}
			
		}
		else if (type == 'w' || type == 'W'){
			newTransaction.setType('W');
			transactionsFile >> from >> amount; 
			//validate from and amount 
			if (validateFrom(from / 10) && validateTo(to / 10)){
				//end validate
				newTransaction.setFromAccountType(from % 10);
				newTransaction.setFromAccount(from / 10);
				newTransaction.setAmount(amount);
				transactions.push(newTransaction);
			}
			else{
				cout << "Invalid from account number: " << from << endl;
			}
		}
		else if (type == 'h' || type == 'H'){
			newTransaction.setType('H');
			transactionsFile >> from; 
			if (validateFrom(from)){
				newTransaction.setFromAccount(from);
			}
			else{
				cout << "Invalid from account number: " << from << endl;
			}
		}
		else if(isalpha(type)){
			//error reading in transaction type
			cout << "'" << type << "'" << "is an invalid entry for transaction type." << endl; 
		}
		else {
			
		}
		
		
		if (transactionsFile.eof()) break;

	}
	return true; 
}

void firm::processTransactions(){
	/*while (!transactions.empty()){
		transactions.front();

	}*/

	Client john(11113); 
	Client * foundJohn;
	bool what; 
	bool test = true; 
	clients.display(); 
	what = clients.retrieve(john, foundJohn);
	cout << *foundJohn << what << endl; 
}

bool firm::validateFrom(int from){
	//make sure from is four digits long
	if (from != 0){
		if ((floor(log10(abs(from))) + 1) == 4){
			return true; 
		}
	}
	else return false; 
}
bool firm::validateTo(int to){
	//make sure from is four digits long
	if (to != 0){
		if ((floor(log10(abs(to))) + 1) == 4){
			return true;
		}
	}
	else return false; 
}

bool firm::validateType(int type){
	//make sure type is one digit long
	if (type != 0 && isdigit(type)){
		if ((floor(log10(abs(type))) + 1) == 1){
			return true;
		}
	}
	else return false; 
}