#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <string>
#include "BankAccount.hpp"
#include "CheckingAccount.hpp"

BOOST_AUTO_TEST_SUITE(bank_account_suite, * boost::unit_test::timeout(10))
/*
Lines Tested: 4, 5, 6, 7

Also tests getBalance, getFirstName, and getLastName functions
Lines: 16, 17, 20, 21, 24, 25
*/
BOOST_AUTO_TEST_CASE(constructor_test1)
{
    CheckingAccount c("Connor", "Coleman", 15.0);

    BOOST_CHECK_EQUAL(c.getBalance(), 15.0);
    BOOST_CHECK_EQUAL(c.getFirstName(), "Connor");
    BOOST_CHECK_EQUAL(c.getLastName(), "Coleman");
}
/*
Lines Tested: 10, 11, 12, 13
*/
BOOST_AUTO_TEST_CASE(constructor_test2)
{
    CheckingAccount c("Connor", "Coleman");
    BOOST_CHECK_EQUAL(c.getBalance(), 0.0);
    BOOST_CHECK_EQUAL(c.getFirstName(), "Connor");
    BOOST_CHECK_EQUAL(c.getLastName(), "Coleman");

}
/*
Lines Tested: 28, 29, 32, 33
*/
BOOST_AUTO_TEST_CASE(setName)
{
    CheckingAccount c("Connor", "Coleman");
    c.setFirstName("Dave");
    c.setLastName("Cole");
    BOOST_CHECK_EQUAL(c.getFirstName(), "Dave");
    BOOST_CHECK_EQUAL(c.getLastName(), "Cole");
}

/*
Lines tested: 36, 37, 38, 39, 40, 42, 43, 44, 47, 48, 49
Branches tested: 37T, 37F, 38T, 38F
*/
BOOST_AUTO_TEST_CASE(withdrawal)
{
    CheckingAccount c("Connor", "Coleman");
    BOOST_CHECK_EQUAL(c.withdrawal(15.0), false);
    BOOST_CHECK_EQUAL(c.withdrawal(-15.0), false);
    c.deposit(15.0);
    BOOST_CHECK_EQUAL(c.withdrawal(5.0), true);
    BOOST_CHECK_EQUAL(c.getBalance(), 10.0);
}

/*
Lines tested: 53, 54, 55, 56, 58, 59, 60
Branches tested: 54T, 54F
*/
BOOST_AUTO_TEST_CASE(deposit)
{
    CheckingAccount c("Connor", "Coleman");
    BOOST_CHECK_EQUAL(c.deposit(-15.0), false);
    BOOST_CHECK_EQUAL(c.deposit(15.0), true);
    BOOST_CHECK_EQUAL(c.getBalance(), 15.0);
}

BOOST_AUTO_TEST_SUITE_END()