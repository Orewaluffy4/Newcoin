#include "blockchain.h"

Blockchain::Blockchain(int diff) : difficulty(diff) {
    chain.push_back(createGenesisBlock());
}

Block Blockchain::createGenesisBlock() {
    Block genesis(0, "Genesis Block", "0");
    genesis.mineBlock(difficulty);
    return genesis;
}

Block Blockchain::getLastBlock() const {
    return chain.back();
}

void Blockchain::addBlock(std::string data) {
    Block block(chain.size(), data, getLastBlock().getHash());
    block.mineBlock(difficulty);
    chain.push_back(block);
}

const std::vector<Block>& Blockchain::getChain() const {
    return chain;
}
