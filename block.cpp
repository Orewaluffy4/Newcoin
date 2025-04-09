#include "block.h"
#include "featherhash.h"
#include <sstream>

Block::Block(int idx, const std::vector<Transaction>& txs, const std::string& prevHash)
    : index(idx), transactions(txs), previousHash(prevHash), nonce(0) {
    timestamp = std::time(nullptr);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << timestamp << previousHash << nonce;

    for (const auto& tx : transactions) {
        ss << tx.toString();
    }

    return FeatherHash::hash(ss.str());
}

void Block::mineBlock(uint32_t difficulty) {
    std::string target(difficulty, '0');

    do {
        nonce++;
        hash = calculateHash();
    } while (hash.substr(0, difficulty) != target);
}