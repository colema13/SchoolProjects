#include <iostream>
#include <map>
#include "BankAccount.hpp"
#include "SavingAccount.hpp"
#include "CheckingAccount.hpp"
#include "Utils.hpp"

int main()
{
    std::cout << "Welcome to the banking software!" << std::endl;

    bool finished = false;
    std::map<std::string, BankAccount*> accounts;


    while(!finished)
    {
        std::cout<<"----------------------------------------------------------" << std::endl;
        std::cout << "Options" << std::endl;
        std::cout << "0) Exit" << std::endl;
        std::cout << "1) Make account" << std::endl;
        std::cout << "2) Deposit to existing account" << std::endl;
        std::cout << "3) Withdraw from existing account" << std::endl;
        std::cout << "4) Display existing account" << std::endl;
        std::cout << "5) Accrue Interest" << std::endl;
        std::cout << "6) Write a check" << std::endl;
        std::cout << "What would you like to do (Input single number):" << std::endl;

        std::string input_string;
        std::cin >> input_string;

        if(input_string == "0")
        {
            finished = true;
        }
        else if(input_string == "1")
        {
            std::string username;
            std::cout<<"----------------------------------------------------------" << std::endl;
            std::cout << "Please create a username: " << std::endl;
            std::cin >> username;
            auto it = accounts.find(username);
            if (it != accounts.end())
            {
                std::cout << "User Already Exists" << std::endl;
            }
            else
            {
                BankAccount* accountPTR = make_account();
                if (accountPTR == nullptr) 
                {
                    std::cout << "Account creation failed." << std::endl;
                }
                else
                {
                    accounts.insert({username, accountPTR});
                    std::cout << "Username has been Created." << std::endl;
                }
            }
 


        }
        else if(input_string == "2")
        {
            std::string input_balance;
            std::string username;
            std::cout<<"----------------------------------------------------------" << std::endl;
            std::cout << "Please enter your username: " << std::endl;
            std::cin >> username;
            auto it = accounts.find(username);
            if (it != accounts.end())
            {
                char *end;
                std::cout << "How much would you like to deposit?" << std::endl;
                std::cin >> input_balance;

                double dbl_balance = std::strtod(input_balance.c_str(), &end);
                if(*end == '\0')
                {
                    bool check_bal = it->second->deposit(dbl_balance);

                    if(check_bal == true)
                    {
                        std::cout << "Money Has Been Deposited. You now have $" << it->second->getBalance() << "." << std::endl;
                        
                    }
                    else
                    {
                        std::cout << "Please enter a Valid Number" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Please enter a Valid Number" << std::endl;
                }

            }
            else
            {
                std::cout << "User Does Not Exist" << std::endl;
            }
        }
        else if(input_string == "3")
        {
            std::string input_withdrawl;
            std::string username;
            std::cout<<"----------------------------------------------------------" << std::endl;
            std::cout << "Please enter your username: " << std::endl;
            std::cin >> username;
            auto it = accounts.find(username);
            if (it != accounts.end())
            {
                char *end;
                std::cout << "How much would you like to withdrawl?" << std::endl;
                std::cin >> input_withdrawl;

                double dbl_withdrawl = std::strtod(input_withdrawl.c_str(), &end);
                if(*end == '\0')
                {
                    bool check_withdrawl = it->second->withdrawl(dbl_withdrawl);

                    if(check_withdrawl == true)
                    {
                        std::cout << "Money Has Been Withdrew. You now have $" << it->second->getBalance() << "." << std::endl;
                        
                    }
                    else
                    {
                        std::cout << "Please enter a Valid Number" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Please enter a Valid Number" << std::endl;
                }

            }
            else
            {
                std::cout << "User Does Not Exist" << std::endl;
            }
        }
        else if(input_string == "4")
        {
            std::string input_balance;
            std::string username;
            std::cout<<"----------------------------------------------------------" << std::endl;
            std::cout << "Please enter your username: " << std::endl;
            std::cin >> username;
            auto it = accounts.find(username);
            if (it != accounts.end())
            {
                bool typeAccount;
                BankAccount *b = it->second;
                SavingAccount *d = dynamic_cast<SavingAccount*>(b);
                if(d == nullptr)
                {
                    //CheckingAccount
                    typeAccount = false;
                }
                else
                {
                    //SavingsAccount
                    typeAccount = true;
                }
                std::cout << "Account Found!" << std::endl;
                std::cout<<"----------------------------------------------------------" << std::endl;
                std::cout << "Username: " << it->first << std::endl;
                std::cout << "Name: " << it->second->getFirst_name() << " " << it->second->getLast_name() << std::endl;
                if(typeAccount == false)
                {
                    std::cout << "Type: Checking Account" << std::endl;
                }
                else
                {
                    std::cout << "Type: Savings Account" << std::endl;
                    std::cout << "Interest Rate: " << d->getInterestRate() << std::endl;
                }
                std::cout << "Balance: $" << it->second->getBalance() << std::endl;


            }
            else
            {
                std::cout << "User Does Not Exist" << std::endl;
            }

        }
        else if(input_string == "5")
        {
            for(auto const& x : accounts)
            {
                std::cout<<"----------------------------------------------------------" << std::endl;
                BankAccount *b = x.second;
                SavingAccount *d = dynamic_cast<SavingAccount*>(b);
                if(d == nullptr)
                {
                std::cout << "Cast Failed" << std::endl;
                }
                else
                {
                    std::cout << "Cast Worked" << std::endl;
                    d->accrue_interest();

                }
            }
        }
        else if(input_string == "6")
        {
            std::string username;
            std::cout<<"----------------------------------------------------------" << std::endl;
            std::cout << "Please enter your username: " << std::endl;
            std::cin >> username;
            auto it = accounts.find(username);
            if (it != accounts.end())
            {
                BankAccount *b = it->second;
                CheckingAccount *d = dynamic_cast<CheckingAccount*>(b);
                if(d == nullptr)
                {
                    std::cout << "Cannot Write Check From Savings Account." << std::endl;
                }
                else
                {
                    std::string transferAcc;
                    std::string transferAmount;
                    char *end;
                    std::cout << "What account do you want to write a check to?" << std::endl;
                    std::cin >> transferAcc;
                    auto it2 = accounts.find(transferAcc);
                    if (it2 != accounts.end())
                    {
                        std::cout << "How much would you like to write the check for?" << std::endl;
                        std::cin >> transferAmount;
                        double dbl_transfer = std::strtod(transferAmount.c_str(), &end);
                        if(*end == '\0')
                        {
                            bool check_bal = d->writeCheck(*it2->second, dbl_transfer);

                            if(check_bal == true)
                            {
                                std::cout << "Money Has Been Transfered. You now have $" << it->second->getBalance() << "." << std::endl;
                        
                            }
                            else
                            {
                                std::cout << "Please enter a Valid Number" << std::endl;
                            }
                        }
                        else
                        {
                            std::cout << "Please enter a Valid Number" << std::endl;
                        }

                    }
                    else
                    {
                        std::cout << "User Does Not Exist" << std::endl;
                    }  
                }  
            }
            else
            {
                std::cout << "User Does Not Exist" << std::endl;
            }

        }
    }


    //used https://stackoverflow.com/questions/26281979/how-do-you-loop-through-a-stdmap
    for (auto const& x : accounts)
    {
        delete x.second;
        std::cout << "Working" << std::endl;
    }
}