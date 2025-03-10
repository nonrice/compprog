#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;

    vector<vector<int>> t(m+1, vector<int>(k, m+1));
    for (int i=m-1; i>=0; --i){
        for (int j=0; j<k; ++j){
            t[i][j] = t[i+1][j];
        }
        t[i][s[i]-'a'] = i+1;
    }

    string w(n, 'a');
    int p = 0;
    debug(t);
    for (int i=0; i<n; ++i){
        auto it = max_element(t[p].begin(), t[p].end());
        w[i] = 'a' + (it-t[p].begin());
        p = *it;

        if (p == m+1){
            cout << "NO\n";
            cout << w << '\n';
            return;
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