#include<bits/stdc++.h>
#pragma optimize("O3,unroll-loops")
using namespace std;
 
#define int long long int
 
auto solve() {
        int n;cin>>n;
 
        // evaluate each index separately, find maximum minimum operations needed
        int mxmn = 0;
 
        for (int i=1;i<=n;i++) {
                int ai;cin>>ai;ai*=-1;
                mxmn = max(mxmn, ai/i+1);
        }
 
        cout << mxmn << "\n";
}
 
int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
}
