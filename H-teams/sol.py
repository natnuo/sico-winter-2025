# ai translated from cpp

import sys
from collections import defaultdict
 
def solve():
    n, m, ka, kb = map(int, sys.stdin.readline().split())
    skill = list(map(int, sys.stdin.readline().split()))
 
    total_skill = sum(skill)
 
    adj = defaultdict(list)
    for _ in range(m):
        u, v = map(int, sys.stdin.readline().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)
 
    fgs = []
    vis = [False] * n
 
    def dfs(x):
        if vis[x]:
            return
        vis[x] = True
 
        fgs[-1]['players'].append(x)
        fgs[-1]['tot_skill'] += skill[x]
 
        for ch in adj[x]:
            dfs(ch)
 
    for x in range(n):
        if not vis[x]:
            fgs.append({'players': [], 'tot_skill': 0})
            dfs(x)
 
    DNE = (-10, -10, -10)
    ORIGIN = (-1, -1, -1)
 
    dp = [[[DNE for _ in range(ka + 1)] for _ in range(n // 2 + 1)] for _ in range(len(fgs) + 1)]
    dp[0][0][0] = ORIGIN
 
    for i in range(1, len(fgs) + 1):
        for v in range(n // 2 + 1):
            for w in range(ka + 1):
                dp[i][v][w] = dp[i - 1][v][w]
 
                nv = v - len(fgs[i - 1]['players'])
                nw = w - fgs[i - 1]['tot_skill']
                if nv >= 0 and nw >= 0 and dp[i][v][w] == DNE and dp[i - 1][nv][nw] != DNE:
                    dp[i][v][w] = (i - 1, nv, nw)
 
    for i in range(len(fgs) + 1):
        for wa in range(ka + 1):
            if dp[i][n // 2][wa] != DNE:
                wb = total_skill - wa
 
                if wb <= kb:
                    team_a_friendgroups = []
 
                    s = dp[i][n // 2][wa]
                    while s != ORIGIN:
                        team_a_friendgroups.append(s[0])
                        s = dp[s[0]][s[1]][s[2]]
 
                    player_team_a = [False] * n
                    for fgix in team_a_friendgroups:
                        for player in fgs[fgix]['players']:
                            player_team_a[player] = True
 
                    team_a_players = []
                    for j in range(n):
                        if player_team_a[j]:
                            team_a_players.append(j)
 
                    for j in range(n // 2):
                        print(team_a_players[j] + 1, end=" \n"[j == n // 2 - 1])
 
                    return
 
    print("-1")
 
if __name__ == "__main__":
    solve()
