with open('input.txt', 'r') as file:
    n = int(file.readline())
    arr = [0 for i in range(n)]
    for i in range(n):
        arr2 = [int(elem) for elem in file.readline().split()]
        for j in range(n):
            if arr2[j] == 1:
                arr[j] = i + 1
with open('output.txt', 'w') as file2:
    file2.write(' '.join(map(str, arr)))