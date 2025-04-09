#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <ctime>

class Block {
private:
    int index;
    std::string previousHash;
    std::string hash;
    std::string data;
    long timestamp;
    int nonce;

public:
    Block(int idx, std::string data, std::string prevHash);
    std::string calculateHash() const;
    void mineBlock(int difficulty);

    // Getters
    int getIndex() const;
    std::string getPreviousHash() const;
    std::string getHash() const;
    std::string getData() const;
    long getTimestamp() const;
    int getNonce() const;
};

#endif
