#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int AI_MAX = 5*1e3;
 
int32_t main() {
    int n;cin>>n;
    vector<int>a(n);for (int i=0;i<n;i++) cin >> a[i];
    
    vector<bool> isprime(2*AI_MAX+1, true);
    vector<int> primes;
    isprime[0] = false;
    isprime[1] = false;
    for (int i=2;i*i<=2*AI_MAX;i++) {
        if (isprime[i]) {
            for (int j=i+i;j<=2*AI_MAX;j+=i) {
                isprime[j] = false;
            }
        }
    }
    for (int i=0;i<=2*AI_MAX;i++)
        if (isprime[i])
            primes.push_back(i);
    
    vector<int> cnts(2*AI_MAX+1);
    int sc = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<primes.size();j++) {
            if (primes[j] - a[i] >= 0) {  // >= 1 should work too
                sc += cnts[primes[j] - a[i]];
            }
        }
        cnts[a[i]]++;
    }
    
    cout << sc << "\n";
}
