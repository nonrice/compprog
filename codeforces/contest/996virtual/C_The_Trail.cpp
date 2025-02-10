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
    string s; cin >> s;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> a[i][j];
        }
    }
    
    int cr=0, cc=0;
    for (int i=0; i<n+m-1; ++i){
        long long t = 0;
        if (i == n+m-2 || s[i] == 'R'){
            for (int r=0; r<n; ++r){
                t += a[r][cc];
            }
        } else {
            for (int c=0; c<m; ++c){
                t += a[cr][c];
            }
        }
        a[cr][cc] = -t;
        
        if (i != n+m-2){
            if (s[i] == 'R'){
                ++cc;
            } else {
                ++cr;
            }
        }
    }

    for (int r=0; r<n; ++r){
        for (int c=0; c<m; ++c){
            cout << a[r][c] << ' ';
        }
        cout << '\n';
    }




}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}