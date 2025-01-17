#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

#define int long long int

struct friendship_group {
        vector<int> players;
        int tot_skill;
};

struct state {
        int i,v,w;
        bool operator==(const state &other) const {
                return i==other.i && v==other.v && w==other.w;
        }
        bool operator!=(const state &other) const {
                return !(*this == other);
        }
};

void solve() {
        /**
         * BLOCK: INPUT
         * IN: standard input
         * OUT: player skills
         */
        int n,m,ka,kb;cin>>n>>m>>ka>>kb;
        vector<int> skill(n); for (int i=0;i<n;i++) cin >> skill[i];

        /**
         * BLOCK: SKILL SUMMER
         * IN: player skills
         * OUT: sum of all player skills
         */
        int total_skill = 0; for (int i=0;i<n;i++) total_skill += skill[i];

        /**
         * BLOCK: ADJ. LIST CONSTRUCTOR
         * IN: standard input
         * OUT: adjacency list
         */
        vector<vector<int>> adj(n);
        for (int i=0;i<m;i++) {
                int u,v;cin>>u>>v;u--;v--;  // 0-index
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        /**
         * BLOCK: CC FINDER
         * IN: adj. list, player skills
         * OUT: friendship groups
         */
        vector<friendship_group> fgs;
        vector<bool> vis(n);
        function<void(int)> dfs = [&](int x) {
                if (vis[x]) return;
                vis[x] = true;

                fgs.rbegin()->players.push_back(x);
                fgs.rbegin()->tot_skill += skill[x];

                for (int ch : adj[x]) dfs(ch);
        };
        for (int x=0;x<n;x++) {
                if (!vis[x]) {
                        fgs.push_back({{}, 0});
                        dfs(x);
                }
        }

        /**
         * BLOCK: KNAPSACK DP
         * IN: friendship groups
         * OUT: A knapsack dp array that:
         *      1. shows whether the first i friendship groups can produce
         *              exactly v players and w skill
         *      2. if so, gives the last state where a friendship group was
         *              added to team A to reach the current state
         */
        state DNE = {-10, -10, -10};  // arbitrary negative value
        state ORIGIN = {-1, -1, -1};

        vector<vector<vector<state>>> dp(fgs.size()+1, vector<vector<state>>(n/2+1, vector<state>(ka+1, DNE)));

        dp[0][0][0] = ORIGIN;
        for (int i=1;i<=fgs.size();i++) {
                for (int v=0;v<=n/2;v++) {  // v --> players
                        for (int w=0;w<=ka;w++) {  // w --> skill
                                dp[i][v][w] = dp[i-1][v][w];

                                int nv = v-fgs[i-1].players.size(), nw = w-fgs[i-1].tot_skill;
                                if (
                                        nv >= 0 && nw >= 0 &&
                                        dp[i][v][w] == DNE &&
                                        dp[i-1][nv][nw] != DNE
                                ) dp[i][v][w] = {i-1, nv, nw};
                        }
                }
        }

        /**
         * BLOCK: SOLUTION UNPACKER
         * IN: knapsack dp array
         * OUT: team a players (printed)
         * METHOD: check if team A configs work; track backwards from working solution
         */
        for (int i=1;i<=fgs.size();i++) {
                for (int wa=ka;wa>=1;wa--) {
                        if (dp[i][n/2][wa] != DNE) {
                                int wb = total_skill - wa;

                                if (wb <= kb) {
                                        vector<int> team_a_friendgroups;
                                        
                                        state s = dp[i][n/2][wa];
                                        while (s != ORIGIN) {
                                                team_a_friendgroups.push_back(s.i);
                                                s = dp[s.i][s.v][s.w];
                                        }

                                        vector<bool> player_team_a(n);
                                        for (int fgix : team_a_friendgroups) {
                                                for (int player : fgs[fgix].players) {
                                                        player_team_a[player] = true;
                                                }
                                        }

                                        vector<int> team_a_players, team_b_players;
                                        for (int j=0;j<n;j++) {
                                                if (player_team_a[j]) team_a_players.push_back(j);
                                        }
                                        
                                        for (int j=0;j<n/2;j++)
                                                cout << (team_a_players[j] + 1) << " \n"[j==n/2-1];
                                        
                                        return;
                                }
                        }
                }
        }

        cout << "-1\n";
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
}
