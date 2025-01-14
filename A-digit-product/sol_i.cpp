#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void solve() {
        int l,r,x,y;cin>>l>>r>>x>>y;

        int sc = 0;
        for (int i=l+1;i<=r;i++) {
                int v = i, p = 1;
                do { p *= v%10; } while (v/=10);
                if (x <= p && p <= y) sc++;
        }

        cout << sc << "\n";
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
}
