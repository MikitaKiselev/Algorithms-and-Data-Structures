def binary_search(x, a):
    l = 0
    r = len(a)
    while l < r:
        k = (l + r) // 2
        if x == a[k]:
            return 1
        elif x < a[k]:
            r = k
        else:  # x > a[k]
            l = k + 1
    return 0


def lower_bound(x, a):
    l = 0
    r = len(a)
    while l < r:
        k = (l + r) // 2
        if x <= a[k]:
            r = k
        else:  # x > a[k]
            l = k + 1

    return l


def upper_bound(x, a):
    l = 0
    r = len(a)
    while l < r:
        k = (l + r) // 2
        if x < a[k]:
            r = k
        else:  # x ≥ a[k]
            l = k + 1
    return l


n = int(input())
arr = [int(elem) for elem in input().split()]
m = int(input())
requests = [int(elem) for elem in input().split()]

for elem in requests:
    answers = []
    answers.append(binary_search(elem, arr))
    answers.append(lower_bound(elem, arr))
    answers.append(upper_bound(elem, arr))
    print(*answers)