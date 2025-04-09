#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#include "transaction.h"
#include <vector>
#include <string>

class Blockchain {
private:
    std::vector<Block> chain;
    std::vector<Transaction> pendingTransactions;
    uint32_t difficulty;
    int reward;

public:
    Blockchain();
    Block getLatestBlock() const;
    void minePendingTransactions(const std::string& minerAddress);
    void addTransaction(const Transaction& tx);
    int getBalanceOfAddress(const std::string& address) const;
    const std::vector<Block>& getChain() const;
};

#endif // BLOCKCHAIN_H