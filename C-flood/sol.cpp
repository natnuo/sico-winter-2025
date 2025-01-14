#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
 
struct bfsinfo {
        int curr_x, curr_y, origin_x, origin_y, dist;
};
 
void solve() {
        int n,m;cin>>n>>m;
 
        bool g[m][n];
        for (int y=0;y<n;y++) {
                for (int x=0;x<m;x++) {
                        char v;cin>>v;
                        g[x][y] = v == '1';
                }
        }
 
        vector<bfsinfo> vis[m][n];
        queue<bfsinfo> q;
        for (int y=0;y<n;y++) {
                for (int x=0;x<m;x++) {
                        if (g[x][y]) q.push({x, y, x, y, 0});
                }
        }
 
        while (q.size()) {
                auto [curr_x, curr_y, origin_x, origin_y, dist] = q.front(); q.pop();
                if (vis[curr_x][curr_y].size() >= 2) continue;
 
                if (
                        vis[curr_x][curr_y].size() &&
                        vis[curr_x][curr_y][0].origin_x == origin_x &&
                        vis[curr_x][curr_y][0].origin_y == origin_y
                ) continue;
 
                if (
                        vis[curr_x][curr_y].size() == 0 ||
                        vis[curr_x][curr_y][0].origin_x != origin_x ||
                        vis[curr_x][curr_y][0].origin_y != origin_y
                )
                        vis[curr_x][curr_y].push_back({curr_x, curr_y, origin_x, origin_y, dist});
 
                function<void(int, int)> addbfs = [&](int x, int y) {
                        if (0 <= x && x < m && 0 <= y && y < n) {
                                q.push({x, y, origin_x, origin_y, dist+1});
                        }
                };
 
                addbfs(curr_x+1, curr_y);
                addbfs(curr_x-1, curr_y);
                addbfs(curr_x, curr_y+1);
                addbfs(curr_x, curr_y-1);
        }
 
        int max_base_dist = 0;
        for (int y=0;y<n;y++) {
                for (int x=0;x<m;x++) {
                        max_base_dist = max(max_base_dist, vis[x][y][0].dist);
                }
        }
 
        vector<vector<int>> dist_on_removal(m, vector<int>(n, max_base_dist));
        for (int y=0;y<n;y++) {
                for (int x=0;x<m;x++) {
                        if (vis[x][y].size() == 2) {
                                int
                                        first_x = vis[x][y][0].origin_x,
                                        first_y = vis[x][y][0].origin_y,
                                        second_dist = vis[x][y][1].dist;
                                
                                dist_on_removal[first_x][first_y] = max(
                                        dist_on_removal[first_x][first_y],
                                        second_dist
                                );
                        }
                }
        }
 
        int mnrmd = INT_MAX;
        for (int y=0;y<n;y++) {
                for (int x=0;x<m;x++) {
                        if (g[x][y]) {
                                mnrmd = min(mnrmd, dist_on_removal[x][y]);
                        }
                }
        }
 
        cout << mnrmd << "\n";
}
 
int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
}
