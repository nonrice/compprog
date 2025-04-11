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
    
    vector<vector<int>> adj(n);
    vector<int> s(k);
    for (int i=0; i<k; ++i){
        cin >> s[i];
        --s[i];
    }
    for (int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    adj[0].push_back(s[0]);
    adj[s[0]].push_back(0);
    for (int i=1; i<k; ++i){
        adj[s[i]].push_back(s[i-1]);
        adj[s[i-1]].push_back(s[i]);
    }

    queue<int> q({ 0 });
    vector<int> d(n, -1);
    d[0] = 0;
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (auto v : adj[u]){
            if (d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    debug(d);

    for (int i=1; i<k; ++i){
        if (d[s[i]] <= d[s[i-1]]){
            cout << "-1\n";
            return;
        }
    }

    cout << (k - (s[0]==0)) << '\n';
    if (s[0] != 0){
        cout << "1 " << s[0]+1 << '\n';
    }
    for (int i=1; i<k; ++i){
        cout << s[i]+1 << ' ' << s[i-1]+1 << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
