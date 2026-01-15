#ifndef CHECKINGACCOUNT_HPP
#define CHECKINGACCOUNT_HPP

#include "BankAccount.hpp"
#include <string>
#include <list>

class CheckingAccount : public BankAccount
{
    public:

    CheckingAccount(double balance);

    CheckingAccount(std::string firstName, std::string lastName);

    std::list<double> getCheckLog();

    bool writeCheck(BankAccount& check, double amount); //checked

    std::string to_string(); //checked


    private:
        
        std::list<double> check_log;


};

#endif