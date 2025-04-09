#include <iostream>
#include "blockchain.h"

int main() {
    Blockchain myCoin(4); // Set difficulty

    myCoin.addBlock("First Block");
    myCoin.addBlock("Second Block");

    for (const Block& block : myCoin.getChain()) {
        std::cout << "Index: " << block.getIndex() << std::endl;
        std::cout << "Timestamp: " << block.getTimestamp() << std::endl;
        std::cout << "Hash: " << block.getHash() << std::endl;
        std::cout << "Previous Hash: " << block.getPreviousHash() << std::endl;
        std::cout << "Nonce: " << block.getNonce() << std::endl;
        std::cout << "Data: " << block.getData() << std::endl;
        std::cout << "----------------------------" << std::endl;
    }

    return 0;
}
