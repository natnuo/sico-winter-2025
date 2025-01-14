import math

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    # evaluate each index separately, find maximum minimum operations needed
    mxmn = 0

    for i in range(0,n):
        mxmn = max(mxmn, math.ceil((1-a[i])/(i+1)))

    print(mxmn)

if __name__ == "__main__":
    solve()
