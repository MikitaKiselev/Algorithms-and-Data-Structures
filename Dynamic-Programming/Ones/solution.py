n, k = map(int, input().split())
mod = 1000000007


def factorial(x):
    result = 1
    for i in range(1, x + 1):
        result = (result * i) % mod
    return result


numerator = factorial(n)
denominator = (factorial(k) * factorial(n - k)) % mod

result = (numerator * pow(denominator, -1, mod)) % mod

print(result)