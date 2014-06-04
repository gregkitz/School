#include "Client.h"


bool Client::operator<(const Client& right) const{
	return clientID < right.clientID ? true : false; 
}