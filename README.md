**EasyBank**

Overview

EasyBank is a console-based, simulated banking application developed in C++. It provides users with a simple yet functional platform to explore basic banking operations, including account creation, deposits, withdrawals, transfers, and interest projections. Designed as a dummy program, EasyBank operates without real financial transactions, making it an educational tool for understanding banking mechanics and C++ programming concepts such as inheritance, polymorphism, and error handling.

Features

Account Management:

Open a current account (one per user) with a fixed overdraft limit of $500.
Open savings accounts (regular or ISA, with a limit of one ISA per user).

**Transactions:**

Deposit funds into any account.

Withdraw funds, respecting overdraft limits (current accounts) or balance constraints (savings accounts).

Transfer money between accounts.

**Interest Calculation:**

Project future balances for savings accounts based on interest rates (ISA or regular).

**Transaction History:**

View and search transaction history for specific amounts (for current and savings accounts).

**User Interface:**

Interactive command-line interface with commands: open, view, withdraw, deposit, transfer, project, search, options, and exit.

**Error Handling:**

Robust input validation for integers and doubles, ensuring the program handles invalid entries gracefully.

**Prerequisites**

A C++ compiler (e.g., g++, Visual Studio, etc.) supporting C++11 or later.

Standard C++ libraries (iostream, vector, string, memory, etc.).

**Installation**

Clone or download the project files to your local machine.

**Ensure all source files (.cpp) and header files (.h) are in the same directory:**

Account.h, Account.cpp

CurrentAccount.h, CurrentAccount.cpp (assumed based on usage)

SavingsAccount.h, SavingsAccount.cpp (assumed based on usage)

Transaction.h, Transaction.cpp (assumed based on usage)

ErrorHandling.h, ErrorHandling.cpp

ConsoleApplication1.cpp (main file)

Compile the program using your preferred C++ compiler. For example, with g++:
~~~

g++ -o EasyBank ConsoleApplication1.cpp Account.cpp CurrentAccount.cpp SavingsAccount.cpp Transaction.cpp ErrorHandling.cpp

~~~

OR 

~~~
Run the executable:

./EasyBank

~~~

**Usage**

Upon launching EasyBank, you’ll be greeted with a welcome message and a prompt to enter commands. Below are the available commands:

open: Create a new account (current or savings).

Specify type (current or savings), holder name, and account number.

For savings, choose regular or isa and provide an initial balance.

view: Display details of all accounts (balance, holder name, account number, etc.).

deposit: Add funds to an account by entering the account number and amount.

withdraw: Remove funds from an account, subject to limits.

transfer: Move money between two accounts by specifying source and target account numbers and the amount.

project: Calculate future savings account balance based on interest over a specified number of years.

search: Find transactions matching a specific value in the account history.

options: List all available commands.

exit: Close the application.

Example Interaction
~~~

~~~ Welcome to LincBank! ~~~

Commands: open, view, withdraw, deposit, transfer, project, search, options, exit
>>> open
Enter type (current/savings): current
Enter account holder name: John
Enter account number: 1234
Current account opened successfully.

>>> deposit
Enter account number: 1234
Enter amount to deposit: 1000
>>> view
Account Holder: John, Account Number: 1234, Balance: 1000.00
~~~

**Project Structure**

Account.h/Account.cpp: Base class defining account properties and virtual methods.

CurrentAccount.h: Derived class for current accounts with overdraft functionality and transaction history.

SavingsAccount.h: Derived class (assumed) for savings accounts with interest-earning capabilities.

Transaction.h: Class (assumed) to manage transaction records.

ErrorHandling.h/ErrorHandling.cpp: Utility class for input validation.

ConsoleApplication1.cpp: Main program logic and user interface.


**Limitations**
This is a dummy application; no real money is involved, and data is not persisted after the program exits.

Only one current account and one ISA savings account are allowed per session.

Assumes additional files (SavingsAccount.cpp, Transaction.cpp) exist with appropriate implementations.

**Future Enhancements**

Add file-based persistence to save account data between sessions.

Implement a graphical user interface (GUI) for broader accessibility.

Expand account types (e.g., business accounts) and transaction features.

**Author**

AMANPREET

Created as a demonstration of object-oriented programming in C++.

License
This project is unlicensed and free for educational use.

Feel free to adjust the "Author" section with your name or any other details you’d like to include! Let me know if you want to refine anything further.
=======
# EASYBANK
EasyBank is a simulated banking application designed to provide users with a seamless and intuitive financial management experience. This program allows individuals to establish a virtual account, review applicable interest rates, deposit funds, and execute withdrawals within a controlled, dummy environment. 

