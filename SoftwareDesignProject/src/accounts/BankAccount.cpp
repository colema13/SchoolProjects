#include "BankAccount.hpp"
#include <iostream>
#include "Utils.hpp"

BankAccount::BankAccount(std::string first, std::string last, double initBalance){
    firstName = first;
    lastName = last;
    balance = initBalance;
}

BankAccount::BankAccount(std::string first, std::string last){
    firstName = first;
    lastName = last;
    balance = 0;
}

double BankAccount::getBalance()const{
    return balance;
}

std::string BankAccount::getFirstName()const{
    return firstName;
}

std::string BankAccount::getLastName()const{
    return lastName;
}

void BankAccount::setFirstName(std::string name){
    firstName = name;
}

void BankAccount::setLastName(std::string name){
    lastName = name;
}

bool BankAccount::withdrawal(double amount){
    if(amount > 0){
        if(amount <= balance){
            balance = balance - amount;
            return true;
        }
        else {
            errorMessage("Withdrawal amount greater than balance.");
            return false;
        }
    }
    else {
        errorMessage("Invalid amount to withdrawal. Must be positive.");
        return false;
    }
}

bool BankAccount::deposit(double amount){
    if(amount > 0){
        balance = balance + amount;
        return true;
    }
    else {
        errorMessage("Invalid amount to deposit. Must be positive.");
        return false;
    }
}