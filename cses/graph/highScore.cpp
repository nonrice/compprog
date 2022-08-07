#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<tuple<int, int, ll>> e;
    while (m--){
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        e.emplace_back(--u, --v, w);
    }

    vector<ll> dist(n, LLONG_MIN);
    dist[0] = 0;
    for (int i=0; i<n-1; ++i){
        cout << i << '\n';
        for (auto [u, v, w] : e) if (dist[v] != LLONG_MIN) {
            dist[v] = max(dist[u]+w, dist[v]); 
        }
    }

    ll ans = dist.back();
    for (auto [u, v, w] : e) if (dist[v] != LLONG_MIN) {
        if (dist[u]+w > dist[v]) {
            cout << "-1\n"; 
            return 0;
        }
    }

    cout << ans << '\n';
}
