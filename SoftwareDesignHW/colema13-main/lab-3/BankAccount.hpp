#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>

class BankAccount
{
    public:

    std::string first_name;
    std::string last_name;

    BankAccount(double init_balance);

    BankAccount(std::string init_first, std::string init_last);

    virtual ~BankAccount() = 0;

    std::string getFirst_name(); //checked

    std::string getLast_name(); //checked

    double getBalance(); //used in to_string

    void setFirst_name(std::string newFirst_name); //checked

    void setLast_name(std::string newLast_name); //checked

    bool deposit(double input_balance); //checked

    bool withdrawl(double output_balance); //used in CheckingAccount

    virtual std::string to_string() = 0; //checked





    private:

    double balance;


};

#endif