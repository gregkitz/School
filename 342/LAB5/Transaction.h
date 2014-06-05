#ifndef TRANSACTION_H
#define TRANSACTION_H
class Transaction{
private: 
	char type; 
	int amount, firstClientID, firstAccountType, secondClientID, secondAccountType;

public: 
	Transaction(); 
	~Transaction(); 
	char getType(); 
	int getAmount(); 
	int getFirstClientID(); 
	int getFirstAccountType(); 
	int getSecondClientID(); 
	int getSecondAccountType();
	void setFromAccount(int from); 
	void setToAccount(int to); 
	void setFromAccountType(int type); 
	void setToAccountType(int type); 
	void setAmount(int setAmount); 
	void setType(char toSet); 



};
#endif