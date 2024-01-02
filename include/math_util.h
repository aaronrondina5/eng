#ifndef INCLUDED_ARONDINAENG_MATH_UTIL
#define INCLUDED_ARONDINAENG_MATH_UTIL


// std

namespace arondina
{
namespace eng
{

namespace MathUtil
{

int sum_consecutive(int lo, int hi_inclusive);

int sum_consecutive_squares(int n);

int sum_of_multiples_of_factor(int factor, int end_inclusive);

int reverse(int value);

bool is_palindromic_number(int value);

int get_number_divisors(int value);

}

} // eng
} // arondina

#endif