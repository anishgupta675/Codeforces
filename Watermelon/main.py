import sys

def canDivide(w: int) -> bool:
    if w == 2:
        return False
    return not w % 2

def main():
    w = int(input())
    print('YES' if canDivide(w) else 'NO')

if __name__ == '__main__':
    sys.exit(main())
