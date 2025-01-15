#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

#define int long long int
#define all(a) a.begin(), a.end()

void solve() {
        int n,k;cin>>n>>k;
        vector<pair<int, int>> a(n); for (int i=0;i<n;i++) { cin >> a[i].first; a[i].second = i; }

        sort(all(a));

        vector<int> ovr(n);
        int ovr_curr = 0;
        int j=n-1;
        for (int i=n-1;i>=0;i--) {
                while (j >= 0 && a[j].first - a[i].first >= k) { j--; ovr_curr++; }
                ovr[a[i].second] = ovr_curr;
        }

        for (int i=0;i<n;i++) {
                cout << ovr[i] << " \n"[i==n-1];
        }
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
}
