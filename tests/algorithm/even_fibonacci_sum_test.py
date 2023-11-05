import unittest

from app.algorithm.even_fibonacci_sum import EvenFibonacciSum


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


if __name__ == "__main__":
    unittest.main()
