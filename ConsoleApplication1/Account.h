#pragma once
#include <iostream>
#include <string>
class Account{
protected:
	std::string accountHolderName;
	int accountNumber;
	double balance;

public:
	Account(const std::string& name, int number, double initialBalance);
	virtual void deposit(double amount)  = 0 ;
	virtual void withdraw(double amount) = 0 ;
	virtual void displayAccountInfo() const= 0  ;

	virtual ~Account();
	double getBalance()const ;
	int getAccountNumber()const;
	const std::string& getHolderName() const;
};

