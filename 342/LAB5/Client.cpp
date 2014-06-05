#include "Client.h"
Client::Client(const int& idNumber){
	clientID = idNumber; 

}

Client::~Client(){
	
}

void Client::displayID(){
	cout << clientID << endl; 

}

void Client::setClientInfo( const ClientInfo& toSet){
	info = toSet; 

}

void Client::setAccounts(Account toSet[]){
	for (int i = 0; i < MAX_ACCOUNT; i++){
		accounts[i] = toSet[i]; 

	}
	
}
bool Client::operator<(const Client& right) const{
	return clientID < right.clientID ? true : false; 
}