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

    vector<string> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    vector<vector<string>> b(m, vector<string>(n));
    for (int i=0; i<m; ++i){
        for (int j=0; j<n; ++j){
            cin >> b[i][j];
        }
    }

    vector<bool> t(n);
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (b[j][i] == a[i]){
                t[i] = true;
                break;
            }
        }
    
    
    if (count(t.begin(), t.end(), true) != n){
        cout << "-1\n";
        return;
    }
    
    int mn = INT_MAX;
    for (int i=0; i<m; ++i){
        int x = 0;
        for (int j=0; j<n; ++j){
            if (a[j] != b[i][j]){
                ++x;
            }
        }
        mn = min(mn, x);
    }
    
    cout << n + 2*mn << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
