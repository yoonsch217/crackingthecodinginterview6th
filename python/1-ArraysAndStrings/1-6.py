s = input("string 1:\n")

count = 0
prior = ''
output = []
#aabbbcaa
for i in s:
    if count == 0:
        prior = i
        count += 1
    if prior != i:
        output.append(prior)
        output.append(str(count))
        prior = i
        count = 1
    else:
        count += 1

output.append(prior)
output.append(str(count))
output = ''.join(output)

if len(s) <= len(output):
    print(s)
else:
    print(output)
