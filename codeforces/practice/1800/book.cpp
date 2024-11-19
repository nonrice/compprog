#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    vector<int> req(n);
    array<priority_queue<int, vector<int>, greater<int>>, 2> bfs;
    for (int u=0; u<n; ++u){
        int k; cin >> k;
        req[u] = k;
        if (k){
            while (k--){
                int v; cin >> v; --v;
                adj[v].push_back(u);
            }
        } else {
            bfs[0].push(u);
        }
    }

    int ans = 0;
    while (!bfs[ans&1].empty()){
        while (!bfs[ans&1].empty()){
            int u = bfs[ans&1].top(); bfs[ans&1].pop();
            for (int v : adj[u]){
                if (--req[v] <= 0){
                    if (u < v) bfs[ans&1].push(v);
                    else bfs[(ans&1) ^ 1].push(v);
                }
            }
        }
        ++ans;
    }

    for (int v : req){
        if (v){
            cout << "-1\n";
            return;
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
