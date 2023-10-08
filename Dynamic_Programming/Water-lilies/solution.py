n = int(input())
arr = [int(elem) for elem in input().split()]
if n == 1:
    print(arr[0])
    print(1)
    exit()
if n < 3:
    print(-1)
    exit()
answer = [0 for i in range(n)]
way = [1, n]
answer[0] = arr[0]
answer[1] = -99999999999999
answer[2] = arr[0] + arr[2]
for i in range(3, n):
    answer[i] = max(answer[i-3], answer[i-2]) + arr[i]
i = n-1
while i > 3:
    if max(answer[i-3], answer[i-2]) == answer[i-3]:
        way.append(i-2)
        i -= 3
    else:
        way.append(i-1)
        i -= 2
print(answer[n-1])
print(*sorted(way))