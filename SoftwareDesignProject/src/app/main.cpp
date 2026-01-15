#include "AccountManager.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cstdlib>

int main(){
    statusMessage("Welcome to the banking software!");

    bool finished = false;

    AccountManager accountManager;
    accountManager.deserialize("account_info");

    while(!finished){
        int input = getOption();

        if(input == 0){
            accountManager.serialize("account_info");
            statusMessage("Thank you for using the software");
            finished = true;
        }
        else if(input == 1){
            std::string user = getString("Enter the username:");
            
            bool check = accountManager.addAccount(user);
            if(check == false)
            {
                errorMessage("This username is already taken!");
            }
            else
            {
                statusMessage("New Account Created");
            }
        }  
        else if(input == 2){
            std::string user = getString("Enter the username:");
            
            bool check = accountManager.deleteAccount(user);
            if(check == false)
            {
                errorMessage("Username not found");
            }
            else
            {
                statusMessage("User deleted");
            }
        }
        else if(input == 3){
            std::string user = getString("Enter the username:");

            double deposit_amount = getDouble("Enter amount: ");

            bool check_deposit = accountManager.makeDeposit(user, deposit_amount);
            if(check_deposit == false)
            {
                errorMessage("Deposit did not go through");
            }
            else
            {
                statusMessage("Money has been deposited");
            }
        }
        else if(input == 4){
            std::string user = getString("Enter the username:");

            double withdrawal_amount = getDouble("Enter amount: ");

            bool check_withdrawal = accountManager.makeWithdrawal(user, withdrawal_amount);
            if(check_withdrawal == false)
            {
                errorMessage("Withdrawal did not go through");
            }
            else
            {
                statusMessage("Money has been Withdrawn");
            }
        }
        
        else if(input == 5){
            std::string user = getString("Enter the username:");
            
            statusMessage(accountManager.displayAccount(user));
        }
        
        else if(input == 6){

            accountManager.addInterest();            
        }


        else if(input == 7){ 
            std::string user = getString("Enter the username of the account writing the check:");  

            std::string target_account = getString("Enter the username of the account cashing the check:"); 

            double check_amount = getDouble("Enter amount");
            
            bool check = accountManager.writeCheck(user, target_account, check_amount);
            if(check == false)
            {
                errorMessage("Check not written");
            }
            else
            {
                statusMessage("Check has been written");
            }
        }
        else{

            errorMessage("I am sorry, this is not a valid choice!");
        }

    }
    return 0; 
}