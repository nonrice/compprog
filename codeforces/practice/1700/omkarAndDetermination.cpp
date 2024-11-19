#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (auto& r : g) cin >> r;
    
    vector<int> pref(m+1);
    for (int c=1; c<m; ++c){
        pref[c+1] = pref[c];
        for (int r=1; r<n; ++r){
            pref[c+1] += (g[r-1][c]=='X' && g[r][c-1]=='X');
        }
    }

    int q; cin >> q;
    while (q--){
        int l, r; cin >> l >> r;
        if (pref[r]-pref[l] == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
