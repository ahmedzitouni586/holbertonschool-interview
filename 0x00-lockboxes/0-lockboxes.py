#!/usr/bin/python3

def canUnlockAll(boxes):
    u = [0]
    n = len(boxes)
    if n == 0:
        return True
    for b in u:
        for key in boxes[b]:
            if key not in u:
                if key < len(boxes):
                    u.append(key)

    if len(u) == len(boxes):
        return True
    return False
    