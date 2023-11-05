import math

from app.model.algorithm import Algorithm
from app.util.math import sum_of_multiples_of_factor, is_palindromic_number


class MultiplesThreeFive(Algorithm):
    def __init__(self):
        super().__init__("MultiplesThreeFive")

    def brute_force(self, **kwargs):
        """ Straightforward loop and mod check
        Time: O(n) where n is max
        Size: O(1)
        """
        result = 0
        for x in range(0, kwargs["end_inclusive"] + 1):
            if x % 3 == 0 or x % 5 == 0:
                result += x
        return result

    def optimal(self, **kwargs):
        """
        There may be a better way. So really, is there a way to calculate the total number of
        each multiple of 3 or 5?

        3, 6, 9, 12...
        It is obvious that a next multiple contains 1 more than the preceding.

        So then you have a straightforward sequence 1,2,3,4... etc to which you need to find the sum.

        That sum can be thought of as (1 + n) + (2 + n - 1) + (3 + n - 2) etc (see util.math)

        Okay, so then we get the end of the sequence by floor(input / 3) or floor(input / 5)
        and get the sum using the method above and multiply by the corresponding factor

        Then, you must subtract the "duplicate" additions - because there are common multiples
        at every 15th (LCM) value.

        Time O(1)
        Space O(1)
        """
        return sum_of_multiples_of_factor(3, kwargs["end_inclusive"]) \
            + sum_of_multiples_of_factor(5, kwargs["end_inclusive"]) \
            - sum_of_multiples_of_factor(15, kwargs["end_inclusive"])


class EvenFibonacciSum(Algorithm):
    def __init__(self):
        super().__init__("Even Fibonacci Sum")

    def decent(self, **kwargs):
        """
        Using bottom up dp.
        Do not do top down recursion for fib; your time will be O(2 ^ n) and space will
        be O(n) for max depth of recursion stack.

        Just check the mod % 2 == 0 and sum?
        Could also just add every 3rd value (e + o = o, o + o = e) 2, 3, 5, 8, 13, 21, 34
        """
        result = 0
        i = 1
        j = 1

        while j < kwargs["max"]:
            if j % 2 == 0:
                result += j

            temp = j
            j = i + j
            i = temp

        return result

    def optimal(self, **kwargs):
        """
        Is there a quicker way?

        Do the algebra to get the F(n) to be some sum of every 3rd term
            b/c: e + o = o, o + o = e, so evens are every 3rd term

        Say F(3) is an even (2 for example, if F(1) = 1, F(2) = 1)
        then F(6) is next even, then F(9), etc

        F(2) = F(1) + F(0)
        F(3) = F(1) + F(2)
        F(4) = F(3) + F(2)
        F(5) = F(4) + F(3)
        F(6) = F(5) + F(4)

        Back substitute terms into 6
        F(6) = F(4) + F(3) + F(4)
        F(6) = F(3) + F(2) + F(3) + F(3) + F(2)
        F(6) = 3 * F(3) + 2 * F(2)
        F(6) = 3F(3) + 2 ( F(1) + F(0) )

        F(1) in terms of 3, 0
        F(1) = F(2) - F(0)
        F(1) = F(3) - F(1) - F(0)
        2F(1) = F(3) - F(0)

        F(6) = 3F(3) + 2F(1) + 2F(0)
        F(6) = 3F(3) + F(3) - F(0) + 2F(0)
        F(6) = 4F(3) + F(0)

        OR F(n) = 4F(n-3) + F(n-6) !!!
        """
        result = 0
        f_n_minus_6 = 0
        f_n_minus_3 = 2

        while f_n_minus_3 < kwargs["max"]:
            result += f_n_minus_3

            temp = f_n_minus_3
            f_n_minus_3 = 4 * f_n_minus_3 + f_n_minus_6
            f_n_minus_6 = temp

        return result


class LargestPrimeFactor(Algorithm):
    def __init__(self):
        super().__init__("LargestPrimeFactor")

    def decent(self, **kwargs):
        # initialize to the value in case you cannot get any prime divisions
        largest = kwargs["val"]
        current = kwargs["val"]

        for x in range(2, int(math.sqrt(kwargs["val"])) + 1):
            while current % x == 0:
                # can divide, so do (and reset the largest)
                largest = x
                current /= x
        return largest

    def optimal(self, **kwargs):
        val = kwargs["val"]
        largest = -1

        if val % 2 == 0:
            largest = 2
            while val % 2 == 0:
                val /= 2

        for x in range(3, int(math.sqrt(val)), 2):
            if val % x == 0:
                # we can divide, thus this is the largest prime factor
                largest = x
                while val % x == 0:
                    val /= x

        return largest


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
