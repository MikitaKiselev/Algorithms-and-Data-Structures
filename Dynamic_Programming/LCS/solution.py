n = int(input())
arr1 = [int(elem) for elem in input().split()]
arr2 = [int(elem) for elem in input().split()]

matrix = [[0 for i in range(n+1)] for j in range(n+1)]
for i in range(n):
    for j in range(n):
        if arr1[i] == arr2[j]:
            matrix[i+1][j+1] = matrix[i][j] + 1
        else:
            matrix[i+1][j+1] = max(matrix[i][j+1], matrix[i+1][j])
print(matrix[n][n])

answer = []
answer2 = []

i, j = n, n

while matrix[i][j] != 0:
    if arr1[i-1] == arr2[j-1]:
        answer.append(i-1)
        answer2.append(j-1)
        i -= 1
        j -= 1
    else:
        if matrix[i-1][j] == matrix[i][j]:
            i -= 1
        else:
            j -= 1

print(*answer[::-1])
print(*answer2[::-1])