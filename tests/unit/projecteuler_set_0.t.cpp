#include "projecteuler_set_0.h"

// std

// gtest
#include <gtest/gtest.h>


namespace arondina
{
namespace eng
{

TEST(LatticePaths, dynamicProgramming)
{
    LatticePaths algo;
    EXPECT_EQ(6, algo.dynamic_programming(2, 2));
    EXPECT_EQ(20, algo.dynamic_programming(3, 3));
    EXPECT_EQ(10, algo.dynamic_programming(2, 3));
    EXPECT_EQ(10, algo.dynamic_programming(3, 2));
}

TEST(LatticePaths, dynamicProgrammingAnswerQuestion)
{
    LatticePaths algo;
    EXPECT_EQ(137846528820, algo.dynamic_programming(20, 20));
}

TEST(SmallestMultipleTest, various) {
    SmallestMultiple algo;
    EXPECT_EQ(2520, algo.with_factorization_loop(10));
    EXPECT_EQ(27720, algo.with_factorization_loop(11));
    EXPECT_EQ(232792560, algo.with_factorization_loop(20));
}

TEST(PalindromeTest, LargestPalindrome) {
    LargestPalindromicProduct algo;
    EXPECT_EQ(906609, algo.with_loop());
}

TEST(SumSquaresNaive, exampleFromQuestion)
{
    SumSquareDifference algo;
    EXPECT_EQ(2640, algo.with_loop(10));
}

TEST(SumSquaresNaive, answerQuestion)
{
    SumSquareDifference algo;
    EXPECT_EQ(25164150, algo.with_loop(100));
}

TEST(NumberMultiplesThreeOrFiveNaiveTest, EndOnSharedMultiple)
{
    MultiplesThreeFive algo;
    EXPECT_EQ(60, algo.with_loop(15));
}

TEST(NumberMultiplesThreeOrFiveNaiveTest, EndOnMultipleOfThree)
{
    MultiplesThreeFive algo;
    EXPECT_EQ(23, algo.with_loop(9));
}

TEST(NumberMultiplesThreeOrFiveNaiveTest, EndOnNeither)
{
    MultiplesThreeFive algo;
    EXPECT_EQ(33, algo.with_loop(11));
}

TEST(NumberMultiplesThreeOrFiveNaiveTest, ActualEulerQuestion)
{
    MultiplesThreeFive algo;
    EXPECT_EQ(233168, algo.with_loop(999));
}

TEST(NumberMultiplesThreeOrFiveBetterTest, EndOnSharedMultiple)
{
    MultiplesThreeFive algo;
    EXPECT_EQ(60, algo.with_math(15));
}

TEST(NumberMultiplesThreeOrFiveBetterTest, EndOnMultipleOfThree)
{
    MultiplesThreeFive algo;
    EXPECT_EQ(algo.with_math(9), 23); // 3 + 5 + 6 + 9
}

TEST(NumberMultiplesThreeOrFiveBetterTest, EndOnNeither)
{
    MultiplesThreeFive algo;
    EXPECT_EQ(algo.with_math(11), 33); // 3 + 5 + 6 + 9 + 10
}

TEST(NumberMultiplesThreeOrFiveBetterTest, ActualEulerQuestion)
{
    MultiplesThreeFive algo;
    EXPECT_EQ(algo.with_math(999), 233168);
}

} // euler
} // arondina