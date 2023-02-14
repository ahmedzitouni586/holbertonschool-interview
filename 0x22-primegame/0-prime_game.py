#!/usr/bin/python3
def isWinner(x, nums):
    def is_prime(num):
        if num < 2:
            return False
        for i in range(2, int(num**(1/2)) + 1):
            if num % i == 0:
                return False
        return True

    def game(n):
        if n < 2:
            return "Ben"
        for i in range(2, int(n**(1/2)) + 1):
            if n % i == 0:
                return "Maria" if game(i) == "Ben" else "Ben"
        return "Maria"

    maria_count = 0
    ben_count = 0
    for n in nums:
        winner = game(n)
        if winner == "Maria":
            maria_count += 1
        elif winner == "Ben":
            ben_count += 1

    if maria_count > ben_count:
        return "Maria"
    elif ben_count > maria_count:
        return "Ben"
    else:
        return None


isWinner = isWinner

print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))
