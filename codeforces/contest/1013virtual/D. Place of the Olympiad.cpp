#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long n, m, k; cin >> m >> n >> k;

    long long w = n;
    for (int s=n; s>=1; s/=2){
        while (w-s>=1 && m*(n - n/(w-s+1)) >= k){
            w -= s;
        }
    }

    cout << w << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
