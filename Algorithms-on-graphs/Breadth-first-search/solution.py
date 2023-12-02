def breadth_first_search(graph, first):
    global index
    queue = []
    arr[first] = index
    visited[first] = True
    index += 1
    queue.append(first)
    while queue:
        v = queue.pop(0)

        for u in graph[v]:
            if not visited[u]:
                visited[u] = True
                arr[u] = index
                index += 1
                queue.append(u)
    return arr


with open('input.txt', 'r') as file:
    n = int(file.readline())
    arr = [-1 for i in range(n)]
    adj_list = [0 for i in range(n)]
    for i in range(n):
        arr_temp = [int(elem) for elem in file.readline().split()]
        adj_list[i] = [j for j in range(n) if arr_temp[j] == 1]
index = 1
visited = [False for _ in range(n)]


for i, elem in enumerate(arr):
    if elem == -1:
        first = i
        breadth_first_search(adj_list, first)

with open('output.txt', 'w') as file2:
    file2.write(' '.join(map(str, arr)))