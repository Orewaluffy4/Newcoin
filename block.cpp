#include "block.h"
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

Block::Block(int idx, std::string data, std::string prevHash)
    : index(idx), data(data), previousHash(prevHash), timestamp(time(nullptr)), nonce(0) {
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << previousHash << timestamp << data << nonce;
    std::string input = ss.str();

    unsigned char hashBytes[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input.c_str(), input.size(), hashBytes);

    std::stringstream hashSS;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        hashSS << std::hex << std::setw(2) << std::setfill('0') << (int)hashBytes[i];
    }

    return hashSS.str();
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
}

int Block::getIndex() const { return index; }
std::string Block::getPreviousHash() const { return previousHash; }
std::string Block::getHash() const { return hash; }
std::string Block::getData() const { return data; }
long Block::getTimestamp() const { return timestamp; }
int Block::getNonce() const { return nonce; }
