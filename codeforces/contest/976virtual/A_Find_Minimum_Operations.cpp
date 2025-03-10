#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long n, k; cin >> n >> k;

    if (k == 1 || k > n){
        cout << n << '\n';
        return;
    }

    long long p = 1;
    while (p*k <= n){
        p *= k;
    }

    int ans = 0;
    while (n && p){
        ans += n/p;
        n %= p;
        p /= k;
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