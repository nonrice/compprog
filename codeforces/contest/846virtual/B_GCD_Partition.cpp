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
    vector<long long> a(n);
    long long s = 0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        s += a[i];
    }

    long long p = 0;
    long long ans = 1;
    for (int i=0; i<n-1; ++i){
        p += a[i];
        s -= a[i];
        ans = max(ans, gcd(p, s));
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}