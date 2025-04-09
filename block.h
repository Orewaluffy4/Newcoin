#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>
#include <ctime>
#include "transaction.h"

class Block {
public:
    int index;
    std::time_t timestamp;
    std::vector<Transaction> transactions;
    std::string previousHash;
    std::string hash;
    uint64_t nonce;

    Block(int idx, const std::vector<Transaction>& txs, const std::string& prevHash);

    std::string calculateHash() const;
    void mineBlock(uint32_t difficulty);
};

#endif