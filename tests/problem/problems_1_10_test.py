import unittest

from app.problem.problems_1_10 import (
    MultiplesThreeFiveBruteForce,
    MultiplesThreeFiveOptimal,
    LargestPrimeFactorDecent,
    LargestPrimeFactorOptimal,
    EvenFibonacciSumDecent,
    EvenFibonacciSumOptimal,
    LargestPalindromeProductBruteForce,
    SmallestMultipleDecent
)


class MultiplesThreeFiveTests(unittest.TestCase):
    def test_end_on_shared_multiple(self):
        bf_impl = MultiplesThreeFiveBruteForce()
        opt_impl = MultiplesThreeFiveOptimal()
        self.assertEqual(60, bf_impl.execute(end_inclusive=15))
        self.assertEqual(60, opt_impl.execute(end_inclusive=15))

    def test_end_on_multiple_of_three(self):
        bf_impl = MultiplesThreeFiveBruteForce()
        opt_impl = MultiplesThreeFiveOptimal()
        self.assertEqual(23, bf_impl.execute(end_inclusive=9))
        self.assertEqual(23, opt_impl.execute(end_inclusive=9))

    def test_end_on_neither(self):
        bf_impl = MultiplesThreeFiveBruteForce()
        opt_impl = MultiplesThreeFiveOptimal()
        self.assertEqual(33, bf_impl.execute(end_inclusive=11))
        self.assertEqual(33, opt_impl.execute(end_inclusive=11))

    def test_actual_euler_question(self):
        bf_impl = MultiplesThreeFiveBruteForce()
        opt_impl = MultiplesThreeFiveOptimal()
        self.assertEqual(233168, bf_impl.execute(end_inclusive=999))
        self.assertEqual(233168, opt_impl.execute(end_inclusive=999))


class EvenFibonacciSumTest(unittest.TestCase):
    def test_end_on_non_fib_number(self):
        dec_impl = EvenFibonacciSumDecent()
        opt_impl = EvenFibonacciSumOptimal()
        # 1,2,3,5,8 => 2 + 8 = 10
        self.assertEqual(10, dec_impl.execute(max=10))
        self.assertEqual(10, opt_impl.execute(max=10))

    def test_end_on_even_fib(self):
        dec_impl = EvenFibonacciSumDecent()
        opt_impl = EvenFibonacciSumOptimal()
        # 1,2,3,5,8,13,21,34 => 2 + 8 + 34 = 44
        self.assertEqual(44, dec_impl.execute(max=35))
        self.assertEqual(44, opt_impl.execute(max=35))

    def test_end_on_odd_fib(self):
        dec_impl = EvenFibonacciSumDecent()
        opt_impl = EvenFibonacciSumOptimal()
        # 1,2,3,5,8,13,21,34,55 => 2 + 8 + 34 = 44
        self.assertEqual(44, dec_impl.execute(max=56))
        self.assertEqual(44, opt_impl.execute(max=56))

    def test_actual_euler_question(self):
        dec_impl = EvenFibonacciSumDecent()
        opt_impl = EvenFibonacciSumOptimal()
        self.assertEqual(4613732, dec_impl.execute(max=4000000))
        self.assertEqual(4613732, opt_impl.execute(max=4000000))


class LargestPrimeFactorTest(unittest.TestCase):
    def test_is_prime(self):
        bf_impl = LargestPrimeFactorDecent()
        opt_impl = LargestPrimeFactorOptimal()
        self.assertEqual(17, bf_impl.execute(val=17))
        self.assertEqual(17, opt_impl.execute(val=17))

    def test_even_with_two(self):
        bf_impl = LargestPrimeFactorDecent()
        opt_impl = LargestPrimeFactorOptimal()
        self.assertEqual(2, bf_impl.execute(val=8))
        self.assertEqual(2, bf_impl.execute(val=16))
        self.assertEqual(2, bf_impl.execute(val=32))
        self.assertEqual(2, opt_impl.execute(val=8))
        self.assertEqual(2, opt_impl.execute(val=16))
        self.assertEqual(2, opt_impl.execute(val=32))

    def test_not_prime(self):
        bf_impl = LargestPrimeFactorDecent()
        opt_impl = LargestPrimeFactorOptimal()
        self.assertEqual(29, bf_impl.execute(val=13195))
        self.assertEqual(29, opt_impl.execute(val=13195))

    def test_actual_question(self):
        bf_impl = LargestPrimeFactorDecent()
        opt_impl = LargestPrimeFactorOptimal()
        self.assertEqual(6857, bf_impl.execute(val=600851475143))
        self.assertEqual(6857, opt_impl.execute(val=600851475143))


class LargestPalindromeProductTest(unittest.TestCase):

    def test_brute_force(self):
        algo = LargestPalindromeProductBruteForce()
        self.assertEqual(906609, algo.execute())


class SmallestMultipleTest(unittest.TestCase):

    def test_decent(self):
        dec_impl = SmallestMultipleDecent()
        self.assertEqual(2520, dec_impl.execute(end=10))
        self.assertEqual(27720, dec_impl.execute(end=11))


if __name__ == "__main__":
    unittest.main()
