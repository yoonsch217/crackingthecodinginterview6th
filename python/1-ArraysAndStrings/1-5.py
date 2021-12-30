s1 = input("string 1:\n")
s2 = input("string 2:\n")

def run(s1, s2):
    if (len(s1) - len(s2)) not in [-1, 0, 1]:
        return False
    diff_detected = False
    # if len is the same, only replace is possible
    if len(s1) == len(s2):
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                if diff_detected:
                    return False
                diff_detected = True
        return True
    # the others are possible
    shorter = s1 if len(s1) < len(s2) else s2
    longer = s2 if shorter == s1 else s1
    i_l = 0
    i = 0
    while i < len(shorter):
        if shorter[i] != longer[i_l]:
            if diff_detected:
                return False
            diff_detected = True
            i -= 1
        i_l += 1
        i += 1
    return True

print(run(s1, s2))
        
