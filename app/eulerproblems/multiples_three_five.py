from app.model.algorithm import Algorithm
from app.util.math import sum_of_multiples_of_factor


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

