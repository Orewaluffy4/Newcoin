#pragma once
#include <string>
#include <vector>
#include "transaction.h"

class Block {
public:
    int index;
    std::string timestamp;
    std::vector<Transaction> transactions;
    std::string previousHash;
    std::string hash;

    Block(int idx, const std::vector<Transaction>& txs, const std::string& prevHash);
    std::string calculateHash() const;
};
