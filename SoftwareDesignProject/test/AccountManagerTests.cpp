//My head hurts trying to test this
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "AccountManager.hpp"
#include <iostream>

BOOST_AUTO_TEST_SUITE(account_manager_suite, * boost::unit_test::timeout(10))
BOOST_AUTO_TEST_CASE(constructor)
{
    AccountManager c;
    BOOST_CHECK_EQUAL(c.getNumAccounts(), 0);

}
BOOST_AUTO_TEST_CASE(deleteAccount)
{
    AccountManager c;
    c.addAccount("username1");
    BOOST_CHECK_EQUAL(c.getNumAccounts(), 1);
    c.deleteAccount("username1");
    BOOST_CHECK_EQUAL(c.getNumAccounts(), 0);

}
BOOST_AUTO_TEST_CASE(displayAccount)
{
    AccountManager c;
    //must be a Checking Account
    std::cout << "Please use Checking Account" << std::endl;
    c.addAccount("username1");
    BOOST_CHECK_EQUAL(c.displayAccount("username1"), "Checking Account Balance: $0.000000");
    //must be a Savings Account
    std::cout << "Please use Savings Account" << std::endl;
    c.addAccount("username2");
    BOOST_CHECK_EQUAL(c.displayAccount("username2"), "Savings Account Balance: $0.000000, Interest Rate: 0.100000");

}
BOOST_AUTO_TEST_CASE(makeDeposit)
{
    AccountManager c;
    c.addAccount("username1");
    BOOST_CHECK_EQUAL(c.makeDeposit("username", 10.0), false);
    BOOST_CHECK_EQUAL(c.makeDeposit("username1", 10.0), true);
    BOOST_CHECK_EQUAL(c.displayAccount("username1"), "Checking Account Balance: $10.000000");

}
BOOST_AUTO_TEST_CASE(makeWithdrawal)
{
    AccountManager c;
    c.addAccount("username1");
    c.makeDeposit("username1", 10.0);
    BOOST_CHECK_EQUAL(c.makeWithdrawal("username", 10.0), false);
    BOOST_CHECK_EQUAL(c.makeWithdrawal("username1", 10.0), true);
    BOOST_CHECK_EQUAL(c.displayAccount("username1"), "Checking Account Balance: $0.000000");
}

BOOST_AUTO_TEST_CASE(addInterest)
{
    std::cout << "WARNING: MUST CHOOSE 2 SAVINGS ACCOUNTS AT .1 INTEREST AND 1 CHECKING ACCOUNT" << std::endl;
    AccountManager c;
    //must be a savings accounts
    c.addAccount("username1");
    c.addAccount("username2");
    //must be checking Account
    c.addAccount("username3");

    c.makeDeposit("username1", 10.0);
    c.makeDeposit("username2", 10.0);
    c.makeDeposit("username3", 10.0);
    c.addInterest();
    BOOST_CHECK_EQUAL(c.displayAccount("username1"), "Savings Account Balance: $11.000000, Interest Rate: 0.100000");
    BOOST_CHECK_EQUAL(c.displayAccount("username2"), "Savings Account Balance: $11.000000, Interest Rate: 0.100000");
    BOOST_CHECK_EQUAL(c.displayAccount("username3"), "Checking Account Balance: $10.000000");

}

BOOST_AUTO_TEST_CASE(serialize)
{
    AccountManager c;
    std::cout << "MAKE THIS A CHECKING ACCOUNT" << std::endl;
    c.addAccount("username1");
    std::cout << "MAKE THIS A SAVINGS ACCOUNT w/ .1" << std::endl;
    c.addAccount("username2");
    c.makeDeposit("username1", 10.0);
    c.serialize("csvTest.csv");
    BOOST_CHECK_EQUAL(c.getNumAccounts(), 2);
    BOOST_CHECK_EQUAL(c.displayAccount("username1"), "Checking Account Balance: $10.000000");
    BOOST_CHECK_EQUAL(c.displayAccount("username2"), "Savings Account Balance: $0.000000, Interest Rate: 0.100000");
    std::cout << "End of serialize" << std::endl;
}

BOOST_AUTO_TEST_CASE(writeCheck)
{
 AccountManager c;
 c.addAccount("username1");
 c.makeDeposit("username1", 10.0);
 c.addAccount("username2");
 BOOST_CHECK_EQUAL(c.writeCheck("username", "username2", 10.0), false);
 BOOST_CHECK_EQUAL(c.writeCheck("username1", "username", 10.0), false);
 BOOST_CHECK_EQUAL(c.writeCheck("username1", "username2", -10.0), false);

 std::cout << "Please Make this a savings Account" << std::endl;
 c.addAccount("username3");
 BOOST_CHECK_EQUAL(c.writeCheck("username3", "username1",10.0), false);
 BOOST_CHECK_EQUAL(c.writeCheck("username1", "username1", 10.0), false);
 BOOST_CHECK_EQUAL(c.writeCheck("username1", "username2", 10.0), true);
 BOOST_CHECK_EQUAL(c.displayAccount("username1"), "Checking Account Balance: $0.000000");
 BOOST_CHECK_EQUAL(c.displayAccount("username2"), "Checking Account Balance: $10.000000");
}
BOOST_AUTO_TEST_CASE(deserialize)
{
    AccountManager c;
    std::cout << "MAKE THIS A CHECKING ACCOUNT" << std::endl;
    c.addAccount("username1");
    c.makeDeposit("username1", 10.0);
    std::cout << "MAKE THIS A SAVINGS ACCOUNT w/ .1" << std::endl;
    c.addAccount("username2");
    c.serialize("csvTest.csv");

    AccountManager d;
    d.deserialize("csvTest.csv");
    BOOST_CHECK_EQUAL(c.getNumAccounts(), 2);
    BOOST_CHECK_EQUAL(d.displayAccount("username1"), "Checking Account Balance: $10.000000");
    BOOST_CHECK_EQUAL(d.displayAccount("username2"), "Savings Account Balance: $0.000000, Interest Rate: 0.100000");
    std::cout << "End of deserialize" << std::endl;

}

BOOST_AUTO_TEST_SUITE_END()