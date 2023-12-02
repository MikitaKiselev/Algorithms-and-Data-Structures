def depth_first_search(graph, start, arr, visited, index):
    stack = [start]

    while stack:
        v = stack.pop()
        if not visited[v]:
            visited[v] = True
            arr[v] = index
            index += 1
            stack.extend(reversed(graph[v]))

    return arr, index


with open('input.txt', 'r') as file:
    n = int(file.readline())
    arr = [-1 for _ in range(n)]
    adj_list = [[] for _ in range(n)]
    for i in range(n):
        arr_temp = [int(elem) for elem in file.readline().split()]
        adj_list[i] = [j for j in range(n) if arr_temp[j] == 1]

index = 1
visited = [False for _ in range(n)]

for i in range(n):
    if not visited[i]:
        arr, index = depth_first_search(adj_list, i, arr, visited, index)

with open('output.txt', 'w') as file2:
    file2.write(' '.join(map(str, arr)))