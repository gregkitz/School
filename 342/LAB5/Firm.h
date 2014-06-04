#ifndef FIRM_H 
#define FIRM_H
#include <iostream> 
#include <fstream>
#include "BSTree.h"
#include "ClientInfo.h"
using namespace std; 
class firm {
private: 
	BSTree clients; 
	int totalClients; 
	
	
public: 
	bool addClients(ifstream& clientFile);
	firm();

};
#endif 

