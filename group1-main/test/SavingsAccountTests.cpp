#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "SavingsAccount.hpp"

BOOST_AUTO_TEST_SUITE(savings_account_suite, * boost::unit_test::timeout(10))
/*
Lines Tested: 3, 4
*/
BOOST_AUTO_TEST_CASE(constructor1)
{
    SavingsAccount c("Connor", "Coleman", 15.0, 0.2);
    BOOST_CHECK_EQUAL(c.getBalance(), 15.0);
    BOOST_CHECK_EQUAL(c.getInterestRate(), 0.2);
    BOOST_CHECK_EQUAL(c.getFirstName(), "Connor");
    BOOST_CHECK_EQUAL(c.getLastName(), "Coleman");
}
/*
Lines Tested: 7, 8
*/
BOOST_AUTO_TEST_CASE(constructor2)
{
    SavingsAccount c("Connor", "Coleman", 0.2);
    BOOST_CHECK_EQUAL(c.getBalance(), 0.0);
    BOOST_CHECK_EQUAL(c.getInterestRate(), 0.2);
    BOOST_CHECK_EQUAL(c.getFirstName(), "Connor");
    BOOST_CHECK_EQUAL(c.getLastName(), "Coleman");
}
/*
Lines Tested: 11, 12 ,13
*/
BOOST_AUTO_TEST_CASE(accrueInterest)
{
    SavingsAccount c("Connor", "Coleman", 15.0, 0.2);
    c.accrueInterest();
    BOOST_CHECK_EQUAL(c.getBalance(), 18.0);
}
/*
Lines Tested: 16, 17
*/
BOOST_AUTO_TEST_CASE(toString)
{
    SavingsAccount c("Connor", "Coleman", 15.0, 0.2);
    BOOST_CHECK_EQUAL(c.toString(), "Savings Account Balance: $15.000000, Interest Rate: 0.200000");
    
}
/* 
Lines Tested: 20, 21
*/
BOOST_AUTO_TEST_CASE(setInterestRate)
{
    SavingsAccount c("Connor", "Coleman", 15.0, 0.2);
    c.setInterestRate(0.5);
    BOOST_CHECK_EQUAL(c.getInterestRate(), 0.5);
}
BOOST_AUTO_TEST_SUITE_END()