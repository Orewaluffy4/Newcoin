#include "block.h"
#include "transaction.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Transaction> genesisTxs = {
        Transaction("System", "Alice", 50.0),
        Transaction("System", "Bob", 50.0)
    };

    Block genesis(0, genesisTxs, "0");
    std::cout << "Genesis Block Hash: " << genesis.hash << "\n";
    for (const auto& tx : genesis.transactions) {
        std::cout << tx << "\n";
    }

    std::vector<Transaction> block1Txs = {
        Transaction("Alice", "Bob", 10.0),
        Transaction("Bob", "Charlie", 5.0)
    };

    Block block1(1, block1Txs, genesis.hash);
    std::cout << "\nBlock 1 Hash: " << block1.hash << "\n";
    for (const auto& tx : block1.transactions) {
        std::cout << tx << "\n";
    }

    return 0;
}
