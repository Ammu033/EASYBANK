#include "ErrorHandling.h"
#include <iostream>



    int ErrorHandling::readInteger() {
        int value;


        std::cin >> value;
        if (std::cin.fail()) {  // Check if input failed
            std::cin.clear();  // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a valid integer.\n";
            std::cout << ">>>";
            return readInteger();
        }
        else {

            return value;
        }


    }

    double ErrorHandling::readdouble() {
        double value;

        std::cin >> value;
        if (std::cin.fail()) {  // Check if input failed
            std::cin.clear();  // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cout << ">>>";
            return readdouble();
        }
        else {
            return value;
        }


    }




