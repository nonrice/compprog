#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;

    DSU(int sz){
        p = vector<int>(sz);
        while (sz--) p[sz] = sz;
    }
    
    int find(int v){
        if (v == p[v]) return v;
        return p[v] = find(p[v]);
    }

    void merge(int u, int v){
        p[find(u)] = find(v);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    DSU dsu(n+1);
    while (m--){
        int u, v; cin >> u >> v;
        dsu.merge(--u, --v);
    }
    
    int k = 0;
    vector<pair<int, int>> ans;
    for (int i=1; i<n; ++i){
        if (dsu.find(i) != dsu.find(0)){
            ans.emplace_back(1, i+1);
            dsu.merge(0, i);
            ++k;
        }
    }

    cout << k << '\n';
    for (auto& p : ans){
        cout << p.first << ' ' << p.second << '\n';
    }
}
