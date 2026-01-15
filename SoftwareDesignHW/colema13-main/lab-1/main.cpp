#include <iostream>
#include <string>
#include <map>

int main(){
    std::map<std::string, double> accounts;
    std::cout<<"Welcome to the banking software!"<<std::endl;

    bool finished = false;

    while(!finished){
        std::cout<<"----------------------------------------------------------" << std::endl;
        std::cout<<"Options"<<std::endl;
        std::cout<<"0) Exit"<<std::endl;
        std::cout<<"1) Make account"<<std::endl;
        std::cout<<"2) Deposit to existing account"<<std::endl;
        std::cout<<"3) Withdraw from existing account"<<std::endl;
        std::cout<<"4) Display existing account balance"<<std::endl;
        std::cout<<"What would you like to do (Input single number):"<<std::endl;

        std::string input_string;
        std::cin >> input_string;
        //EXIT
        if(input_string == "0")
        {
            finished = true;
            std::cout<<"----------------------------------------------------------" << std::endl;
            std::cout << "Goodbye! Thank you for using the banking software." << std::endl;
        }

        //CREATE ACCOUNT
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
            accounts.insert({username, 0.0});
            std::cout << "Username has been Created." << std::endl;
            std::cout << "Balance: $0" << std::endl;
            }

        }

        //DEPOSIT FROM EXISTING ACCOUNT
        else if(input_string == "2")
        {
            std::string username;
            std::cout<<"----------------------------------------------------------" << std::endl;
            std::cout << "What account would you like to deposit into: " << std::endl;
            std::cin >> username;

            auto it = accounts.find(username);
            if (it != accounts.end()) 
            {
                char *end;
                std::string deposit;
                std::cout << "How much would you like to deposit: " << std::endl;
                std::cin >> deposit;

                double doubledeposit = std::strtod(deposit.c_str(), &end);
                if(*end == '\0')
                {
                    if(doubledeposit >= 0)
                    {
                        accounts.at(username) += doubledeposit;
                        std::cout<<"----------------------------------------------------------" << std::endl;
                        std::cout << "Money deposited" << std::endl;
                        std::cout << "Balance is now: $" << it->second << std::endl;
                    }
                    else
                    {
                        std::cout << "Please enter a positive number." << std::endl;

                    }
                }
                else
                {
                    std::cout << "Please enter a valid number." << std::endl;
                }
            }           
            else 
            {
                std::cout << "User not found." << std::endl;
            }

        }


        //WITHDRAW FROM EXISTING ACCOUNT
        else if(input_string == "3")
        {
            std::string username;
            std::cout<<"----------------------------------------------------------" << std::endl;
            std::cout << "What account would you like to withdraw from: " << std::endl;
            std::cin >> username;

            auto it = accounts.find(username);
            if (it != accounts.end()) 
            {
                char *end;
                std::string deposit;
                std::cout << "How much would you like to withdraw: " << std::endl;
                std::cin >> deposit;

                double doubledeposit = std::strtod(deposit.c_str(), &end);
                if(*end == '\0')
                {
                    if(doubledeposit >= 0)
                    {
                        if(doubledeposit <= it->second)
                        {
                            accounts.at(username) -= doubledeposit;
                            std::cout<<"----------------------------------------------------------" << std::endl;
                            std::cout << "Money Withdrawn" << std::endl;
                            std::cout << "Balance is now: $" << it->second << std::endl;
                        }
                        else
                        {
                            std::cout << "Not enough money in account." << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "Please enter a positive number." << std::endl;
                    }
                }
                else
                {
                    std::cout << "Please enter a valid number." << std::endl;
                }
            }           
            else 
            {
                std::cout << "User not found." << std::endl;
            }

        }


        //DISPLAY EXISTING ACCOUNT BALANCE
        else if(input_string == "4")
        {
            std::string username;
            std::cout<<"----------------------------------------------------------" << std::endl;
            std::cout << "What account would you like to view: " << std::endl;
            std::cin >> username;

            auto it = accounts.find(username);
            if (it != accounts.end()) 
            {
                std::cout << "Username: " << it->first << "\nBalance: $" << it->second << std::endl;

            }           
            else 
            {
                std::cout << "User not found." << std::endl;
            }

        }

        //check for invalid response
        else
        {
            std::cout<<"----------------------------------------------------------" << std::endl;
            std::cout << "Please enter a number 0-4." << std::endl;
        }

    }

    return 0;
}