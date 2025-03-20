#include "CurrentAccount.h"
#include <iomanip>

CurrentAccount::CurrentAccount(const std::string& name, int number)
    : Account(name, number, 0.0), overdraftLimit(1000.0) {}  // Added default overdraft limit

void CurrentAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid deposit amount. Please enter a positive value.\n";
        return;
    }

    balance += amount;
    history.emplace_back("Deposit", amount);
    std::cout << "Deposited " << std::fixed << std::setprecision(2) << amount
        << ". New balance: " << balance << "\n";
}

void CurrentAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid withdrawal amount. Please enter a positive value.\n";
        return;
    }

    if (balance - amount < -overdraftLimit) {
        std::cout << "Overdraft limit exceeded. Withdrawal denied.\n";
        return;
    }

    balance -= amount;
    history.emplace_back("Withdrawal", -amount);
    std::cout << "Withdrew " << std::fixed << std::setprecision(2) << amount
        << ". New balance: " << balance << "\n";
}

void CurrentAccount::displayAccountInfo() const {
    std::cout << "[Current Account]\n"
        << "Account Holder: " << accountHolderName << "\n"
        << "Account Number: " << accountNumber << "\n"
        << "Balance: " << std::fixed << std::setprecision(2) << balance << "\n"
        << "Overdraft Limit: " << overdraftLimit << "\n";
}

const std::vector<Transaction>& CurrentAccount::getHistory() const {
    return history;
}