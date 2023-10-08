with open('in.txt', 'r') as file:
    x = int(file.readline())
    y = int(file.readline())
    z = int(file.readline())
    arr1 = file.readline().strip()
    arr2 = file.readline().strip()
n, m = len(arr1), len(arr2)

matrix = [[0] * (m + 1) for i in range(n + 1)]

for i in range(n + 1):
    for j in range(m + 1):
        if i == 0:
            matrix[i][j] = j * y
        elif j == 0:
            matrix[i][j] = i * x
        else:
            q = 1 if arr1[i - 1] != arr2[j - 1] else 0
            matrix[i][j] = min(matrix[i - 1][j - 1] + q * z,
                               matrix[i - 1][j] + x,
                               matrix[i][j - 1] + y)

with open('out.txt', 'w') as file:
    file.write(str(matrix[n][m]))