from app.model.algorithm import Algorithm
from app.util.math import is_palindromic_number


class LargestPalindromeProduct(Algorithm):
    def __init__(self):
        super().__init__("LargetsPalindromeProduct")

    def brute_force(self, **kwargs):
        res = -1
        for x in range(999, 99, -1):
            for y in range(999, 99, -1):
                if y <= x:  # prevent duplicate calculations
                    if is_palindromic_number(x * y):
                        res = max(res, x * y)
        return res
