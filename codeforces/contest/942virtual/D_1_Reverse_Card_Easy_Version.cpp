#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

map<int, vector<int>> g;


constexpr int MXN = 2*1e6;

void solve(){
    int n, m; cin >> n >> m;

    int ans = 0;
    for (int b=1; b<=m; ++b){
        ans += upper_bound(g[b].begin(), g[b].end(), n) - g[b].begin();
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    for (int b=1; b<=MXN; ++b){
        for (int a=b; a<=MXN; a+=b){
            if ((a/b+1) % gcd(a, b) == 0){
                g[b].push_back(a);
            }
        }
    }
    for (auto& [a, b] : g){
        sort(b.begin(), b.end());
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}