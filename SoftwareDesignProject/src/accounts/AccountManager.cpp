#include "AccountManager.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"
#include "Utils.hpp"

#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include<iostream>
#include<string>



AccountManager::AccountManager():numAccounts(0){

}

/*
            Creating an account: 
            - checking if the username exist in our database
            - if not then we can go ahead and create the account
*/

bool AccountManager::addAccount(const std::string& username){


   if (accounts.count(username)){
       std::cout<<"This username is already taken!"<<std::endl;
       return false;
   }

   BankAccount* acct = make_account();
   accounts[username] = acct;
   numAccounts++;
   return true;

}

/*
    deleting the account and erasing it from our database completely
*/


bool AccountManager::deleteAccount(const std::string& username){
   auto i = accounts.find(username);
   if (i !=  accounts.end()){
       delete i -> second;
       accounts.erase(i);
       numAccounts--;
       return true;

   }
   else{
    return false;
   }



}



std::string AccountManager::displayAccount(const std::string& username) {
    auto i = accounts.find(username);
    if(i != accounts.end()){

        return i->second->toString();
        
    }
    else{ 
        return " Account not found";
    }
}

/*

to make a withdrawal: 
- find the account 
-if we cant find it then sending an error message to our user 
-if the account is found in our database then continue to withdraw 

*/


bool AccountManager:: makeWithdrawal(const std::string& username, double amount){
   auto i = accounts.find(username);


   if(i == accounts.end()){
       errorMessage("You do no have an account with our bank");
       return false;


       }
       
    return i->second->withdrawal(amount);
}


/*

Make deposite: 
- first finding the account to make sure it exists in our database
- if not found then sending out an error message 
- if found then go ahead and deposite the money
*/

bool AccountManager:: makeDeposit(const std::string& username, double amount){
   auto i = accounts.find(username);
  
   if (i == accounts.end()){
       errorMessage(" U cant make a deposit! you dont have an account :( )");
    
       return false;
   }
   else{
       return i -> second -> deposit(amount);
  
   }
}



/*
    Add interest :
    - using dynamic casting 
    - add interest to them
*/

void AccountManager::addInterest() {
   for (auto& pair : accounts) {
       SavingsAccount* savingsAccount = dynamic_cast<SavingsAccount*>(pair.second);
       if (savingsAccount != nullptr) {
           savingsAccount->accrueInterest();
       }
   }
   statusMessage("Interest added to all savings accounts successfully!");
}

//writecheck function


bool AccountManager:: writeCheck(const std::string& checkWriter, const std::string& checkReceiver, double amount) {

   // checking to see if the person writting the check has an account in our database
   auto writerIt = accounts.find(checkWriter);
   if (writerIt == accounts.end()) {
       errorMessage("Sorry, the checkWriter account does not exist in our system");
       return false;
   }
  
   //Does the reciver have an account in our bank?
   auto receiverIt = accounts.find(checkReceiver);
   if (receiverIt == accounts.end()) {
       errorMessage(" Sorry, the check receiver account does not exist!");
       return false;
   }
  // making sure the amount is above zero
   if (amount <= 0) {
       errorMessage("Invalid amount!");
       return false;
   }
  
   //Making sure they are not writting checks using their savings account 
   // checks should only be sent using checking account
   CheckingAccount* checkingAccount = dynamic_cast<CheckingAccount*>(writerIt->second);
   if (checkingAccount == nullptr) {
       errorMessage("Invalid account! The check writer is not a checking account. ");
       return false;
   }
  
   // making sure the check writer does not write a check to themselves 
   if (checkWriter == checkReceiver) {
       errorMessage("You cannot write a check to yourself :|");
       return false;
   }

   //Checking if writer has enough funds BEFORE doing anything!
   if (amount > checkingAccount->getBalance()) {
       errorMessage("Insufficient funds!");
       return false;
   }

   //Using the CheckingAccount's writeCheck method which handles both withdrawal and deposit :)
   bool success = checkingAccount->writeCheck(*(receiverIt->second), amount);
   
   if (!success) {
       
       return false;
   }
  
   return true;
}



// getting the number of accounts 

int AccountManager:: getNumAccounts() const{
   return numAccounts;


}





void AccountManager::serialize(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        errorMessage("Could not open file: " + filename);
        return;
    }

    for (const auto& entry : accounts) {
        const std::string& username = entry.first;
        BankAccount* acct = entry.second;

        file << username << "," << acct->serialize() << std::endl;
    }

    statusMessage("Accounts saved to " + filename);
}

void AccountManager::deserialize(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        statusMessage("No save file found");
        return;
    }

    // Clear old accounts
    for (auto &p : accounts) delete p.second;
    accounts.clear();
    numAccounts = 0;

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::vector<std::string> tokens;
        boost::split(tokens, line, boost::is_any_of(","));

        std::string username = tokens[0];
        std::string type     = tokens[1];
        std::string first    = tokens[2];
        std::string last     = tokens[3];
        double balance       = std::stod(tokens[4]);

        BankAccount* acct = nullptr;

        if (type == "savings") {
            double interest = std::stod(tokens[5]);
            acct = new SavingsAccount(first, last, balance, interest);
        }
        else if (type == "checkings") {
            CheckingAccount* ca = new CheckingAccount(first, last, balance);

            for (size_t i = 5; i < tokens.size(); i++) {
                ca->getCheckLog().push_back(std::stod(tokens[i]));
            }

            acct = ca;
        }

        accounts[username] = acct;
        numAccounts++;
    }

    statusMessage("Accounts loaded from " + filename);

}
    /*

the destuctor: deleting all the dynamic memory of the account manager!

*/
AccountManager::~AccountManager() {
   for (auto& pair : accounts) {
       delete pair.second;
   }

   accounts.clear();
}


