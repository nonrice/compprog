#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
    
    bool operator<(const edge& o) const {
        return w < o.w;
    }
};

struct DSU {
    int* p;

    DSU(int sz){
        p = new int[sz];
        while (sz--) p[sz] = sz;
    }
    
    int find(int v){
        if (v == p[v]) return v;
        return p[v] = find(p[v]);
    }

    bool merge(int u, int v){
        int up = find(u);
        int vp = find(v);
        p[up] = vp;
        return up != vp;
    }

    ~DSU(){
        delete[] p;
    }
};


edge e[200000];

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int ek = INT_MAX;
    for (int i=0; i<m; ++i){
        cin >> e[i].u >> e[i].v >> e[i].w;
        --e[i].u;
        --e[i].v;
        ek = min(ek, abs(e[i].w - k));
    }
    
    sort(e, e+m);
    DSU mst(n);
    int cnt = 0;
    int x = 0;
    long long sum = 0;
    for (; x<m; ++x){
        if (mst.merge(e[x].u, e[x].v)){
            sum += max(0, e[x].w - k);
            if (++cnt == n-1){
                cout << max(sum , (long long)ek) << '\n';
                return;
            }
        }
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
