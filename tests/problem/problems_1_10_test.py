import unittest

from app.problem.problems_1_10 import MultiplesThreeFive, LargestPrimeFactor, EvenFibonacciSum, \
    LargestPalindromeProduct


class MultiplesThreeFiveTests(unittest.TestCase):
    def test_end_on_shared_multiple(self):
        algo = MultiplesThreeFive()
        self.assertEqual(60, algo.brute_force(end_inclusive=15))
        self.assertEqual(60, algo.optimal(end_inclusive=15))

    def test_end_on_multiple_of_three(self):
        algo = MultiplesThreeFive()
        self.assertEqual(23, algo.brute_force(end_inclusive=9))
        self.assertEqual(23, algo.optimal(end_inclusive=9))

    def test_end_on_neither(self):
        algo = MultiplesThreeFive()
        self.assertEqual(33, algo.brute_force(end_inclusive=11))
        self.assertEqual(33, algo.optimal(end_inclusive=11))

    def test_actual_euler_question(self):
        algo = MultiplesThreeFive()
        self.assertEqual(233168, algo.brute_force(end_inclusive=999))
        self.assertEqual(233168, algo.optimal(end_inclusive=999))


class EvenFibonacciSumTest(unittest.TestCase):
    def test_end_on_non_fib_number(self):
        algo = EvenFibonacciSum()

        # 1,2,3,5,8 => 2 + 8 = 10
        self.assertEqual(10, algo.decent(max=10))
        self.assertEqual(10, algo.optimal(max=10))

    def test_end_on_even_fib(self):
        algo = EvenFibonacciSum()
        # 1,2,3,5,8,13,21,34 => 2 + 8 + 34 = 44
        self.assertEqual(44, algo.decent(max=35))
        self.assertEqual(44, algo.optimal(max=35))

    def test_end_on_odd_fib(self):
        algo = EvenFibonacciSum()
        # 1,2,3,5,8,13,21,34,55 => 2 + 8 + 34 = 44
        self.assertEqual(44, algo.decent(max=56))
        self.assertEqual(44, algo.optimal(max=56))

    def test_actual_euler_question(self):
        algo = EvenFibonacciSum()
        self.assertEqual(4613732, algo.decent(max=4000000))
        self.assertEqual(4613732, algo.optimal(max=4000000))


class LargestPrimeFactorTest(unittest.TestCase):
    def test_is_prime(self):
        algo = LargestPrimeFactor()
        self.assertEqual(17, algo.decent(val=17))

    def test_even_with_two(self):
        algo = LargestPrimeFactor()
        self.assertEqual(2, algo.decent(val=8))
        self.assertEqual(2, algo.decent(val=16))
        self.assertEqual(2, algo.decent(val=32))

    def test_not_prime(self):
        algo = LargestPrimeFactor()
        self.assertEqual(29, algo.decent(val=13195))

    def test_actual_question(self):
        algo = LargestPrimeFactor()
        self.assertEqual(6857, algo.decent(val=600851475143))
        self.assertEqual(6857, algo.optimal(val=600851475143))


class LargestPalindromeProductTest(unittest.TestCase):

    def test_brute_force(self):
        algo = LargestPalindromeProduct()
        self.assertEqual(906609, algo.brute_force())


if __name__ == "__main__":
    unittest.main()
