#pragma once
#include <string>
#include <ostream>

class Transaction {
public:
    std::string sender;
    std::string recipient;
    double amount;

    Transaction(const std::string& from, const std::string& to, double amt);
};

std::ostream& operator<<(std::ostream& os, const Transaction& tx);
