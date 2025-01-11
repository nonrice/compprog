#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; ++i){
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string s; cin >> s;

    int c=0, x=0, y=0;
    for (int i=1; i<n; ++i){
        if (adj[i].size() == 1){
            if (s[i] == '?'){
                ++c;
            } else if (s[i] == '0'){
                ++x;
            } else if (s[i] == '1'){
                ++y;
            }
        }
    }
    int m = count(s.begin(), s.end(), '?') - c - (s[0] == '?');
    debug(c, x, y);
    debug(adj);

    if (s[0] != '?'){
        cout << ((c+1)/2 + ((s[0]=='1') ? x : y)) << '\n';
    } else {
        if (x == y){
            cout << (x + ((c + m%2)/2)) << '\n';
        } else {
            cout << max(x, y) + c/2 << '\n';
        }
    }

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        debug(t);
        solve();
    }
}