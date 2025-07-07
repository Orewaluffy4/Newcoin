# 🪙 __**NewCoin — A Simple Blockchain in C++**__

_NewCoin_ is an educational blockchain project written in **C++**. It demonstrates the core principles of blockchain technology including block mining, hashing, transactions, and wallet systems — all in a simple and modular way.

---

## __**🚀 Features**__

- ⛓️ **Blockchain Structure** with indexed blocks, hashes, and links  
- 🔐 **Wallet System** with pseudo key-pair generation  
- 💰 _Basic Transaction Model_ with sender, receiver, and amount  
- 🪙 **Proof-of-Work Mining** with adjustable difficulty  
- 🧾 _Command-line Output_ of blockchain data

---

## __**📁 File Structure**__

NewCoin/ ├── main.cpp              → Entry point ├── block.{h,cpp}         → Block structure & mining ├── blockchain.{h,cpp}    → Chain management logic ├── transaction.{h,cpp}   → Transaction data model ├── wallet.{h,cpp}        → Simulated key-pair and transaction creation ├── featherhash.{h,cpp}   → SHA-256 hashing logic (OpenSSL)

---

## __**⚙️ Requirements**__

- **C++11 or later**
- _OpenSSL_ development libraries
- A standard C++ compiler (e.g. `g++`, `clang++`)

---

## __**🛠️ Build Instructions**__

```bash
g++ -std=c++11 main.cpp block.cpp blockchain.cpp transaction.cpp wallet.cpp featherhash.cpp -lssl -lcrypto -o newcoin
./newcoin


---

📈 Future Improvements

🖊️ Digital signing using real asymmetric cryptography

💾 File-based blockchain persistence (e.g., JSON or binary)

🌐 P2P node simulation for consensus

🧮 Wallet balance tracking and mempool system



---

📜 License

This project is intended for educational use only.
License: MIT (or define your own)


---

👨‍💻 Author

Pranav Pradeesh
GitHub: Orewaluffy4


---

Let me know if you'd like:
- A dark-themed version for GitHub markdown preview
- A `.docx` or `.pdf` version
- A Malayalam or Hindi translation of the README

