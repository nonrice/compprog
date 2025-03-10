#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> a[i][j];
        }
    }
    vector<string> g(n);
    for (int i=0; i<n; ++i){
        cin >> g[i];
    }

    vector<vector<int>> p(n+1, vector<int>(m+1));
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=m; ++j){
            p[i][j] = ((g[i-1][j-1]=='1') ? 1 : -1) + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
    set<int> c;
    for (int i=0; i+k-1<n; ++i){
        for (int j=0; j+k-1<m; ++j){
            c.insert(abs(p[i+k][j+k] + p[i][j] - p[i][j+k] - p[i+k][j]));
        }
    }

    long long d = 0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (g[i][j] == '1'){
                d += a[i][j];
            } else {
                d -= a[i][j];
            }
        }
    }

    int h = *c.begin();
    for (auto v : c){
        if (v != 0){
            h = gcd(h, v);
        }
    }

    debug(c);
    debug(h, d);



    if ((d==0) || (h!=0 && d%h == 0)){
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