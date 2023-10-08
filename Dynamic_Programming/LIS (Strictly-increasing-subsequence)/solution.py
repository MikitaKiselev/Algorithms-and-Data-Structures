def lower_bound(x, a):
    l = 0
    r = len(a)
    while l < r:
        k = (l + r) // 2
        if x <= a[k]:
            r = k
        else:  # x ≥ a[k]
            l = k + 1
    return l


with open('input.txt', 'r') as file:
    n = int(file.readline())
    arr = [int(elem) for elem in file.readline().split()]
arr2 = [float("Inf") for i in range(n+1)]
arr2[0] = float("-Inf")

for elem in arr:
    arr2[lower_bound(elem, arr2)] = elem

for i in range(n, 0, -1):
    if arr2[i] != float("Inf"):
        answ = i
        break
with open('output.txt', 'w') as file:
    file.write(str(answ))