#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <stdexcept>

#include "BankAccount.hpp"
#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"

// Logging helpers
void statusMessage(const std::string& message);
void errorMessage(const std::string& message);

// Input helpers
int getOption();  // This returns the chosen option
std::string getString(const std::string& prompt);
double getDouble(const std::string& prompt);  // throws exception if not a double

//For creating a new account
BankAccount* make_account();

#endif // UTILS_HPP
