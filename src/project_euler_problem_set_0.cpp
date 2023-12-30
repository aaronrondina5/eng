#include "project_euler_problem_set_0.h"

#include "math_util.h"

// std
#include <cmath>
#include <iostream>
#include <vector>

namespace arondina
{
namespace eng
{

namespace EulerProblemSet0
{

/**
  * Straightforward loop and mod check
  * Time: O(n) where n is max
  * Size: O(1)
*/
int number_multiples_three_or_five_naive(int end_inclusive)
{
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

/**
 * There may be a better way. So really, is there a way to calculate the total number of each multiple of 3 or 5?
 * 
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
int number_multiples_three_or_five_better(int end_inclusive)
{
    return MathUtil::sum_of_multiples_of_factor(3, end_inclusive) + MathUtil::sum_of_multiples_of_factor(5, end_inclusive)
        - MathUtil::sum_of_multiples_of_factor(15, end_inclusive);
}

/**
 * Using bottom up dp.
 * Do not do top down recursion for fib; your time will be O(2 ^ n) and space will be O(n) for max depth of recursion stack.
 * 
 * Just check the mod % 2 == 0 and sum?
 * Could also just add every 3rd value (e + o = o, o + o = e) 2, 3, 5, 8, 13, 21, 34
*/
int even_fibonacci_sum_decent(int max)
{
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
int even_fibonacci_sum_optimal(int max)
{
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

/**
 * idea is to start a low prime numbers and move up
 * if you divide prime factor as many times as you can, then you dont have to
 * worry about hitting non-primes later
 * ie, you would never be able to divide by 9 if you had already divided all
 * the 3s out of the number
 * 
 * you don't have to go higher than the sqrt(input) because that cant possibly be a factor
*/
int largest_prime_factor_decent(int value)
{
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

/**
 * the improvement here was suggested by euler's docs
 * 
 *  makes sense - you can increment twice as fast because you know you have removed all the evens
 * at first
 * so similar to my solution, just with improvement
*/
int largest_prime_factor_optimal(int value)
{
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

/**
 * thought about how to not do the following for a while
 * this seems okay - we aren't duplicating checks by making sure y <= x
 * was thinking of some way of using priority queues to make sure we always
 * get the highest product next, but it would probably be overkill
*/
int largest_palindromic_product_brute_force()
{
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
int smallest_multiple_decent(int end) {
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

/**
 * simply do the loop and take the difference
*/
int sum_square_difference_naive(int limit_inclusive)
{
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
 * seems like there is a pattern here to figure out - unsure of the proof, so just looked 
 * it up => MathUtil::sum_consecutive_squares
*/
int sum_square_difference_better(int limit_inclusive)
{
    return MathUtil::sum_consecutive(1, limit_inclusive) * MathUtil::sum_consecutive(1, limit_inclusive)
        - MathUtil::sum_consecutive_squares(limit_inclusive);
}

/**
 * So you always will take the same number of steps down and to the right
 * if its a m x n graph, you will take m steps down, and n steps to the right,
 * no matter what path you take.
 * 
 * the question is calling 2x2 grid a graph of 3x3 points.
 * so naive approach, we could just backtrack with all the paths.
 * 
 * A better approach is to use DP to do it.
*/
int lattice_paths_dynamic_programming(int m, int n)
{
    if(m == 0 || n == 0)
    {
        return 0;
    }

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
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
            std::cout << "row=" << row << " col=" << col << " paths=" << dp[row][col] << std::endl;
        }
    }

    return dp[m][n];
}

}

} // euler
} // arondina