#ifndef INCLUDED_ARONDINA_ENG_PROJECT_EULER_PROBLEM_SET_0
#define INCLUDED_ARONDINA_ENG_PROJECT_EULER_PROBLEM_SET_0


// std
#include <string>
#include <vector>

namespace arondina
{
namespace eng
{

/**
 * https://projecteuler.net/problem=15
*/
class LatticePaths
{
public:
    long long dynamic_programming(int m, int n) const;
    long long combinatorics(int m, int n) const;
};

/**
 * https://projecteuler.net/problem=12
*/
class HighlyDivisibleTrangular
{
public:
    long long brute_force(int min_divisors) const;
    long long optimal(int min_divisors) const;
};

/**
 * https://projecteuler.net/problem=11
*/
class LargestGridProduct
{
public:
    int brute_force(const std::vector<std::vector<int>>& grid, int segment_length) const;
};

/**
 * https://projecteuler.net/problem=10
*/
class SumPrimes
{
public:
    long sieve_and_sum(long limit) const;
};

/**
 * https://projecteuler.net/problem=9
*/
class PythagoreanTriplet
{
public:
    void programmatically(int* result, int sum_equals) const;
    void mathematically(int* result, int sum_equals) const;
};

/**
 * https://projecteuler.net/problem=8
*/
class LargestProductInSeries
{
public:
    long long greedy(const std::string& series, int segment_length) const;
};

/**
 * https://projecteuler.net/problem=7
*/
class LargePrime
{
public:
    int with_sieve(int n) const;
};

/**
 * https://projecteuler.net/problem=6
*/
class SumSquareDifference
{
public:
    int with_loop(int limit_inclusive) const;
    int using_math(int limit_inclusive) const;
};

/**
 * https://projecteuler.net/problem=5
*/
class SmallestMultiple
{
public:
    int with_factorization_loop(int end) const;
};

/**
 * https://projecteuler.net/problem=4
*/
class LargestPalindromicProduct
{
public:
    int with_loop() const;
};

/**
 * https://projecteuler.net/problem=3
*/
class LargestPrimeFactor
{
public:
    int decent(int val) const;
    int optimal(int val) const;
};

/**
 * https://projecteuler.net/problem=2
*/
class EvenFibonacciSum
{
public:
    int dynamic_programming(int max) const;
    int dynamic_programming_fast(int max) const;
};

/**
 * https://projecteuler.net/problem=1
*/
class MultiplesThreeFive
{
public:
    int with_loop(int end_inclusive) const;
    int with_math(int end_inclusive) const;
};

} // eng
} // arondina

#endif