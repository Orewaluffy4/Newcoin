#include <iostream>
#include "blockchain.h"

int main() {
    Blockchain myCoin;

    std::cout << "Mining block 1..." << std::endl;
    myCoin.addTransaction(Transaction("Alice", "Bob", 10));
    myCoin.minePendingTransactions("Miner1");

    std::cout << "Balance of Miner1: " << myCoin.getBalanceOfAddress("Miner1") << std::endl;

    std::cout << "Mining block 2..." << std::endl;
    myCoin.addTransaction(Transaction("Bob", "Charlie", 5));
    myCoin.minePendingTransactions("Miner1");

    std::cout << "Balance of Miner1: " << myCoin.getBalanceOfAddress("Miner1") << std::endl;

    std::cout << "Blockchain:" << std::endl;
    for (const auto& block : myCoin.getChain()) {
        std::cout << "------------------------" << std::endl;
        std::cout << "Index: " << block.getIndex() << std::endl;
        std::cout << "Timestamp: " << block.getTimestamp() << std::endl;
        std::cout << "Hash: " << block.getHash() << std::endl;
        std::cout << "Previous Hash: " << block.getPreviousHash() << std::endl;
        std::cout << "Nonce: " << block.getNonce() << std::endl;
        std::cout << "Data: " << std::endl;
        for (const auto& d : block.getData()) {
            std::cout << "  " << d << std::endl;
        }
    }

    return 0;
}