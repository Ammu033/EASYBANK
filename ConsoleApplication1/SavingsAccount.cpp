#include "SavingsAccount.h"
#include <cmath>
#include <iomanip>

SavingsAccount::SavingsAccount(const std::string& name, int number,
    double initialBalance, bool isISA)
    : Account(name, number, initialBalance) ,
    interestRate(isISA ? 1.15 : 0.85),
    isISA(isISA)
{
    if (isISA && initialBalance < 1000.0)
    {
        throw std::invalid_argument("ISA accounts require minimum £1000 initial deposit");
    }
}

void SavingsAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid deposit amount. Please enter a positive value.\n";
        return;
    }

    balance += amount;
    history.emplace_back("Deposit", amount);
    std::cout << "Deposited " << std::fixed << std::setprecision(2) << amount
        << ". New balance: " << balance << "\n";
}

void SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid withdrawal amount. Please enter a positive value.\n";
        return;
    }

    if (amount > balance) {
        std::cout << "Insufficient balance. Withdrawal denied.\n";
        return;
    }

    balance -= amount;
    history.emplace_back("Withdrawal", -amount);
    std::cout << "Withdrew " << std::fixed << std::setprecision(2) << amount
        << ". New balance: " << balance << "\n";
}

double SavingsAccount::computeInterest(int years) const {
    if (years <= 0) {
        throw std::invalid_argument("Years must be positive");
    }

    const double r = interestRate / 100.0;
    const int n = 12;  // Compounding monthly
    return balance * std::pow(1 + r / n, n * years);
}

void SavingsAccount::displayAccountInfo() const {
    std::cout << (isISA ? "[ISA Savings Account]\n" : "[Regular Savings Account]\n")
        << "Account Holder: " << accountHolderName << "\n"
        << "Account Number: " << accountNumber << "\n"
        << "Balance: " << std::fixed << std::setprecision(2) << balance << "\n"
        << "Interest Rate: " << interestRate << "%\n";
}

const std::vector<Transaction>& SavingsAccount::getHistory() const {
    return history;
}

