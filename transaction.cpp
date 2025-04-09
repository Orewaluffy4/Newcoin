#include "transaction.h"

Transaction::Transaction(const std::string& from, const std::string& to, double amt)
    : sender(from), recipient(to), amount(amt) {}

std::ostream& operator<<(std::ostream& os, const Transaction& tx) {
    os << "From: " << tx.sender << ", To: " << tx.recipient << ", Amount: " << tx.amount;
    return os;
}
