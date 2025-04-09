#include "blockchain.h"
#include <iostream>

Blockchain::Blockchain() {
    difficulty = 4;
    reward = 100;

    // Create the genesis block
    std::vector<Transaction> genesisTxs = { Transaction("System", "Genesis", 0) };
    Block genesis(0, genesisTxs, "0");
    genesis.mineBlock(difficulty);
    chain.push_back(genesis);
}

Block Blockchain::getLatestBlock() const {
    return chain.back();
}

void Blockchain::minePendingTransactions(const std::string& minerAddress) {
    Block block(chain.size(), pendingTransactions, getLatestBlock().hash);
    block.mineBlock(difficulty);
    chain.push_back(block);

    // Reward the miner (added to the next block)
    pendingTransactions.clear();
    pendingTransactions.push_back(Transaction("System", minerAddress, reward));
}

void Blockchain::addTransaction(const Transaction& tx) {
    if (tx.sender.empty() || tx.recipient.empty()) {
        std::cerr << "Invalid transaction: sender or recipient is empty." << std::endl;
        return;
    }

    if (tx.amount <= 0) {
        std::cerr << "Invalid transaction: amount must be greater than 0." << std::endl;
        return;
    }

    pendingTransactions.push_back(tx);
}

int Blockchain::getBalanceOfAddress(const std::string& address) const {
    int balance = 0;

    for (const auto& block : chain) {
        for (const auto& tx : block.transactions) {
            if (tx.sender == address)
                balance -= tx.amount;
            if (tx.recipient == address)
                balance += tx.amount;
        }
    }

    return balance;
}

const std::vector<Block>& Blockchain::getChain() const {
    return chain;
}