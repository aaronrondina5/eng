#include "project_euler_problem_set_0.h"


// std

// gtest
#include <gtest/gtest.h>


namespace arondina
{
namespace eng
{

TEST(NumberMultiplesThreeOrFiveNaiveTest, EndOnSharedMultiple)
{
    EXPECT_EQ(EulerProblemSet0::number_multiples_three_or_five_naive(15), 60); // 3 + 5 + 6 + 9 + 10 + 12 + 15
}

TEST(NumberMultiplesThreeOrFiveNaiveTest, EndOnMultipleOfThree)
{
    EXPECT_EQ(EulerProblemSet0::number_multiples_three_or_five_naive(9), 23); // 3 + 5 + 6 + 9
}

TEST(NumberMultiplesThreeOrFiveNaiveTest, EndOnNeither)
{
    EXPECT_EQ(EulerProblemSet0::number_multiples_three_or_five_naive(11), 33); // 3 + 5 + 6 + 9 + 10
}

TEST(NumberMultiplesThreeOrFiveNaiveTest, ActualEulerQuestion)
{
    EXPECT_EQ(EulerProblemSet0::number_multiples_three_or_five_naive(999), 233168);
}

TEST(NumberMultiplesThreeOrFiveBetterTest, EndOnSharedMultiple)
{
    EXPECT_EQ(EulerProblemSet0::number_multiples_three_or_five_better(15), 60); // 3 + 5 + 6 + 9 + 10 + 12 + 15
}

TEST(NumberMultiplesThreeOrFiveBetterTest, EndOnMultipleOfThree)
{
    EXPECT_EQ(EulerProblemSet0::number_multiples_three_or_five_better(9), 23); // 3 + 5 + 6 + 9
}

TEST(NumberMultiplesThreeOrFiveBetterTest, EndOnNeither)
{
    EXPECT_EQ(EulerProblemSet0::number_multiples_three_or_five_better(11), 33); // 3 + 5 + 6 + 9 + 10
}

TEST(NumberMultiplesThreeOrFiveBetterTest, ActualEulerQuestion)
{
    EXPECT_EQ(EulerProblemSet0::number_multiples_three_or_five_better(999), 233168);
}

TEST(SumSquaresNaive, exampleFromQuestion)
{
    EXPECT_EQ(2640, EulerProblemSet0::sum_square_difference_naive(10));
}
TEST(PalindromeTest, LargestPalindrome) {
    EXPECT_EQ(906609, EulerProblemSet0::largest_palindromic_product_brute_force());
}

TEST(SmallestMultipleTest, UpTo10) {
    EXPECT_EQ(EulerProblemSet0::smallest_multiple_decent(10), 2520); // Smallest multiple for numbers 1 to 10
}

TEST(SmallestMultipleTest, UpTo11) {
    EXPECT_EQ(EulerProblemSet0::smallest_multiple_decent(11), 27720); // Smallest multiple for numbers 1 to 11
}

TEST(LatticePaths, dynamicProgramming)
{
    EXPECT_EQ(6, EulerProblemSet0::lattice_paths_dynamic_programming(2, 2));
    EXPECT_EQ(20, EulerProblemSet0::lattice_paths_dynamic_programming(3, 3));
    EXPECT_EQ(10, EulerProblemSet0::lattice_paths_dynamic_programming(2, 3));
    EXPECT_EQ(10, EulerProblemSet0::lattice_paths_dynamic_programming(3, 2));
}

} // euler
} // arondina