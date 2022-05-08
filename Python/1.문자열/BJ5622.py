import sys

A = ord('A')
T = ord('T')
S = ord('S')
Z = ord('Z')

def function(char) :
    n = ord(char)

    if n == S :
        return 8
    if n== Z :
        return 10

    if n >= T :
        return int((n - T) / 3) + 9
    else :
        return int((n - A) / 3) + 3

if __name__ == '__main__' :
    INPUT = list(input())

    print(sum(list(map(function, INPUT))))
