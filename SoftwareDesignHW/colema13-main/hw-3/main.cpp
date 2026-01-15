#include <iostream>
#include "BankAccount.hpp"
#include "SavingAccount.hpp"
#include "CheckingAccount.hpp"

int main()
{
    SavingAccount sav1(1000.0, 0.05);
    sav1.setFirst_name("Timmy");
    sav1.setLast_name("Stevens");

    std::cout << sav1.getFirst_name() << " " << sav1.getLast_name() <<  " " << sav1.getInterestRate() << std::endl;

    sav1.setInterestRate(.01);

    sav1.deposit(-500.0);

    std::cout << sav1.getFirst_name() << " " << sav1.getLast_name() <<  " " << sav1.getInterestRate() << std::endl;
    
    std::cout << sav1.to_string() << std::endl;
    sav1.deposit(500.0);
    std::cout << "After depositing $500: " << sav1.to_string() << std::endl;
    sav1.accrue_interest();
    std::cout << "After accruing interest: " << sav1.to_string() << std::endl;

    CheckingAccount chk1(800.0);
    std::cout << chk1.to_string() << std::endl;

    chk1.deposit(200.0);
    std::cout << "After depositing $200: " << chk1.to_string() << std::endl;

    if (chk1.writeCheck(sav1, 300.0))
    {
        std::cout << "Check of $300 written successfully!" << std::endl;
    }
    else
    {
        std::cout << "Failed to write check!" << std::endl;
    }

    if (chk1.writeCheck(sav1, 30000.0))
    {
        std::cout << "Check of $300 written successfully!" << std::endl;
    }
    else
    {
        std::cout << "Failed to write check: insufficient funds." << std::endl;
    }

    std::cout << "Checking account: " << chk1.to_string() << std::endl;
    std::cout << "Savings account: " << sav1.to_string() << std::endl;

    std::cout << "Checks written by checking account: " << chk1.getCheckLog().size() << std::endl;

    return 0;
}