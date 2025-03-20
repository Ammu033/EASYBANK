

#include "Transaction.h"
#include <iomanip>
#include <sstream>

Transaction::Transaction(const std::string& description, double value)
    : description(description), value(value) {
    std::time_t now = std::time(nullptr);
#ifdef _WIN32
    localtime_s(&timestamp, &now);
#else
    timestamp = *localtime(&now);
#endif
}

std::string Transaction::getDetails() const {
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timestamp);
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << value;
    return description + " | Amount: " + oss.str() + " | Date: " + buffer;
}

double Transaction::getValue() const {
    return value;
}






