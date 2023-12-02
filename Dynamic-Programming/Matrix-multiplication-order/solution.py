def matrix_chain_multiplication_order(dim):
    n = len(dim)
    matrix = [[0 for i in range(n)] for j in range(n)]
    for L in range(2, n):
        for i in range(1, n-L+1):
            j = i+L-1
            matrix[i][j] = float('Inf')
            for k in range(i, j):
                cost = matrix[i][k] + matrix[k+1][j] + dim[i-1] * dim[k] * dim[j]
                if cost < matrix[i][j]:
                    matrix[i][j] = cost
    return matrix[1][n-1]


arr =[]
with open('input.txt', 'r') as file:
    n = int(file.readline())
    for i in range(n):
        line = file.readline()
        elements = [int(elem) for elem in line.split()]
        arr.append(elements[0])
        if i == n-1:
            arr.append(elements[1])

with open('output.txt', 'w') as file:
    file.write(str(matrix_chain_multiplication_order(arr)))