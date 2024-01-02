#include "math_util.h"


// std

// gtest
#include <gtest/gtest.h>


namespace arondina
{
namespace eng
{

TEST(numberDivisors, unit)
{
    EXPECT_EQ(1, MathUtil::get_number_divisors(1));
}

TEST(numberDivisors, prime)
{
    EXPECT_EQ(2, MathUtil::get_number_divisors(7));
}

TEST(numberDivisors, nonPrime)
{
    EXPECT_EQ(4, MathUtil::get_number_divisors(8));
}

TEST(numberDivisors, square)
{
    EXPECT_EQ(5, MathUtil::get_number_divisors(16));
}

TEST(SumConsecutiveTest, PositiveNumbers)
{
    EXPECT_EQ(55, MathUtil::sum_consecutive(1, 10)); // Sum of 1 to 10
}

TEST(SumConsecutiveTest, LowIsZero)
{
    EXPECT_EQ(55, MathUtil::sum_consecutive(0, 10)); // Sum of 0 to 10
}

TEST(SumConsecutiveTest, HighLowerThanLow)
{
    EXPECT_EQ(0, MathUtil::sum_consecutive(10, 1)); // Edge case, might depend on function design
}

TEST(SumConsecutiveTest, NegativeValues)
{
    EXPECT_EQ(-55, MathUtil::sum_consecutive(-10, -1)); // Sum of -10 to -1
}

TEST(SumConsecutiveTest, SameLowAndHigh)
{
    EXPECT_EQ(5, MathUtil::sum_consecutive(5, 5)); // Edge case: low and high are the same
}

TEST(SumConsecutiveTest, LargeValues)
{
    EXPECT_EQ(50005000, MathUtil::sum_consecutive(1, 10000)); // Sum of 1 to 10000, check for overflow
}

TEST(SumOfMultiplesOfFactorTest, CommonFactor)
{
    EXPECT_EQ(18, MathUtil::sum_of_multiples_of_factor(3, 9)); // 3 + 6 + 9
}

TEST(SumOfMultiplesOfFactorTest, NoMultipleInRange)
{
    EXPECT_EQ(0, MathUtil::sum_of_multiples_of_factor(5, 3)); // No multiples of 5 in the range 0-3
}

TEST(SumOfMultiplesOfFactorTest, FactorOne)
{
    EXPECT_EQ(55, MathUtil::sum_of_multiples_of_factor(1, 10)); // Sum of all numbers from 0 to 10
}

TEST(SumOfMultiplesOfFactorTest, EndInclusiveZero)
{
    EXPECT_EQ(MathUtil::sum_of_multiples_of_factor(3, 0), 0); // No multiples of 3 when end is 0
}

TEST(PalindromeTest, IsPalindromicNumber) {
    EXPECT_TRUE(MathUtil::is_palindromic_number(121));
    EXPECT_TRUE(MathUtil::is_palindromic_number(12321));
    EXPECT_FALSE(MathUtil::is_palindromic_number(1234));
    EXPECT_TRUE(MathUtil::is_palindromic_number(5));
    EXPECT_FALSE(MathUtil::is_palindromic_number(-121));
}

} // euler
} // arondina