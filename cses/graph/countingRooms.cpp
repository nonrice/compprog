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

pair<int, int> D[] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int main(){
    int n, m; cin >> n >> m;
    vector<string> b(n);
    for (string& v : b) cin >> v;
    
    DSU dsu(n*m);
    for (int r=0; r<n; ++r) for (int c=0; c<m; ++c) if (b[r][c]=='.') {
        for (auto [dr, dc] : D){
            int tr = r + dr;
            int tc = c + dc;
            if (tr>=0 && tr<n && tc>=0 && tc<m && b[tr][tc]=='.'){
                dsu.merge(r*m + c, tr*m + tc);
            }
        }
    }

    int ans = 0;
    for (int i=0; i<n*m; ++i){
        ans += b[i/m][i%m] == '.' && dsu.p[i]==i;
    }

    cout << ans << '\n';
}
