#include "CheckingAccount.hpp"
#include "BankAccount.hpp"
#include <sstream>
#include<string>

bool CheckingAccount::writeCheck(BankAccount &a, double amount){
    bool success = withdrawal(amount);

    if(success){
        a.deposit(amount);
        checkLog.push_back(amount);
    }

    return success;
}

std::string CheckingAccount::toString(){
    return "Checking Account Balance: $" + std::to_string(getBalance());
}

std::list<double>& CheckingAccount::getCheckLog(){
    return checkLog;
}

std::string CheckingAccount::serialize() const{
    std::ostringstream out;
    out <<"checkings"
        <<","<< getFirstName()
        <<","<< getLastName()
        <<","<< getBalance();
    for (double c:checkLog){
        out << "," << c;
    }
    return out.str();
}

