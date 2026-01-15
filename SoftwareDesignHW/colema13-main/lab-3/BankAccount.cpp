#include "BankAccount.hpp" 

#include <string>
#include <iostream>
   
BankAccount::BankAccount(double init_balance) : balance(init_balance) {};

BankAccount::BankAccount(std::string init_first, std::string init_last)
{   
    first_name = init_first; 
    last_name = init_last;
    balance = 0.0;
}

BankAccount::~BankAccount() {}

std::string BankAccount::getFirst_name()
{
    return first_name;
}

std::string BankAccount::getLast_name()
{
    return last_name;
}
    
double BankAccount::getBalance()
{
    return balance;
}

void BankAccount::setFirst_name(std::string newFirst_name)
{
    first_name = newFirst_name;
}

void BankAccount::setLast_name(std::string newLast_name)
{
    last_name = newLast_name;
}

bool BankAccount::deposit(double input_balance)
{
    if(input_balance >= 0)
    {
        balance = balance + input_balance;

        return true;
    }
    else
    {
        return false;
    }

}

bool BankAccount::withdrawl(double output_balance)
{
    if(output_balance >= 0 && output_balance <= balance)
    {
        balance = balance - output_balance;

        return true;
    }
    else
    {
        return false;
    }
}