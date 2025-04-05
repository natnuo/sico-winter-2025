#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
 
#define int long long int
#define all(a) a.begin(), a.end()
 
int MAX_AI = 5000;
 
void solve() {
        int n;cin>>n;
        vector<int> a(n); for (int i=0;i<n;i++) cin >> a[i];
 
        vector<int> freq(MAX_AI+1);
        for (int i=0;i<n;i++) freq[a[i]]++;

        int sc = 0;
        vector<bool> isprime(2*MAX_AI+1, true);
        isprime[1] = false; isprime[0] = false;
        for (int i=2;i<=2*MAX_AI;i++) {
                if (isprime[i]) {
                        for (int j=2*i;j<=2*MAX_AI;j+=i) {
                                isprime[j] = false;
                        }

                        for (int v : a) {
                                int rem = i - v;
                                if (rem < 0 || rem > MAX_AI) continue;
                                int fac = freq[rem] - (v == rem);
                                sc += fac;
                        }
                }
        }

        cout << (sc/2) << "\n";
}
 
int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
}
