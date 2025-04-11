n = 7
branches = [0, 1]
length = [0, 1]
for i in range(2, n + 1):
    branches.append(branches[i - 1] + branches[i - 2])
    length.append(length[i - 1] + length[i - 2] + 1)
print(branches[n], length[n])
