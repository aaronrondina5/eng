#include "projecteuler_set_1_20.h"

// std
#include <string>
#include <vector>

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

TEST(HighlyDivisibleTrangular, optimalSmallValues)
{
    HighlyDivisibleTrangular algo;
    EXPECT_EQ(28, algo.optimal(5));
    EXPECT_EQ(36, algo.optimal(6));
    EXPECT_EQ(36, algo.optimal(7));
}

TEST(HighlyDivisibleTrangular, optimalAnswer)
{
    HighlyDivisibleTrangular algo;
    EXPECT_EQ(76576500, algo.optimal(500));
}

TEST(HighlyDivisibleTrangular, bruteForce)
{
    HighlyDivisibleTrangular algo;
    EXPECT_EQ(28, algo.brute_force(5));
    EXPECT_EQ(76576500, algo.brute_force(500));
}

TEST(LargestProductSeries, testValues)
{
    const std::string series = "012340340333";
    LargestProductInSeries algo;
    EXPECT_EQ(27, algo.greedy(series, 3));
}

TEST(LargestGridProduct, bruteForce)
{
    std::vector<std::vector<int>> grid{
        {8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
        {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0},
        {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
        {52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91},
        {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
        {24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
        {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
        {67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
        {24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
        {21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
        {78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
        {16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
        {86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
        {19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
        {4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
        {88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
        {4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
        {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
        {20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
        {1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}};
    LargestGridProduct algo;
    int result = algo.brute_force(grid, 4);
    EXPECT_EQ(70600674, result);
}

TEST(LargestProductSeries, answer)
{
    const std::string series =
        "73167176531330624919225119674426574742355349194934"
        "96983520312774506326239578318016984801869478851843"
        "85861560789112949495459501737958331952853208805511"
        "12540698747158523863050715693290963295227443043557"
        "66896648950445244523161731856403098711121722383113"
        "62229893423380308135336276614282806444486645238749"
        "30358907296290491560440772390713810515859307960866"
        "70172427121883998797908792274921901699720888093776"
        "65727333001053367881220235421809751254540594752243"
        "52584907711670556013604839586446706324415722155397"
        "53697817977846174064955149290862569321978468622482"
        "83972241375657056057490261407972968652414535100474"
        "82166370484403199890008895243450658541227588666881"
        "16427171479924442928230863465674813919123162824586"
        "17866458359124566529476545682848912883142607690042"
        "24219022671055626321111109370544217506941658960408"
        "07198403850962455444362981230987879927244284909188"
        "84580156166097919133875499200524063689912560717606"
        "05886116467109405077541002256983155200055935729725"
        "71636269561882670428252483600823257530420752963450";
    LargestProductInSeries algo;
    EXPECT_EQ(23514624000, algo.greedy(series, 13));
}

TEST(LargePrime, testAnswer)
{
    LargePrime algo;
    EXPECT_EQ(104743, algo.with_sieve(10001));
}

TEST(PythagoreanTriplet, answerTheQuestion)
{
    int answer[3];
    PythagoreanTriplet algo;
    algo.programmatically(answer, 1000);
    EXPECT_EQ(200, answer[0]);
    EXPECT_EQ(375, answer[1]);
    EXPECT_EQ(425, answer[2]);
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
    EXPECT_EQ(23, algo.with_math(9));
}

TEST(NumberMultiplesThreeOrFiveBetterTest, EndOnNeither)
{
    MultiplesThreeFive algo;
    EXPECT_EQ(33, algo.with_math(11));
}

TEST(NumberMultiplesThreeOrFiveBetterTest, ActualEulerQuestion)
{
    MultiplesThreeFive algo;
    EXPECT_EQ(233168, algo.with_math(999));
}

} // euler
} // arondina