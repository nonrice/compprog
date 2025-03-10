#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    set<int> s1, s2;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> a[i][j];
            s1.insert(a[i][j]);
        }
    }

    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (s1.count(a[i][j])){
                if ((j+1<m && a[i][j+1] == a[i][j]) || (i+1<n && a[i+1][j] == a[i][j])){
                    s1.erase(a[i][j]);
                    s2.insert(a[i][j]);
                }
            }
        }
    }
    
    if (s2.size() == 0){
        cout << s1.size()-1 << '\n';
    } else {
        cout << s1.size() + 2*(s2.size()-1) << '\n';
    }
}


int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
