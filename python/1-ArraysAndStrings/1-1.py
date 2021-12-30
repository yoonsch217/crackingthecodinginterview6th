
s = str(input("input value:\n"))

"""
1. Using set data structure
2. Making array whose size is the number of characters. Reading one by one and if duplicated return False.
"""

def use_set(s):
    char_set = set()
    for i in range(len(s)):
        if s[i] in char_set:
            print("Not unique")
            exit(0)
        char_set.add(s[i])


def without_data_structure(s):
"""
1. Compare each one by one. n square time complexity.
2. Sort and linearly check through it. 
"""
    pass



use_set(s)

print("Unique")
