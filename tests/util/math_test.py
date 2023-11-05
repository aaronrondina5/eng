import unittest

from app.util.math import sum_consecutive, sum_of_multiples_of_factor, is_palindromic_number, reverse


class MathUtilTest(unittest.TestCase):
    def test_sum_sequence(self):
        self.assertEqual(6, sum_consecutive(1, 3))

        self.assertEqual(2, sum_consecutive(-1, 2))

        self.assertEqual(0, sum_consecutive(0, 0))

        self.assertEqual(1, sum_consecutive(1, 1))

        self.assertEqual(55, sum_consecutive(1, 10))

        self.assertEqual(66, sum_consecutive(1, 11))

        self.assertEqual(68, sum_consecutive(5, 12))

    def test_sum_of_multiples_of_factor(self):
        self.assertEqual(18, sum_of_multiples_of_factor(3, 9))
        self.assertEqual(75, sum_of_multiples_of_factor(5, 27))

    def test_reverse(self):
        self.assertEqual(1234, reverse(4321))
        self.assertEqual(0, reverse(0))
        self.assertEqual(7, reverse(7))
        self.assertEqual(55, reverse(55))

    def test_is_palindromic_number(self):
        self.assertTrue(is_palindromic_number(9009))
        self.assertFalse(is_palindromic_number(90007))
        self.assertTrue(is_palindromic_number(1234321))
        self.assertTrue(is_palindromic_number(12344321))
        self.assertTrue(is_palindromic_number(999999))
        self.assertFalse(is_palindromic_number(1234594321))


if __name__ == "__main__":
    unittest.main()
