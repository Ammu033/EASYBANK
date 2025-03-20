// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Transaction.h"
#include "Account.h"
#include "ErrorHandling.h"
#include "Currentaccount.h"
#include "SavingsAccount.h"
#include "InterestEarning.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <algorithm>


int main()
{
    std::vector<std::unique_ptr<Account>> accounts;
    ErrorHandling read;

    std::cout << "~~~ Welcome to LincBank! ~~~\n";

    bool running = true;
    while (running) {
        std::cout << "\nCommands: open, view, withdraw, deposit, transfer, project, search, options, exit\n";
        std::cout << ">>> ";
        std::string command;
        std::cin >> command;


        if (command == "open") {

            std::cout << "Enter type (current/savings): ";
            std::string type;
            std::cin >> type;

            std::string name;
            int number;
            double initialBalance = 0.0;
            double rateOrLimit = 0.0;

            std::cout << "Enter account holder name: ";
            std::cin >> name;
            std::cout << "Enter account number: ";
            number = read.readInteger();



            if (type == "current") {
                bool hasCurrentAccount = false;
                for (const auto& account : accounts) {
                    if (dynamic_cast<CurrentAccount*>(account.get())) {
                        hasCurrentAccount = true;
                        break;
                    }  
                }
                if (hasCurrentAccount) {
                    std::cout << "Error: Account already exits.\n";
                    continue;
                }
                else {

                   accounts.push_back(std::make_unique<CurrentAccount>(name, number));
                   std::cout << "Current account opened successfully.\n";

                }
            }
            else if (type == "savings") {
                std::cout << "Enter savings type (regular/isa): ";
                std::string savingsType;
                std::cin >> savingsType;

                std::cout << "Enter initial balance: ";
                std::cin >> initialBalance;
                
                if (savingsType == "isa") {
                    // Check if ISA already exists
                    bool hasISA = false;
                    for (const auto& account : accounts) {
                        auto* savings = dynamic_cast<SavingsAccount*>(account.get());
                        if (savings && savings->getIsISA()) {
                            hasISA = true;
                            break;
                        }
                    }
                    if (hasISA) {
                        std::cout << "Error: Only one ISA account allowed.\n";
                        continue;
                    }

                    try {
                        accounts.push_back(std::make_unique<SavingsAccount>(name, number, initialBalance, true));
                        std::cout << "ISA account opened successfully.\n";
                    }
                    catch (const std::invalid_argument& e) {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                }
                else if (savingsType == "regular") {
                    accounts.push_back(std::make_unique<SavingsAccount>(name, number, initialBalance, false));
                    std::cout << "Regular savings account opened successfully.\n";
                }
                else {
                    std::cout << "Invalid savings account type.\n";
                }
            }
            else {
                std::cout << "Invalid account type.\n";
            }
            
                
            continue;
        }
        else if (command == "view") {
            for (const auto& account : accounts) {
                account->displayAccountInfo();
                std::cout << "\n";
            }
        }
        else if (command == "withdraw") {
            std::cout << "Enter account number: ";
            int number;
            number = read.readInteger();
            std::cout << "Enter amount to withdraw: ";
            double amount;
            amount = read.readdouble();

            for (auto& account : accounts) {
                if (account->getAccountNumber() == number) {
                    account->withdraw(amount);
                    break;
                }
            }
        }
        else if (command == "deposit") {
            std::cout << "Enter account number: ";
            int number;
            number = read.readInteger();

            std::cout << "Enter amount to deposit: ";

            double amount;
            amount = read.readdouble();


            for (auto& account : accounts) {
                if (account->getAccountNumber() == number) {
                    account->deposit(amount);
                    break;
                }
            }
        }
        else if (command == "transfer") {
            std::cout << "Enter source account number: ";
            int source;
            source = read.readInteger();

            std::cout << "Enter target account number: ";
            int target;
            target = read.readInteger();

            std::cout << "Enter amount to transfer: ";
            double amount;
            amount = read.readdouble();

            Account* sourceAccount = nullptr;
            Account* targetAccount = nullptr;

            for (auto& account : accounts) {
                if (account->getAccountNumber() == source) {
                    sourceAccount = account.get();
                }
                else if (account->getAccountNumber() == target) {
                    targetAccount = account.get();
                }
            }

            if (sourceAccount && targetAccount) {
                sourceAccount->withdraw(amount);
                targetAccount->deposit(amount);
                std::cout << "Transfer successful.\n";
            }
            else {
                std::cout << "Invalid account numbers.\n";
            }
        }
        else if (command == "project") {
            std::cout << "Enter account number: ";
            int number;
            number = read.readInteger();

            std::cout << "Enter years for projection: ";
            int years;
            years = read.readInteger();

            if (years <= 0) {
                std::cout << "Error: Projection years must be positive.\n";
                continue;
            }
             
            bool accountFound = false;
            for (const auto& account : accounts) {
                auto* savings = dynamic_cast<SavingsAccount*>(account.get());
                if (savings && account->getAccountNumber() == number) {
                    try {
                        double projectedAmount = savings->computeInterest(years);
                        std::cout << std::fixed << std::setprecision(2);
                        std::cout << "Projected amount after " << years << " years: " << projectedAmount << "\n";
                        accountFound = true;
                    }
                    catch (const std::invalid_argument& e) {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                    break;
                }
            }

            if (!accountFound) {
                std::cout << "Error: No savings account found with that number.\n";
            }
            

            
        }
        else if (command == "search") {
            std::cout << "Enter transaction value to search: ";
            double value;
            value = read.readdouble();

            for (const auto& account : accounts) {
                const auto* current = dynamic_cast<CurrentAccount*>(account.get());
                const auto* savings = dynamic_cast<SavingsAccount*>(account.get());

                if (current) {
                    for (const auto& transaction : current->getHistory()) {
                        if (transaction.getValue() == value) {
                            std::cout << transaction.getDetails() << "\n";
                        }
                    }
                }
                else if (savings) {
                    for (const auto& transaction : savings->getHistory()) {
                        if (transaction.getValue() == value) {
                            std::cout << transaction.getDetails() << "\n";
                        }
                    }
                }
            }
        }
        else if (command == "options") {
            std::cout << "Commands: open, view, withdraw, deposit, transfer, project, search, options, exit\n";
        }
        else if (command == "exit") {
            running = false;
        }
        else {
            std::cout << "Invalid command. Type 'options' for a list of commands.\n";
        }
    }

    std::cout << "Thank you for using LincBank. Goodbye!\n";
    return 0;
}







