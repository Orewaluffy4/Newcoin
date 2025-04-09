#include "wallet.h"
#include "featherhash.h" // For hashing to simulate keys
#include <ctime>
#include <sstream>

Wallet::Wallet() {
    publicKey = generateKey();
    privateKey = generateKey(); // In a real scenario, this would be securely paired
}

std::string Wallet::generateKey() {
    std::stringstream ss;
    ss << std::time(nullptr) << rand(); // Add randomness
    return FeatherHash::hash(ss.str());
}

std::string Wallet::getPublicKey() const {
    return publicKey;
}

std::string Wallet::getPrivateKey() const {
    return privateKey;
}

Transaction Wallet::createTransaction(const std::string& to, double amount) const {
    return Transaction(publicKey, to, amount);
}