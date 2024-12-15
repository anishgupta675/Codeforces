import sys
import math

p = pow(10, 9) + 7

def getPower(a: int, b: int) -> int:
    global p
    res = 1
    a = a % p
    if not a:
        return 0
    while b > 0:
        if (b & 1) == 1:
            res = (res * a) % p
        b >>= 1
        a = (a * a) % p
    return res

def main():
    n = int(input())
    for i in range(n):
        a, b = list(map(int, input().split()))
        print(math.trunc(getPower(a, b)))

if __name__ == '__main__':
    sys.exit(main())
