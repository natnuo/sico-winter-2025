#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

#define all(a) a.begin(), a.end()

class DSU {
        vector<int> link, size;
public:
        DSU(int n) {
                link.assign(n, 0);
                for (int i=0;i<n;i++) link[i] = i;

                size.assign(n, 1);
        }

        void unite(int a, int b) {
                a = find(a), b = find(b);
                if (same(a, b)) return;
                if (size[a] < size[b]) swap(a, b);
                size[a] += size[b];
                link[b] = a;
        }

        int find(int x) {
                if (link[x] == x) return x;
                link[x] = find(link[x]);
                return link[x];
        }

        bool same(int a, int b) {
                return find(a) == find(b);
        }

        int csize(int x) {
                return size[find(x)];
        }
};

struct query {
        int t,i;
};

void solve() {
        int n,m;cin>>n>>m;
        vector<set<int>> adj(n);
        vector<pair<int, int>> edges(m);
        for (int i=0;i<m;i++) {
                int u,v;cin>>u>>v;u--;v--;  // 0-index
                adj[u].insert(v);
                adj[v].insert(u);
                edges[i] = {u, v};
        }

        int q;cin>>q;

        vector<query> queries(q);
        for (int i=0;i<q;i++) {
                int t,i_;cin>>t>>i_;i_--;  // 0-index
                queries[i] = {t, i_};
        }

        for (int i=0;i<q;i++) {
                auto [t, i_] = queries[i];
                if (t == 1) {
                        auto [u, v] = edges[i_];
                        adj[u].erase(v);
                        adj[v].erase(u);
                }
        }

        DSU dsu(n);
        for (int u=0;u<n;u++) {
                for (int v : adj[u]) {
                        dsu.unite(u, v);
                }
        }

        reverse(all(queries));

        vector<int> ans;

        for (int i=0;i<q;i++) {
                auto [t, i_] = queries[i];
                if (t == 1) {
                        auto [u, v] = edges[i_];
                        dsu.unite(u, v);
                        // note: you could also update adj here, but there is no need
                } else {
                        ans.push_back(dsu.csize(i_));
                }
        }

        reverse(all(ans));

        for (int i=0;i<ans.size();i++) {
                cout << ans[i] << "\n";
        }
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
}
