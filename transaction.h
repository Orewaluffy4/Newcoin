#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    std::string sender;
    std::string receiver;
    double amount;

    Transaction(const std::string& from, const std::string& to, double amt);
    std::string toString() const;
};

#endif // TRANSACTION_H