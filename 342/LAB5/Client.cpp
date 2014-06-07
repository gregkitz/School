#include "Client.h"
Client::Client(const int& idNumber){
	clientID = idNumber; 
	accounts[0].setName("Money Market");
	accounts[1].setName("Prime Money Market");
	accounts[2].setName("Long-Term Bond");
	accounts[3].setName("Short-Term Bond");
	accounts[4].setName("500 Index Fund");
	accounts[5].setName("Capital Value Fund");
	accounts[6].setName("Growth Equity Fund");
	accounts[7].setName("Growth Index Fund");
	accounts[8].setName("Value Fund");
	accounts[9].setName("Value Stock Index");
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

bool Client::operator<=(const Client& right) const{
	return clientID <= right.clientID ? true : false; 
}
bool Client::operator>=(const Client& right) const{
	return clientID >= right.clientID ? true : false; 
}
bool Client::operator>(const Client& right) const{
	return clientID > right.clientID ? true : false; 
}

bool Client::operator==(const Client& lhs) const{
	if (clientID == lhs.clientID){
		return true; 
	}
	else{
		return false; 
	}
}

ostream& operator<<(ostream & output, const Client & client){
		output << client.clientID << endl;
		return output; 
}