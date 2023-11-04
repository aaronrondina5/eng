import unittest

from app.util.math import sum_consecutive, sum_of_multiples_of_factor


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


if __name__ == "__main__":
    unittest.main()
