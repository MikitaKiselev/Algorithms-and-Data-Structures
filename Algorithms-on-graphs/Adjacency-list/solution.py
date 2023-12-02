with open('input.txt', 'r') as file:
    n, m = map(int, file.readline().split())
    matrix = []
    for i in range(n):
        matrix.append([])
    for i in range(m):
        a, b = map(int, file.readline().split())
        matrix[a-1].append(b)
        matrix[b-1].append(a)
with open('output.txt', 'w') as file2:
    for i in range(n):
        file2.write(str(len(matrix[i])) + ' ')
        file2.write(' '.join(map(str, matrix[i])) + '\n')