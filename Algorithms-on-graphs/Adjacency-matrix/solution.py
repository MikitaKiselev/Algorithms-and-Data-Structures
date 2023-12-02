with open('input.txt', 'r') as file:
    n, m = map(int, file.readline().split())
    matrix = [[0 for i in range(n)] for j in range(n)]
    for i in range(m):
        a, b = map(int, file.readline().split())
        matrix[a-1][b-1] = matrix[b-1][a-1] = 1
with open('output.txt', 'w') as file2:
    for i in range(n):
        file2.write(' '.join(map(str, matrix[i])) + '\n')