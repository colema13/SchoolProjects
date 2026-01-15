#include "Utils.hpp"


#include <iostream>   
#include <limits>    

//  logging helpers


void statusMessage(const std::string& message) {
    std::cout << "[STATUS]: " << message << std::endl;
}

void errorMessage(const std::string& message) {
    std::cout << "[ERROR]: " << message << std::endl;
}


//  this is for getting user input

std::string getString(const std::string& prompt) {
    std::cout << prompt;
    std::string input;

    // this is to ensure we ignore leading whitespace
    std::getline(std::cin >> std::ws, input);

    return input;
}

double getDouble(const std::string& prompt) {
    std::string input = getString(prompt);

    // Attempt to convert the string to a double
    try {
        size_t idx = 0;
        double value = std::stod(input, &idx);

        // Check if the entire string was converted
        if (idx != input.size()) {
            throw std::invalid_argument("Input is not a valid double.");
        }

        return value;
    } catch (const std::exception&) {
        // Rethrow as invalid_argument for consistency
        throw std::invalid_argument("Input is not a valid double.");
    }
}

int getOption() {
    std::cout << "\nOptions\n";
    std::cout << "0) Exit\n";
    std::cout << "1) Make account\n";
    std::cout << "2) Delete account\n";
    std::cout << "3) Deposit to existing account\n";
    std::cout << "4) Withdraw from existing account\n";
    std::cout << "5) Display existing account\n";
    std::cout << "6) Accrue Interest\n";
    std::cout << "7) Write a check\n";

    std::string input = getString("What would you like to do (Input single number): ");

    try {
        size_t idx = 0;
        int option = std::stoi(input, &idx);
// This is for checking if there are extra characters after the number
        if (idx != input.size()) {
            // If there are extra characters, throw an exception
            throw std::invalid_argument("There is an extra character after the number. Please try again.");
        }

        return option;
    } catch (const std::exception&) {
        // If conversion fails, return -1 to indicate invalid input
        errorMessage("Invalid option. Please, enter a number!");
        return -1;
    }
}

// this is for creating a new account

BankAccount* make_account() {
    BankAccount* acct = nullptr;

    std::string first = getString("Enter the first name: ");
    std::string last  = getString("Enter the last name: ");

    std::string choice = getString(
        "Would you like to make a savings (1) or checking (2) account: "
    );

    if (choice == "1") {
        // getDouble will throw std::invalid_argument if user types junk
        double interest_rate = getDouble("Enter the interest rate: ");

        if (interest_rate > 0 && interest_rate < 1) {
            acct = new SavingsAccount(first, last, interest_rate);
            statusMessage("Savings account created.");
        } else {
            errorMessage("Interest rate must be between 0 and 1");
        }
    } else if (choice == "2") {
        acct = new CheckingAccount(first, last);
        statusMessage("Checking account created.");
    } else {
        errorMessage("That is not a valid .");
    }

    return acct;
}
