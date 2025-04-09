#ifndef WALLET_H
#define WALLET_H

#include <string>
#include "transaction.h"

class Wallet {
private:
    std::string publicKey;
    std::string privateKey;

    std::string generateKey(); // Simulate key generation

public:
    Wallet();

    std::string getPublicKey() const;
    std::string getPrivateKey() const;

    Transaction createTransaction(const std::string& to, double amount) const;
};

#endif // WALLET_H