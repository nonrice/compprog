#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    map<int, int> f;
    for (int i=0; i<n; ++i){
        ++f[a[i]%k];
    }

    int r = -1;
    for (auto [k, v] : f){
        if (v == 1){
            r = k;
            break;
        }
    }

    if (r == -1){
        cout << "NO\n";
        return;
    }

    for (int i=0; i<n; ++i){
        if (a[i]%k == r){
            cout << "YES\n";
            cout << i+1 << '\n';
            return;
        }
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}