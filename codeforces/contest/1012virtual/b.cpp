#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (int i=0; i<n; ++i){
        cin >> g[i];
    }
    
    vector<vector<bool>> c(n, vector<bool>(m));
    for (int i=0; i<n; ++i){
        for (int j=1; j<m; ++j){
            if (g[i][j] == '1' && g[i][j-1] == '0'){
                break;
            }
            c[i][j] = true;
        }
    }

    for (int j=0; j<m; ++j){
        for (int i=1; i<n; ++i){
            if (g[i][j] == '1' && g[i-1][j] == '0'){
                break;
            }
            c[i][j] = true;
        }
    }

    for (int i=1; i<n; ++i){
        for (int j=1; j<m; ++j){
            if (g[i][j]=='1' && !c[i][j]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
