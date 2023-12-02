def func_h(x, i, c, m):
    return (((x % m) + c * i) % m)


with open('input.txt', 'r') as file:
    m, c, n = map(int, file.readline().split())
    arr = [-1 for i in range(m)]
    for i in range(n):
        elem = int(file.readline())
        for j in range(m):
            ind = func_h(elem, j, c, m)
            if arr[ind] == elem:
                break
            if arr[ind] != -1:
                continue
            else:
                arr[ind] = elem
                break

with open('output.txt', 'w') as file2:
    file2.write(' '.join(map(str, arr)))