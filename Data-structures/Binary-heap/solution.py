def is_heap(arr):
    l = len(arr)
    arr.insert(l, 1000000001)
    for i in range(l // 2):
        if 2 * i + 1 <= len(arr):
            if arr[i] > arr[2 * i + 1] or arr[i] > arr[2 * i + 2]:
                return False
    return True


if __name__ == '__main__':
    inFile = open('input.txt', 'r')
    outFile = open('output.txt', 'w')

    lines = inFile.readlines()
    inFile.close()

    arr = list(map(int, lines[1].split()))

    outFile.write("YES" if is_heap(arr) else "NO")
    outFile.close()