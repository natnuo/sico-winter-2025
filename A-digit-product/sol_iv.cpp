#include <bits/stdc++.h>
using namespace std;

#define int long long int

int dp[72][100002][2];

auto solve() {
        string l,r;cin>>l>>r;
        int x,y;cin>>x>>y;

        // solves the problem for S values in [0, v]
        function<int(string, int)> cnt = [&](string v, int h) {
                if (v == "0") return 0ll;

                int n = v.size();

                // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(h+1, vector<int>(2)));

                for (int i=0;i<n+1;i++) {
                        for (int j=0;j<h+1;j++) {
                                for (int l=0;l<2;l++) {
                                        dp[i][j][l] = 0;
                                }
                        }
                }

                int d = v[n-1]-'0';
                for (int hi=1;hi<=min(h, 9ll);hi++) {
                        dp[1][hi][0] = 1;
                        if (hi<=d) dp[1][hi][1] = 1;
                }

                for (int ni=2;ni<=n;ni++) {
                        int d = v[n-ni]-'0';
                        for (int hi=1;hi<=h;hi++) {
                                for (int i=1;i<=9;i++) {
                                        if (hi%i==0) {
                                                dp[ni][hi][0] += dp[ni-1][hi/i][0];
                                                if (i <= d)
                                                        dp[ni][hi][1] += dp[ni-1][hi/i][i==d];
                                        }
                                }
                        }
                }

                int sc = 0;
                for (int ni=1;ni<=n;ni++) {
                        for (int hi=1;hi<=h;hi++) {
                                sc += dp[ni][hi][ni==n];
                        }
                }

                return sc;
        };

        return cnt(r, y) - cnt(r, x-1) + cnt(l, x-1) - cnt(l, y);
}

int32_t main() {
        cout << solve() << "\n";
}
