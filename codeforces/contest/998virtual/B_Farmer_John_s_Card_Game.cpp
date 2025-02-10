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

    vector<vector<int>> g(n, vector<int>(m));
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> g[i][j];
        }
        sort(g[i].begin(), g[i].end());
    }

    vector<int> p(n);
    for (int i=0; i<n; ++i){
        p[i] = i;
    }
    sort(p.begin(), p.end(), [&](const int a, const int b){
        return g[a][0] < g[b][0];
    });

    debug(g);

    for (int j=1; j<m; ++j){
        if (g[p[0]][j] < g[p[n-1]][j-1]){
            cout << "-1\n";
            return;
        }
        for (int i=1; i<n; ++i){
            if (g[p[i]][j] < g[p[i-1]][j]){
                cout << "-1\n";
                return;
            }
        }
    }

    for (auto x : p){
        cout << x+1 << ' ';
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