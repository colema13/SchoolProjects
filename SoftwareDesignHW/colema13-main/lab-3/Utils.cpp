#include "Utils.hpp"

#include "iostream"
#include <string>

std::string input;
std::string first_name;
std::string last_name;

BankAccount* make_account()
{
    BankAccount* newAccount = nullptr;

    std::cout << "What is the first name you want on your account" << std::endl;
    std::cin >> first_name;
    std::cout << "What is the last name you want on your account" << std::endl;
    std::cin >> last_name;

    std::cout << "What type of account would you like to open?" << std::endl;
    std::cout << "1) Savings Account" << std::endl;
    std::cout << "2) Checking Account" << std::endl;
    std::cin >> input;

    if(input == "1")
    {
        char *end;
        std::string interest;
        std::cout << "Please enter a interest rate that is between 0 and 1: ";
        std::cin >> interest;

        double dbl_interest = std::strtod(interest.c_str(), &end);
        if(*end == '\0')
        {
            if(dbl_interest > 0 && dbl_interest < 1)
            {
                newAccount = new SavingAccount(first_name, last_name, dbl_interest);
            }
            else
            {
                std::cout << "Interest rate must be between 0 and 1. Account has not been created." << std::endl;
            }
        }
        else
        {
            std::cout << "Interest rate must be between 0 and 1. Account has not been created." << std::endl;
        }
    }
    else if(input == "2")
    {
        newAccount = new CheckingAccount(first_name, last_name);

    }
    else
    {
        std::cout << "Invalid Choice. Account has not been created." << std::endl;
    }

return newAccount;
}
