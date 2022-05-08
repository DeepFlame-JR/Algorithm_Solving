import sys

cro = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]

if __name__ == "__main__" :
    INPUT = list(input())
    N = len(INPUT)

    RESULT = 0
    i = 0
    while(i < N) :
        if(i+2 < N) :
            assemble3 = INPUT[i] + INPUT[i+1] + INPUT[i+2]
            if assemble3 in cro :
                i += 3
                RESULT += 1
                continue
        if(i+1 < N) :
            assemble2 = INPUT[i] + INPUT[i+1]
            if assemble2 in cro :
                i += 2
                RESULT += 1
                continue
        i += 1
        RESULT += 1

    print(RESULT)


