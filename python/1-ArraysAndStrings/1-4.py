s = input("input:\n")

def run(s):
    s = s.lower().replace(' ', '')
    s = sorted(s)
    print(s)
    odd_found = False
    prior_char = ''
    for i in s:
        print("current char: %s" % i)
        if prior_char == '':
            print(1)
            prior_char = i
            continue
        if i == prior_char:
            print(2)
            prior_char = ''
            continue
        if odd_found:
            print(3)
            return False
        prior_char = i
        print(4)
        odd_found = True
    if odd_found and prior_char != '':
        return False
    return True

print(run(s))

