import unittest

from app.algorithm.multiples_three_five import MultiplesThreeFive


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


if __name__ == "__main__":
    unittest.main()
