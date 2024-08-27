#!/usr/bin/python3
"""
Change
"""


def makeChange(coins, total):
    """
    makeChange
    """
    if total <= 0:
        return 0

    d = [float('inf')] * (total + 1)
    d[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            d[amount] = min(d[amount], d[amount - coin] + 1)

    return d[total] if d[total] != float('inf') else -1
