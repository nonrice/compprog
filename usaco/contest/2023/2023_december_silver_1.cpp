#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct mv {
    ll u, v, x;
};

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> a(n);
    vector<set<int>> adj(n, set<int>());
    for (ll& v : a) cin >> v;
    for (int i=0; i<n-1; ++i){
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    const int t = accumulate(a.begin(), a.end(), 0LL)/n;

    queue<int> bfs;
    for (int i=0; i<n; ++i) if (adj[i].size() == 1) bfs.push(i);
    
    vector<mv> mvs, mvs_debt;
    while (!bfs.empty()){
        int u = bfs.front(); bfs.pop();

        //if (a[u]==t)

        //assert(adj[u].size() >= 1 || a[u]==t);
        int v = *(adj[u].begin());
        if (a[u] > t){
            mvs.push_back({ u, v, a[u]-t });
            a[v] += a[u]-t;
            a[u] = t;
            adj[v].erase(u);
            if (adj[v].size() == 1) bfs.push(v);
        } else if (a[u] < t){
            if (t-a[u] <= a[v]) mvs.push_back({ v, u, t-a[u] });
            else mvs_debt.push_back({ v, u, t-a[u] });
            a[v] -= t-a[u];
            a[u] = t;
            adj[v].erase(u);
            if (adj[v].size() == 1) bfs.push(v);
        }
    }

    reverse(mvs_debt.begin(), mvs_debt.end());
    cout << mvs.size() + mvs_debt.size() << '\n';
    for (auto [u, v, x] : mvs) cout << u+1 << ' ' << v+1 << ' ' << x << '\n';;
    for (auto [u, v, x] : mvs_debt) cout << u+1 << ' ' << v+1 << ' ' << x << '\n';;
}
