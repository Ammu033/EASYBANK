#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include "Transaction.h"
#include <vector>
#include <iostream>
class CurrentAccount : public Account
{
    const double overdraftLimit = 500.0;
	std::vector<Transaction> history;

public:
    CurrentAccount(const std::string& name, int number);

    void deposit(double amount)  override;        

    void withdraw(double amount)  override;       

    void displayAccountInfo() const override;     

    const std::vector<Transaction>& getHistory() const;
};

