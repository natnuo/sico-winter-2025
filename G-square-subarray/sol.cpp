#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
 
#define int long long int
 
void solve() {
        int n;cin>>n;
        vector<int> a(n); for (int i=0;i<n;i++) cin >> a[i];
 
        vector<int> ps(n+1);
        for (int i=1;i<=n;i++) ps[i] = ps[i-1] + a[i-1];
 
        int sm = 0;
        for (int l=0;l<n;l++) {
                int r,i=1;  // subarray is [l, r)
                while (true) {
                        r = l+i*i;
                        if (r > n) break;
                        sm += ps[r] - ps[l];
                        i++;
                }
        }
 
        cout << sm << "\n";
}
 
int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
}
