#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;

void solve(){
    int n, m, k, q; cin >> n >> m >> k >> q;
    vector<pair<int, int>> ops(q);
    while (q--) cin >> ops[q].first >> ops[q].second;
    
    ll ans = 1;
    vector<bool> rs(n+1), cs(m+1);
    int tr=0, tc=0;
    for (auto& [r, c] : ops){
        if (!rs[r] || !cs[c]){
            tr += !rs[r];
            tc += !cs[c];
            rs[r] = cs[c] = true;

            ans = ans*k % MOD;
            if (tr==n || tc==m) break;
        }
    }

    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
