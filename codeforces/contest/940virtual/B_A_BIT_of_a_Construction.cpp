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

    if (n == 1){
        cout << k << '\n';
        return;
    }

    long long s = 0;
    while (((s<<1)|1) <= k){
        s <<= 1;
        s |= 1;
    }
    cout << s << ' ' << k-s << ' ';
    for (int i=0; i<n-2; ++i){
        cout << "0 ";
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}