#!/usr/bin/python3

def isWinner(x, nums):
    def is_prime(n):
        if n <= 1:
            return False
        for i in range(2, int(n**(0.5)) + 1):
            if n % i == 0:
                return False
        return True

    def game(n):
        if n <= 1:
            return "Ben"
        for i in range(2, n + 1):
            if is_prime(i):
                if game(n - i) == "Maria":
                    return "Ben"
        return "Maria"

    maria_wins = 0
    ben_wins = 0
    for n in nums:
        if game(n) == "Maria":
            maria_wins += 1
        else:
            ben_wins += 1
    if ben_wins > maria_wins:
        return "Ben"
    elif maria_wins > ben_wins:
        return "Maria"
    else:
        return None

print("Winner: {}".format(isWinner(3, [4, 5, 1])))
