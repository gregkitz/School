#include "Client.h"

Client(infile("lab5data.txt")){


}


bool Client::operator<(const Client& right) const{
	return clientID < right.clientID ? true : false; 
}