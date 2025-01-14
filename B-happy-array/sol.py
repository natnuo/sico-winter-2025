def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    # evaluate each index separately
    # find maximum minimum operations needed
    mxmn = 0
 
    for i in range(1, n+1):
        mxmn = max(mxmn, (a[i-1] * (-1)) // i + 1)
 
    print(mxmn)
 
if __name__ == "__main__":
    solve()
