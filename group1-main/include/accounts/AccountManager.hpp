#ifndef ACCOUNTMANAGER_HPP
#define ACCOUNTMANAGER_HPP

#include <map>
#include <string>
#include "BankAccount.hpp"

class AccountManager {
public:
    AccountManager();
    bool addAccount(const std:: string& username);
    bool deleteAccount(const std::string& username);
    std:: string displayAccount(const std::string& username);
    bool makeWithdrawal(const std::string& username, double amount);
    bool makeDeposit(const std::string& username, double amount);
    void addInterest();
    bool writeCheck(const std::string& checkWriter, const std::string& checkReceiver, double amount);
    
    int getNumAccounts() const;

    // ⭐ MUST BE HERE
    void serialize(const std::string& filename) const;
    void deserialize(const std::string& filename);

    ~AccountManager();

private:
    int numAccounts;
    std::map<std::string, BankAccount*> accounts;
};

#endif
