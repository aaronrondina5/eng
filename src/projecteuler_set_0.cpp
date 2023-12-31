#include "projecteuler_set_0.h"

#include "math_util.h"

// std
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

namespace arondina
{
namespace eng
{

long long LargestProductInSeries::greedy(const std::string& series, int segment_length) const
{
    /**
     * Similar to largest grid product, cacheing fails us when we hit zeroes.
     * But lets try to cache anyway, and do the back calculation only if we hit a zero.
     * 
     * Time O(n) in the best case O(n x segment_length) in worst case
     * 
     * Space O(1)
    */
    int n = series.size();
    if (n < segment_length || segment_length == 0) {
        return 0;
    }

    long long result = 0;
    long long current_product = 1;

    for(int i = 0; i < n; ++i)
    {
        int value = series[i] - '0';
        current_product *= value;

        if(i > segment_length - 1)
        {
            int excluded_value = series[i - segment_length] - '0';
            if(excluded_value == 0)
            {
                // go back and recomput the values
                current_product = 1;
                for(int j = i - segment_length + 1; j <= i; ++j)
                {
                    current_product *= (series[j] - '0');
                }
            }
            else
            {
                // we need to divide
                current_product /= excluded_value;
            }
        }

        if(i >= segment_length - 1)
        {
            result = std::max(result, current_product);
        }
    }

    return result;
}

long long LatticePaths::dynamic_programming(int m, int n) const
{
    /**
     * So you always will take the same number of steps down and to the right
     * if its a m x n graph, you will take m steps down, and n steps to the right,
     * no matter what path you take.
     * 
     * the question is calling 2x2 grid a graph of 3x3 points.
     * so naive approach, we could just backtrack with all the paths.
     * 
     * A better approach is to use DP to do it.
     * 
     * A possible improvement to this dynamic programming method is 
     * to only use 1 half of the matrix because it is symmetrical across
     * the diagonal.
     *
    */

    if(m == 0 || n == 0)
    {
        return 0;
    }

    std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(n + 1, 0));
    // so you can skip the first row & col and dont have to do a check each time
    for(int row = 0; row <= m; ++row)
    {
        dp[row][0] = 1;
    }
    for(int col = 0; col <= n; ++col)
    {
        dp[0][col] = 1;
    }

    for(int row = 1; row <= m; ++row)
    {
        for(int col = 1; col <= n; ++col)
        {
            dp[row][col] = dp[row][col - 1] + dp[row - 1][col];
        }
    }

    return dp[m][n];
}

long long LatticePaths::combinatorics(int m, int n) const
{
    /**
     * As mentioned above, you will be taking m steps down and
     * n steps to the right, always. 
     * 
     * So we need to figure out the number of combinations to do this.
    */
    throw std::runtime_error("TODO: the combinatorics for this!");
}

int LargestGridProduct::brute_force(const std::vector<std::vector<int>>& grid, int segment_length) const
{
    /**
     * 
     * Initially thought about caching the products, but this breaks down with the 0s, because we lose 
     * the record.
     * 
     * like if we go from a sequence of 0, 1, 2, 3 our cache is at 0. Then
     * we move on to the next and we need to know 1,2,3 * next but we only have 0 in the cache.
     * 
     * Could be an optimization still. And only do the back calculation if you hit a zero.
     * But probably too much for this.
     * 
     * 
     * 
     * Time O(m x n x segment_length)
     * Space O(1)
    */
    if(segment_length == 0)
    {
        return 0;
    }

    int m = grid.size();
    int n = grid[0].size();

    int result = INT_MIN;

    for(int row = 0; row < m; ++row)
    {
        for(int col = 0; col < n; ++col)
        {
            // if horizontal segment long enough, compute and compare
            // We can only compare at this point, because of the possibility of negative values.
            // for example, say a we have segment_length = 4 and our 3 values are a max. Sounds good right?
            // but if the next value is negative, then we really dont have a max.
            if(col >= segment_length - 1)
            {
                int horizontal_product = grid[row][col];
                for(int i = 1; i < segment_length; ++i)
                {
                    horizontal_product *= grid[row][col - i];
                }
                result = std::max(horizontal_product, result);
            }

            // if vertical segment long enough, compute and compare
            if(row >= segment_length - 1)
            {
                int vertical_product = grid[row][col];
                for(int i = 1; i < segment_length; ++i)
                {
                    vertical_product *= grid[row - i][col];
                }
                result = std::max(vertical_product, result);
            }

            // if diagonal segment long enough, compute and compare
            if(row >= segment_length - 1 && col >= segment_length - 1)
            {
                int diagonal_product = grid[row][col];
                for(int i = 1; i < segment_length; ++i)
                {
                    diagonal_product *= grid[row - i][col - i];
                }
                result = std::max(diagonal_product, result);
            }

            // if anti-diagonal segment long enough, compute and compare
            if(row >= segment_length - 1 && n - col >= segment_length)
            {
                int antidiagonal_product = grid[row][col];
                for(int i = 1; i < segment_length; ++i)
                {
                    antidiagonal_product *= grid[row - i][col + i];
                }
                result = std::max(antidiagonal_product, result);
            }
        }
    }

    return result;
}

void PythagoreanTriplet::programmatically(int* result, int sum_equals) const
{
    /**
     * Need to check triplets. First need to get the viable triplets.
     * Could loop through 1 through 1001 and store the squared values
     * in a 1-indexed vector.
     * 
     * Then, you need to compare all candidates in the squared-values vector
     *  to see if there are 2 values in the array that sum to the candidate.
     * 
     * Since it is sorted, you can used a sliding window from 1 to candidate - 1
     * to see if you can add to this value
    */
    std::vector<int> squares(sum_equals, 0);
    for(int i = 1; i < sum_equals + 1; ++i)
    {
        squares[i] = i * i;
    }

    // loop through our possible values for c^2
    for(int i = 3; i < sum_equals + 1; ++i)
    {
        // sliding window on the previous values to see if we get a match
        int start_window = 1;
        int end_window = i - 1;

        while(start_window < end_window)
        {
            if(squares[start_window] + squares[end_window] == squares[i])
            {
                // found a pythagorean triplet
                if(start_window + end_window + i == sum_equals)
                {
                    // found a result
                    result[0] = start_window;
                    result[1] = end_window;
                    result[2] = i;

                    return;
                }

                // continue the search
                start_window++;
                end_window++;
            }
            else
            {
                // decrement the window
                if(squares[start_window] + squares[end_window] > squares[i])
                {
                    // too large
                    end_window--;
                }
                else
                {
                    // too small
                    start_window++;
                }
            }
        }
    }
}

void PythagoreanTriplet::mathematically(int* result, int sum_equals) const
{
    throw std::runtime_error("TODO: look up the euclid paramaterized triplets stuff");
}

int SumSquareDifference::with_loop(int limit_inclusive) const
{
    /**
     * simply do the loop and take the difference
    */
    int sum_squares = 0;
    for(int i = 1; i <= limit_inclusive; ++i)
    {
        sum_squares += (i * i);
    }
    int sum_consecutive = MathUtil::sum_consecutive(1, limit_inclusive);
    return sum_consecutive * sum_consecutive - sum_squares;
}

/**
 * write out (1 + 2 + ...) * (1 + 2 + ...)
 * 
 * it contains all the terms of
 * (1)(1) + (2)(2) + (3)(3). This would still involve looping the first.
 * 
 * lets see if there is a non-loop formula for sum of consecutive squares.
 * 
 * if you write it out, the spaces go up by 2. this is weird, why??
 * 
 * 1 -> 4 -> 9 -> 16 -> 25 -> 36
 *   3    5    7     9     11 
 * 
 * drawing out the sqaures its like you are adding another row&col,
 * but increasing the dimensionality by 1 on each side
 *
 * 
 * seems like there is a pattern here to figure out - unsure of the proof
 * just looked it up. will need to read over this in more detail later.
*/
int SumSquareDifference::using_math(int limit_inclusive) const
{
    return MathUtil::sum_consecutive(1, limit_inclusive) * MathUtil::sum_consecutive(1, limit_inclusive)
        - MathUtil::sum_consecutive_squares(limit_inclusive);
}


int SmallestMultiple::with_factorization_loop(int end) const
{
    /**
     * So you would start at res=1
     * then move to 2, res *= 2
     * then 3, res *= 3
     * then 4, you only need 1 2, because you have a factor of 2 already
     * How to figure this out?
     *  you essentially need to know the prime factorization, and have a running total of number of primes
     * that are needed to build the number
     * so if we keep an array of length 20 for numbers 1 thru 20, then continue to update this as
     * you move along
    */
    int end_value = end;

    // Initialize a value count holder array
    std::vector<int> factor_count_holder(end_value + 1, 0); // +1 for 1-based indexing

    for(int i = 2; i <= end_value; ++i)
    {
        int factor = i;

        // Loop through the prime factors and count how many are needed
        int prime = 2;
        while(factor > 1)
        {
            if(factor % prime == 0)
            {
                // Valid prime factor - count total
                int prime_count = 0;
                while(factor % prime == 0)
                {
                    prime_count++;
                    factor /= prime;
                }

                // Update the value_count_holder for this prime if needed (1 indexed)
                factor_count_holder[prime] = std::max(factor_count_holder[prime], prime_count);
            }
            prime++;
        }
    }

    // Now we have an array of number of each prime value
    // Loop through and multiply
    int res = 1;
    for(size_t factor = 2; factor < factor_count_holder.size(); ++factor)
    {
        if(factor_count_holder[factor] > 0)
        {
            res *= static_cast<int>(std::pow(factor, factor_count_holder[factor]));
        }
    }
    return res;
}

int LargestPalindromicProduct::with_loop() const
{
    /**
     * thought about how to not do the following for a while
     * this seems okay - we aren't duplicating checks by making sure y <= x
     * was thinking of some way of using priority queues to make sure we always
     * get the highest product next, but it would probably be overkill
    */
    int res = -1;
    for(int x = 999; x > 99; --x)
    {
        // Start at x to avoid duplicating checks
        for(int y = x; y > 99; --y)
        {
            if(MathUtil::is_palindromic_number(x * y))
            {
                res = std::max(res, x * y);
            }
        }
    }
    return res;
}

int LargestPrimeFactor::decent(int value) const
{
    /**
     * idea is to start a low prime numbers and move up
     * if you divide prime factor as many times as you can, then you dont have to
     * worry about hitting non-primes later
     * ie, you would never be able to divide by 9 if you had already divided all
     * the 3s out of the number
     * 
     * you don't have to go higher than the sqrt(input) because that cant possibly be a factor
    */

    // initialize to the value in case you cannot get any prime divisions
    int largest = value;
    int current = value;

    for (int x = 2; x <= static_cast<int>(std::sqrt(current)) + 1; ++x)
    {
        while (current % x == 0)
        {
            largest = x;
            current /= x;
        }
    }

    return largest;
}

int LargestPrimeFactor::optimal(int value) const
{
    /**
     * the improvement here was suggested by euler's docs
     * 
     *  makes sense - you can increment twice as fast because you know you have removed all the evens
     * at first
     * so similar to my solution, just with improvement
    */

    int largest = value;
    int current = value;

    if(current % 2 == 0)
    {
        largest = 2;
        while(current % 2 == 0)
        {
            current /= 2;
        }
    }

    for (int x = 3; x <= static_cast<int>(std::sqrt(current)) + 1; x+=2)
    {
        while (current % x == 0)
        {
            largest = x;
            current /= x;
        }
    }

    return largest;
}

int EvenFibonacciSum::dynamic_programming(int max) const
{
    /**
     * Using bottom up dp.
     * Do not do top down recursion for fib; your time will be O(2 ^ n) and space will be O(n) for max depth of recursion stack.
     * 
     * Just check the mod % 2 == 0 and sum?
     * Could also just add every 3rd value (e + o = o, o + o = e) 2, 3, 5, 8, 13, 21, 34
    */

    int result = 0;
    int i = 1;
    int j = 1;

    while(j < max)
    {
        if(j % 2 == 0)
        {
            result += j;
        }
        int temp = j;
        j = i + j;
        i = temp;
    }
    return result;
}

int EvenFibonacciSum::dynamic_programming_fast(int max) const
{
    /**
     * Do the algebra to get the F(n) to be some sum of every 3rd term
     * b/c: e + o = o, o + o = e, so evens are every 3rd term
     * 
     * Say F(3) is an even (2 for example, if F(1) = 1, F(2) = 1)
     * then F(6) is next even, then F(9), etc
     * 
     * F(2) = F(1) + F(0)
     * F(3) = F(1) + F(2)
     * F(4) = F(3) + F(2)
     * F(5) = F(4) + F(3)
     * F(6) = F(5) + F(4)
     * 
     * Back substitute terms into 6
     * F(6) = F(4) + F(3) + F(4)
     * F(6) = F(3) + F(2) + F(3) + F(3) + F(2)
     * F(6) = 3 * F(3) + 2 * F(2)
     * F(6) = 3F(3) + 2 ( F(1) + F(0) )
     * 
     * F(1) in terms of 3, 0
     * F(1) = F(2) - F(0)
     * F(1) = F(3) - F(1) - F(0)
     * 2F(1) = F(3) - F(0)
     * 
     * F(6) = 3F(3) + 2F(1) + 2F(0)
     * F(6) = 3F(3) + F(3) - F(0) + 2F(0)
     * F(6) = 4F(3) + F(0)
     * 
     * OR F(n) = 4F(n-3) + F(n-6) !!!
    */
    int result = 0;
    int f_n_minus_6 = 0;
    int f_n_minus_3 = 2;

    while(f_n_minus_3 < max)
    {
        result += f_n_minus_3;

        int temp = f_n_minus_3;
        f_n_minus_3 = 4 * f_n_minus_3 + f_n_minus_6;
        f_n_minus_6 = temp;
    }

    return result;
}

int MultiplesThreeFive::with_loop(int end_inclusive) const
{
    /**
     * Straightforward loop and mod check
     * Time: O(n) where n is max
     * Size: O(1)
    */
    int result = 0;
    for(int i = 0; i <= end_inclusive; ++i)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            result += i;
        }
    }
    return result;
}

int MultiplesThreeFive::with_math(int end_inclusive) const
{
    /**
     * 3, 6, 9, 12...
     * It is obvious that a next multiple contains 1 more than the preceding.
     * 
     * So then you have a straightforward sequence 1,2,3,4... etc to which you need to find the sum.
     * That sum can be thought of as (1 + n) + (2 + n - 1) + (3 + n - 2) etc (see util.math)
     * 
     * Okay, so then we get the end of the sequence by floor(input / 3) or floor(input / 5)
     * and get the sum using the method above and multiply by the corresponding factor
     * 
     * Then, you must subtract the "duplicate" additions - because there are common multiples
     * at every 15th (LCM) value.
     * 
     * Time O(1)
     * Space O(1)
    */
    return MathUtil::sum_of_multiples_of_factor(3, end_inclusive) + MathUtil::sum_of_multiples_of_factor(5, end_inclusive)
        - MathUtil::sum_of_multiples_of_factor(15, end_inclusive);
}

} // euler
} // arondina