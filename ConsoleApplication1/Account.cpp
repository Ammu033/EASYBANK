#include "Account.h"

 Account:: Account(const std::string& name, int number, double initialBalance)
        : accountHolderName(name), accountNumber(number), balance(initialBalance) {}

 Account::~Account() = default;
 double Account:: getBalance() const { return balance; }
 int Account::getAccountNumber() const { return accountNumber; }
 const std::string& Account:: getHolderName() const { return accountHolderName; }


