import unittest

from app.algorithm.largest_prime_factor import LargestPrimeFactor


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