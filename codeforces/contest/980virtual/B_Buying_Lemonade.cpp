#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;
    long long k; cin >> k;
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long p = 0;
    long long s = 0;
    long long e = 0;
    for (int i=0; i<n; ++i){    
        s += (a[i]-p)*(n-i);

        if (s >= k){
            cout << k+e << '\n';
            return;
        }
        

        p = a[i];
        ++e;
    }

    cout << e+k << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}