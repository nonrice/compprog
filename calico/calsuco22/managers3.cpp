#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<int>& szs, vector<vector<int>>& adj){
    int sz = 0;
    for (int chil : adj[cur]){
        dfs(chil, szs, adj);
        sz += (1+szs[chil]);
    }
    szs[cur] = sz;
}

void solve(){
    int n; cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    vector<int> szs(n);
    for (int i=0; i<n; ++i){
        int v; cin >> v;
        if (i>0) adj[v].push_back(i);
    }

    dfs(0, szs, adj);
    
    for (int& v : szs) {
        ++v;
    }
    
    long long ans = 0;
    for (int i=0; i<n; ++i) if (adj[i].size() > 0){
        long long cand = 0;
        long long sum = 0;
        for (auto it = adj[i].begin(); it!=adj[i].end(); ++it){
            sum += szs[*it];
            if (it!=adj[i].end()-1){
                cand += sum*szs[*(it+1)];
            }
        }
        ans = max(ans, cand+sum);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases; cin >> cases;
    while (cases--) solve();
}
