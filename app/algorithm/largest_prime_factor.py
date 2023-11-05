import math

from app.model.algorithm import Algorithm


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
