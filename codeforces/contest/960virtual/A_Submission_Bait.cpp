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
    map<int, int> f;
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        ++f[x];
    }

    for (auto [k, v] : f){
        if (v%2){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
    return;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}