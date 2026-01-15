#ifndef SAVINGACCOUNT_HPP
#define SAVINGACCOUNT_HPP

#include "BankAccount.hpp"
#include <string>

class SavingAccount : public BankAccount
{
    public:
    
    SavingAccount(double init_balance, double InterestRate);

    SavingAccount(std::string firstName, std::string lastName);

    double getInterestRate(); //checked

    void setInterestRate(double newInterestRate); //checked

    void accrue_interest(); //checked

    std::string to_string(); //checked

    private:

    double interest_rate;




};

#endif