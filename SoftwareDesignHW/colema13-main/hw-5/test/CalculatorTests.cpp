#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "Calculator.hpp"

BOOST_AUTO_TEST_SUITE(calculator_suite)
/*
Lines covered - 67(1/1)
*/
BOOST_AUTO_TEST_CASE(constructor_test)
{
    Calculator c;

    BOOST_CHECK_EQUAL(c.getState(), 0.0);
}
/*
Lines Covered - 5, 7(2/2)
*/
BOOST_AUTO_TEST_CASE(add_test)
{
    Calculator c;
    c.add(3.0);
    BOOST_CHECK_EQUAL(c.getState(), 3.0);
}
/*
Lines Covered - 11, 13(2/2)
*/
BOOST_AUTO_TEST_CASE(sub_test)
{
    Calculator c;
    c.subtract(3.0);
    BOOST_CHECK_EQUAL(c.getState(), -3.0);
}
/*
Lines Covered - 17, 19(2/2)
*/
BOOST_AUTO_TEST_CASE(mult_test)
{
    Calculator c;
    c.add(3.0);
    c.multiply(3.0);
    BOOST_CHECK_EQUAL(c.getState(), 9.0);
}
/*
Lines Covered - 23, 24, 27(3/3)
Branches Covered - 23T, 23F(2/2)
*/
BOOST_AUTO_TEST_CASE(abs_test)
{
    Calculator c;
    c.subtract(3.0);
    c.abs();
    BOOST_CHECK_EQUAL(c.getState(), 3.0);
    c.abs();
    BOOST_CHECK_EQUAL(c.getState(), 3.0);

}
/*
Lines Covered - 31, 32, 34, 35, 38(5/5)
Branches Covered - 31T, 34F(2/2)
*/
BOOST_AUTO_TEST_CASE(div_test)
{
    Calculator c;
    BOOST_CHECK_THROW(c.divide(0), std::invalid_argument);
    c.add(3.0);
    c.divide(3.0);
    BOOST_CHECK_EQUAL(c.getState(), 1.0);
}
/*
Lines Covered - 42, 43, 45, 46, 47, 49, 50, 52, 54, 55, 56, 58, 60, 62(14/14)
Branches Covered - 42T, 42F, 55T, 55F(4/4)
*/
BOOST_AUTO_TEST_CASE(sqrt_test)
{
    Calculator c;
    c.add(9.0);
    c.sqrt();
    BOOST_CHECK_CLOSE(c.getState(), 3.0, 1);
    c.subtract(6.0);
    BOOST_CHECK_THROW(c.sqrt(), std::invalid_argument);
    c.clear();
    c.add(0.25);
    c.sqrt();
    BOOST_CHECK_CLOSE(c.getState(), 0.5, 1);

}
/*
Lines Covered - 72
*/
BOOST_AUTO_TEST_CASE(clear)
{
    Calculator c;
    c.add(9.0);
    c.clear();
    BOOST_CHECK_EQUAL(c.getState(), 0.0);

}
/*
Lines Covered - 77, 78, 80, 81, 84, 85, 86, 89, 90, 92, 93, 94, 96, 98(14/14)
Branches Covered - 77T, 77F, 80T, 80F, 84T, 84F(6/6)
*/
BOOST_AUTO_TEST_CASE(factorial)
{
    Calculator c;
    c.subtract(4.0);
    BOOST_CHECK_THROW(c.factorial(), std::invalid_argument);

    c.clear();
    c.add(4.5);
    BOOST_CHECK_THROW(c.factorial(), std::invalid_argument);

    c.clear();
    c.add(4.0);
    c.factorial();
    BOOST_CHECK_EQUAL(c.getState(), 24.0);

    c.clear();
    c.factorial();
    BOOST_CHECK_EQUAL(c.getState(), 1.0);

    
    

    
}

BOOST_AUTO_TEST_SUITE_END()