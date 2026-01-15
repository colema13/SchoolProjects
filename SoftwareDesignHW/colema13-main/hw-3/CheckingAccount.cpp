#include "CheckingAccount.hpp"
#include <bits/stdc++.h>


CheckingAccount::CheckingAccount(double init_balance) : BankAccount(init_balance), check_log()  {};

CheckingAccount::CheckingAccount(std::string firstName, std::string lastName) : BankAccount(firstName, lastName), check_log()  {};

std::list<double> CheckingAccount::getCheckLog()
{
    return check_log;
}

bool CheckingAccount::writeCheck(BankAccount& check, double amount)
{
    if (withdrawl(amount))
    {
        if (check.deposit(amount))
        {
            check_log.push_back(amount);
            return true;
        }
        else
        {
            deposit(amount);
            return false;
        }
        
    }
    else
    {
        return false;
    }
}

std::string CheckingAccount::to_string()
{
    std::string Data = "Checking Account balance: $" + std::to_string(getBalance()) + ", checks written: " + std::to_string(check_log.size());
    return Data;
}