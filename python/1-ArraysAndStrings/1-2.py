s1 = input("string 1:\n")
s2 = input("string 2:\n")

"""
1. sort and compare if identical => n log n
2. Iterate each string and make an array that counts each charater. => n
"""

def iterate_and_make_array(s1, s2):
# assuming the string consists of 128 ASCII charaters
    if len(s1) != len(s2):
        print("False")
        exit(0)
    arr1 = [0] * 128
    arr2 = [0] * 128
    for i in range (len(s1)):
        idx = ord(s1[i])
        arr1[idx] += 1
    for i in range (len(s2)):
        idx = ord(s2[i])
        arr2[idx] += 1
    if arr1 != arr2:
        print("False")
        exit(0)
    print("True")
    exit(0)

iterate_and_make_array(s1, s2)
