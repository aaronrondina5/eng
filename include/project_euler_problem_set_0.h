#ifndef INCLUDED_ARONDINA_ENG_PROJECT_EULER_PROBLEM_SET_0
#define INCLUDED_ARONDINA_ENG_PROJECT_EULER_PROBLEM_SET_0


// std
#include <vector>

namespace arondina
{
namespace eng
{

namespace EulerProblemSet0
{

/**
 * https://projecteuler.net/problem=1
*/
int number_multiples_three_or_five_naive(int end_inclusive);
int number_multiples_three_or_five_better(int end_inclusive);

/**
 * https://projecteuler.net/problem=2
*/
int even_fibonacci_sum_decent(int max);
int even_fibonacci_sum_optimal(int max);

/**
 * https://projecteuler.net/problem=3
*/
int largest_prime_factor_decent(int val);
int largest_prime_factor_optimal(int val);

/**
 * https://projecteuler.net/problem=4
*/
int largest_palindromic_product_brute_force();

/**
 * https://projecteuler.net/problem=5
*/
int smallest_multiple_decent(int end);

/**
 * https://projecteuler.net/problem=6
*/
int sum_square_difference_naive(int limit_inclusive);
int sum_square_difference_better(int limit_inclusive);


/**
 * https://projecteuler.net/problem=15
*/
int lattice_paths_dynamic_programming(int m, int n);

}

} // eng
} // arondina

#endif