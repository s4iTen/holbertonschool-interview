#!/usr/bin/python3
"""inimum Operations"""


def minOperations(n):
    if n <= 1:
        return 0

    operations = 0
    divisor = 2
    while n > 1:
        while n % divisor == 0:
            n //= divisor
            operations += divisor
        divisor += 1

    return operations


if __name__ == "__main__":
    n = 4
    print("Min number of operations to reach {} characters: {}".format(
        n, minOperations(n)))

    n = 12
    print("Min number of operations to reach {} characters: {}".format(
        n, minOperations(n)))
