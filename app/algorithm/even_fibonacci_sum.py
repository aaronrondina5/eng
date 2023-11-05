from app.model.algorithm import Algorithm


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
