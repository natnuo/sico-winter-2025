#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
 
#define int long long int
#define all(a) a.begin(), a.end()
 
void solve() {
        int n;cin>>n;
        vector<int> x(n), y(n); for (int i=0;i<n;i++) cin >> x[i] >> y[i];
 
        sort(all(x)); sort(all(y));
 
        int med_x = x[n/2], med_y = y[n/2];
 
        function<int(vector<int>&, int)> loss = [](vector<int> &a, int v) {
                int sm = 0;
                for (int ai : a) sm += abs(ai - v);
                return sm;
        };
 
        cout << min(loss(x, med_x), loss(y, med_y)) << "\n";
}
 
int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
}
