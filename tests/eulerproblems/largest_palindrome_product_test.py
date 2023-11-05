import unittest

from app.eulerproblems.largest_palindrome_product import LargestPalindromeProduct


class LargestPalindromeProductTest(unittest.TestCase):

    def test_brute_force(self):
        algo = LargestPalindromeProduct()
        self.assertEqual(906609, algo.brute_force())
