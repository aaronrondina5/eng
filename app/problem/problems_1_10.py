import math

from app.model.algorithm import Algorithm
from app.util.math import sum_of_multiples_of_factor, is_palindromic_number


class MultiplesThreeFiveBruteForce(Algorithm):
    def execute(self, **kwargs):
        """ Straightforward loop and mod check
        Time: O(n) where n is max
        Size: O(1)
        """
        result = 0
        for x in range(0, kwargs["end_inclusive"] + 1):
            if x % 3 == 0 or x % 5 == 0:
                result += x
        return result


class MultiplesThreeFiveOptimal(Algorithm):
    def execute(self, **kwargs):
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


class EvenFibonacciSumDecent(Algorithm):
    def execute(self, **kwargs):
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


class EvenFibonacciSumOptimal(Algorithm):
    def execute(self, **kwargs):
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


class LargestPrimeFactorDecent(Algorithm):
    def execute(self, **kwargs):
        """
        - idea is to start a low prime numbers and move up
        - if you divide prime factor as many times as you can, then you dont have to
        worry about hitting non-primes later
            - ie, you would never be able to divide by 9 if you had already divided all
            the 3s out of the number
        - you don't have to go higher than the sqrt(input) because that cant possibly be a factor
        """
        # initialize to the value in case you cannot get any prime divisions
        largest = kwargs["val"]
        current = kwargs["val"]

        for x in range(2, int(math.sqrt(kwargs["val"])) + 1):
            while current % x == 0:
                # can divide, so do (and reset the largest)
                largest = x
                current /= x
        return largest


class LargestPrimeFactorOptimal(Algorithm):
    def execute(self, **kwargs):
        """
        - the improvement here was suggested by euler's docs
        - makes sense - you can increment twice as fast because you know you have removed all the evens
        at first
        - so similar to my solution, just with improvement
        """
        val = kwargs["val"]
        largest = kwargs["val"]

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


class LargestPalindromeProductBruteForce(Algorithm):
    def execute(self, **kwargs):
        """
        - thought about how to not do the following for a while
        - this seems okay - we aren't duplicating checks by making sure y <= x
        - was thinking of some way of using priority queues to make sure we always
            get the highest product next, but it would probably be overkill
        """
        res = -1
        for x in range(999, 99, -1):
            for y in range(x, 99, -1):  # by starting at x you aren't duplicating checks
                if is_palindromic_number(x * y):
                    res = max(res, x * y)

        return res


class SmallestMultipleDecent(Algorithm):
    def execute(self, **kwargs):
        """
        So you would start at res=1
        then move to 2, res *= 2
        then 3, res *= 3
        then 4, you only need 1 2, because you have a factor of 2 already
            How to figure this out?
            - you essentially need to know the prime factorization, and have a running total of number of primes
            that are needed to build the number
            - so if we keep an array of length 20 for numbers 1 thru 20, then continue to update this as
            you move along
        """
        end_value = int(kwargs["end"])

        # initialize a value count hold array
        factor_count_holder = [0] * (end_value + 1)  # +1 makes it easier than have 1 indexed

        for i in range(2, end_value + 1):
            # we have a potential factor for our value
            factor = i

            # let's loop through the prime factors and count how many are needed
            prime = 2
            while factor > 1:
                print(f"factor={i} current_value={factor} prime={prime}")

                # technically not a needed check via logic below, but for readability
                if factor % prime == 0:
                    # valid prime factor - count total
                    prime_count = 0
                    while factor % prime == 0:
                        prime_count += 1
                        factor /= prime

                    print(f"factor={i} current_value={factor} prime={prime} prime_count={prime_count}")

                    # update the value_count_holder for this prime if needed (1 indexed)
                    factor_count_holder[prime] = max(factor_count_holder[prime], prime_count)

                prime += 1

        print(factor_count_holder)

        # now we have an array of number of each prime value
        # loop through and multiply
        res = 1
        for factor in range(2, len(factor_count_holder)):
            if factor_count_holder[factor] > 0:

                res = res * (math.pow(factor, factor_count_holder[factor]))
        return res

