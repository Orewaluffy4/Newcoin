#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#include <vector>

class Blockchain {
private:
    std::vector<Block> chain;
    int difficulty;

    Block createGenesisBlock();
    Block getLastBlock() const;

public:
    Blockchain(int difficulty = 4);
    void addBlock(std::string data);
    const std::vector<Block>& getChain() const;
};

#endif
