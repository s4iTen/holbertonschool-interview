#!/usr/bin/python3
"""
Prime Game
"""


def isWinner(x, nums):
    """
    Determine the winner of a game of Prime Game.
    """
    def is_prime(n):
        if n <= 1:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    def get_primes(n):
        primes = []
        for i in range(2, n + 1):
            if is_prime(i):
                primes.append(i)
        return primes

    def play_game(n):
        primes = get_primes(n)
        if len(primes) % 2 == 0:
            return "Ben"
        else:
            return "Maria"

    winners = []
    for num in nums:
        winners.append(play_game(num))

    winner_counts = {player: winners.count(player) for player in set(winners)}
    max_wins = max(winner_counts.values())
    winning_players = [player for player, wins in winner_counts.items()
                       if wins == max_wins]

    if len(winning_players) == 1:
        return winning_players[0]
    else:
        return None
