import sys

def closestPower(n: int, p: int) -> int:
    temp = p
    while temp * p <= n:
        temp *= p
    return temp

def removeChild(n: int, k: int) -> int:
    if k * 2 <= n:
        return k * 2
    if k == n:
        return ((n - closestPower(n, 2)) * 2) + 1
    children = [0] * n
    for i in range(n):
        children[i] = i + 1
    pos = 0
    while(len(children) > n - k + 1):
        pos += 1
        pos %= len(children)
        del children[pos]
    return children[1]

def main():
    q = int(input())
    for i in range(q):
        n, k = list(map(int, input().split()))
        print(removeChild(n, k))

if __name__ == '__main__':
    sys.exit(main())
