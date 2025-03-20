
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include <time.h>
#include <iomanip>

class Transaction{
private :
	std::string description;
	double value;
	std::tm timestamp;
 public:
	 
 Transaction(const std::string& description, double valuee);
	std::string getDetails() const;
	double getValue() const;
};







