#include "BankAccount.hpp"
#include "SavingAccount.hpp"

#include <string>
#include <iostream>

SavingAccount::SavingAccount(double init_balance, double InterestRate) : BankAccount(init_balance), interest_rate(InterestRate) {};

SavingAccount::SavingAccount(std::string firstName, std::string lastName) : BankAccount(firstName, lastName)
{
    interest_rate = .1;

}

double SavingAccount::getInterestRate()
{
    return interest_rate;
}

void SavingAccount::setInterestRate(double newInterestRate)
{
    if(newInterestRate > 0)
    {
        interest_rate = newInterestRate;
    }
    else
    {
        std::cout << "Please enter a valid number" << std::endl;
    }
}

void SavingAccount::accrue_interest()
{
    double CurrentBalance = getBalance();

    double ExtraMoney = interest_rate*CurrentBalance;
    deposit(ExtraMoney);

}

std::string SavingAccount::to_string()
{
    std::string Data = "Saving Account balance: $" + std::to_string(getBalance()) + ", interest rate: " + std::to_string(interest_rate);
    return Data;
}