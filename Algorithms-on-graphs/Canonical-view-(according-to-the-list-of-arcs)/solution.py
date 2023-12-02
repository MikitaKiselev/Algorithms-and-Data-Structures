with open('input.txt', 'r') as file:
    n = int(file.readline())
    arr = [0 for i in range(n)]
    for i in range(n-1):
        a, b = map(int, file.readline().split())
        arr[b-1] = a
with open('output.txt', 'w') as file2:
    file2.write(' '.join(map(str, arr)) + '\n')