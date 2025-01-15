#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

#define int long long int
#define all(a) a.begin(), a.end()

void solve() {
        int n,k;cin>>n>>k;
        vector<pair<int, int>> a(n); for (int i=0;i<n;i++) { cin >> a[i].first; a[i].second = i; }

        sort(all(a));

        vector<int> sol(n);
        for (int i=0;i<n-1;i++) {
                sol[a[i].second] = a.end() - lower_bound(all(a), (pair<int, int>){a[i].first + k, LLONG_MIN});
        }

        for (int i=0;i<n;i++) {
                cout << sol[i] << " \n"[i==n-1];
        }
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
}
