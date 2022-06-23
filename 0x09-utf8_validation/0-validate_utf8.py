#!/usr/bin/python3
"""
moduel to check UTF-8
"""

def validUTF8(data):
    """
    """
    successive_10 = 0
    for i in data:
        i = bin(i).replace('0b', '').rjust(8, '0')
        if successive_10 != 0:
            successive_10 -= 1
            if not i.startswith('10'):
                return False
        elif i[0] == '1':
                successive_10 = len(i.split('0')[0]) - 1
    return True
