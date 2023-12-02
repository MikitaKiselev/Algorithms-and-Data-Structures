from collections import deque

file2 = open('output.out', 'w')


def sort_teams(first_t, second_t):
    if len(first_t) >= len(second_t):
        return first_t, second_t
    else:
        return second_t, first_t


def breadth_first_search(graph, start, first_team, second_team):
    queue = deque([start])
    colors[start] = 1

    while queue:
        current_vertex = queue.popleft()
        current_color = colors[current_vertex]

        for neighbor in graph[current_vertex]:
            if colors[neighbor] == 0:
                colors[neighbor] = -current_color
                queue.append(neighbor)
            elif colors[neighbor] == current_color:
                file2.write("NO")
                exit(0)

    for vertex, color in colors.items():
        if color == 1 and not visited[vertex]:
            first_team.append(vertex)
            visited[vertex] = True
        elif color == -1 and not visited[vertex]:
            second_team.append(vertex)
            visited[vertex] = True

    return True, first_team, second_team


with open('input.in', 'r') as file:
    n = int(file.readline())
    adj_list = [[] for _ in range(n)]
    for i in range(n):
        arr_temp = list(map(int, file.readline().split()))
        adj_list[i] = [j for j in range(n) if arr_temp[j] == 0 and i != j]

first_team = []
second_team = []
colors = {vertex: 0 for vertex in range(len(adj_list))}
visited = [False] * n

matrix_team = []
matrix_team_len = []

for i in range(n):
    if colors[i] == 0:
        first_team.clear()
        second_team.clear()
        breadth_first_search(adj_list, i, first_team, second_team)
        matrix_team.append([first_team.copy(), second_team.copy()])
        matrix_team_len.append(abs(len(first_team)- len(second_team)))

max_team_index = matrix_team_len.index(max(matrix_team_len))
final_max_team = matrix_team[max_team_index][0]
final_min_team = matrix_team[max_team_index][1]
for i in range(len(matrix_team)):
    if i == max_team_index:
        continue
    final_max_team, final_min_team = sort_teams(final_max_team, final_min_team)
    max_team, min_team = sort_teams(matrix_team[i][0], matrix_team[i][1])
    final_max_team += min_team
    final_min_team += max_team

final_max_team, final_min_team = sort_teams(final_max_team, final_min_team)

if len(final_min_team) * 2 < len(final_max_team):
    file2.write("NO")
    exit(0)
file2.write("YES\n")
file2.write(' '.join(map(lambda x: str(x + 1), sorted(final_max_team))))