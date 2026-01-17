import sys

def condenseWord(word: str) -> str:
    if len(word) < 11:
        return word
    return word[0] + str(len(word) - 2) + word[len(word) - 1]

def main():
    n = int(input())
    for i in range(n):
        word = input()
        print(condenseWord(word))

if __name__ == '__main__':
    sys.exit(main())
