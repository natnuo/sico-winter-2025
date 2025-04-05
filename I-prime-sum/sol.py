def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = list(map(int, data[1:n+1]))
    
    MAX_AI = 5000
    freq = [0] * (MAX_AI + 1)
    
    for num in a:
        freq[num] += 1

    sc = 0
    isprime = [True] * (2 * MAX_AI + 1)
    isprime[0] = isprime[1] = False
    
    for i in range(2, 2 * MAX_AI + 1):
        if isprime[i]:
            for j in range(2 * i, 2 * MAX_AI + 1, i):
                isprime[j] = False

            for v in a:
                rem = i - v
                if rem < 0 or rem > MAX_AI:
                    continue
                fac = freq[rem] - (1 if v == rem else 0)
                sc += fac

    print(sc // 2)

if __name__ == "__main__":
    solve()

