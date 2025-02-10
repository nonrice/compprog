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
    int mx=INT_MIN, mn=INT_MAX;
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        mx = max(x, mx);
        mn = min(x, mn);
    }

    cout << mx-mn << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}