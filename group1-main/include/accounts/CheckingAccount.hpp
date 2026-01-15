#ifndef CHECKINGACCOUNT_HPP
#define CHECKINGACCOUNT_HPP

#include "BankAccount.hpp"
#include <list>

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(std::string first, std::string last, double initBalance)
        : BankAccount(first, last, initBalance) {}
    
    CheckingAccount(std::string first, std::string last)
        : BankAccount(first, last) {}

    bool writeCheck(BankAccount &a, double amount);

    std::string toString();

    // FIXED: must return reference, not value
    std::list<double>& getCheckLog();

    std::string serialize() const override;

    ~CheckingAccount() {} 

private:
    std::list<double> checkLog;
};

#endif
