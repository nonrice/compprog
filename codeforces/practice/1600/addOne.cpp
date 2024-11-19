#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll sz[200010], dig[10];

void solve(){
    string s; cin >> s;
    int m; cin >> m;
    
    ll ans = 0;
    for (char ch : s){
        ans = (ans + sz[(ch-'0') + m]) % MOD;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sz[0] = dig[0] = 1;
    for (int i=1; i<200010; ++i){
        for (int j=9; j>=1; --j){
            sz[i] = (sz[i] + dig[j-1]) % MOD;
            swap(dig[j], dig[j-1]);
        }
        sz[i] = (sz[i] + dig[0]*2) % MOD;
        dig[1] = (dig[1] + dig[0]) % MOD;
    }

    int cases; cin >> cases;
    while (cases--) solve();
}
