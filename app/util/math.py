from math import floor


def sum_consecutive(lo, hi):
    """
    Think of the pairs (1 + n) + (2 + n - 1) + (3 + n - 2) etc
    If there are an even number of terms, the number of pairs is n / 2
    If there are an odd number of terms, there are floor(n / 2) pairs, plus 1 final value
    which is the average/median of the terms.

    If you are going to get the average any way, just multiply the average by the number of terms.
    (for odd number of terms + 1)
    """
    return int((float(hi + lo) / 2.0) * (hi - lo + 1))


def sum_of_multiples_of_factor(factor, end):
    return factor * sum_consecutive(0, floor(end / factor))


def reverse(val):
    res = 0
    x = val
    while x > 0:
        res = (res * 10) + (x % 10)  # add the 1s place value
        x = int(x / 10)

    return res


def is_palindromic_number(val):
    return val == reverse(val)

