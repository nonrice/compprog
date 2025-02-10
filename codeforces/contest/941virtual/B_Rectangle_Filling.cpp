#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (int i=0; i<n; ++i){
        cin >> g[i];
    }

    bool w[4] = {}, b[4] = {};
    for (int i=0; i<m; ++i){
        if (g[0][i] == 'W'){
            w[0] = true;
        } else {
            b[0] = true;
        }
        if (g[n-1][i] == 'W'){
            w[1] = true;
        } else {
            b[1] = true;
        }
    }

    for (int i=0; i<n; ++i){
        if (g[i][0] == 'W'){
            w[2] = true;
        } else {
            b[2] = true;
        }
        if (g[i][m-1] == 'W'){
            w[3] = true;
        } else {
            b[3] = true;
        }
    }

    if (w[0]+w[1]+w[2]+w[3] == 4 || b[0]+b[1]+b[2]+b[3] == 4){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}