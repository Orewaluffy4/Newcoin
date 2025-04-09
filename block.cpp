#include "block.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

Block::Block(int idx, const std::vector<Transaction>& txs, const std::string& prevHash)
    : index(idx), transactions(txs), previousHash(prevHash) {
    time_t now = time(0);
    timestamp = std::to_string(now);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << timestamp << previousHash;
    for (const auto& tx : transactions) {
        ss << tx.sender << tx.recipient << tx.amount;
    }

    std::string input = ss.str();
    unsigned char hashOutput[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hashOutput);

    std::stringstream result;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        result << std::hex << std::setw(2) << std::setfill('0') << (int)hashOutput[i];
    }

    return result.str();
}
