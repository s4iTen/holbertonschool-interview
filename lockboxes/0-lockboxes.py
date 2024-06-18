#!/usr/bin/python3

def canUnlockAll(boxes):
    n = len(boxes)
    unlocked = set()
    keys = set([0])
    
    while keys:
        key = keys.pop()
        if key not in unlocked:
            unlocked.add(key)
            for new_key in boxes[key]:
                if new_key < n:
                    keys.add(new_key)
    
    return len(unlocked) == n