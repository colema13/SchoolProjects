#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "CheckingAccount.hpp"
#include <list>

BOOST_AUTO_TEST_SUITE(checking_account_suite, * boost::unit_test::timeout(10))
/*
Lines tested: 3, 4, 6, 7, 8, 11
Branches tested: 6T, 6F
*/
BOOST_AUTO_TEST_CASE(writecheck)
{
    CheckingAccount c("Connor", "Coleman");
    CheckingAccount d("Someone", "Else");

    BOOST_CHECK_EQUAL(c.writeCheck(d, 15.0), false);

    c.deposit(15.0);
    c.writeCheck(d, 10.0);
    BOOST_CHECK_EQUAL(c.getBalance(), 5.0);
    BOOST_CHECK_EQUAL(d.getBalance(), 10.0);
}
/*
Lines tested: 14, 15
*/
BOOST_AUTO_TEST_CASE(toString)
{
    CheckingAccount c("Connor", "Coleman");
    c.deposit(15.0);
    BOOST_CHECK_EQUAL(c.toString(), "Checking Account Balance: $15.000000");
}
/*
Lines Tested: 18, 19
*/
BOOST_AUTO_TEST_CASE(getCheckLog)
{
    CheckingAccount c("Connor", "Coleman", 15.0);
    CheckingAccount d("Someone", "Else");
    std::list<double> compare;
    compare.push_back(5.0);
    compare.push_back(10.0);


    c.writeCheck(d, 5.0);
    c.writeCheck(d, 10.0);
    c.writeCheck(d, 5.0);

    auto e = c.getCheckLog();

    BOOST_CHECK_EQUAL(compare.size(), e.size());

    auto it1 = e.begin();
    auto it2 = compare.begin();

    while (it1 != e.end()) 
    {
        BOOST_CHECK_EQUAL(*it1, *it2);
        ++it1;
        ++it2;
    }
    

}
BOOST_AUTO_TEST_SUITE_END()