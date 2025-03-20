#pragma once

#include "Account.h"
#include "Currentaccount.h"
#include "InterestEarning.h"
class SavingsAccount :
	public Account, public InterestEarning {
    double interestRate = 0.85;
    double interestrate = 1.15;
    std::vector<Transaction> history;
    bool isISA;
    

public:
        

    SavingsAccount(const std::string& name, int number, double initialBalance, bool isISA = false);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    double computeInterest(int years) const override;
    void displayAccountInfo() const override;
    const std::vector<Transaction>& getHistory() const;
    bool getIsISA() const { return isISA; }
};
        
    


    






