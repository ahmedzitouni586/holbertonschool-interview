#!/usr/bin/python3
"""
Minoperation file
"""

def minOperations(n):
    result = 0
    x = 2
    while x * x <= n:
        if n % x:
            x += 1
        else:
            n //= x
            result += x
    if n > 1:
        result += n
    return result