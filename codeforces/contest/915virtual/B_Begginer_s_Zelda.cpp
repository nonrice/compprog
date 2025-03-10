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

    vector<int> adj(n);
    for (int i=0; i<n-1; ++i){
        int u, v; cin >> u >> v;
        --u, --v;
        ++adj[u];
        ++adj[v];
    }

    int c = 0;
    for (int i=0; i<n; ++i){
        if (adj[i] == 1){
            ++c;
        }
    }

    debug(c);

    cout << 1 + ((c-1)/2) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}