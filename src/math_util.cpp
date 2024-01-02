#include "math_util.h"


// std
#include <iostream>
#include <cmath>
#include <vector>

namespace arondina
{
namespace eng
{

namespace MathUtil
{

int sum_consecutive(int lo, int hi_inclusive)
{
    if(lo > hi_inclusive)
    {
        return 0;
    }
    return static_cast<int>((static_cast<double>(hi_inclusive + lo) / 2.0) * (hi_inclusive - lo + 1));
}

int sum_consecutive_squares(int n)
{
    return n * (n + 1) * (2 * n + 1) / 6;
}

int sum_of_multiples_of_factor(int factor, int end_inclusive) {
    return factor * sum_consecutive(0, end_inclusive / factor);
}

int reverse(int val) {
    int res = 0;
    int x = val;
    while (x > 0) {
        res = (res * 10) + (x % 10);
        x /= 10;
    }
    return res;
}

bool is_palindromic_number(int val) {
    if(val < 0)
    {
        return false;
    }
    return val == reverse(val);
}

int get_number_divisors(int value)
{
    int square_root = static_cast<int>(std::sqrt(value));
    int number_divisors = 0;

    for(int i = 1; i <= square_root; ++i)
    {
        if(value % i == 0)
        {
            number_divisors+=2;
        }
    };

    // if it was a perfect square, you need to subtract one of the divisors
    if(square_root * square_root == value)
    {
        --number_divisors;
    }

    return number_divisors;
}

}

} // euler
} // arondina