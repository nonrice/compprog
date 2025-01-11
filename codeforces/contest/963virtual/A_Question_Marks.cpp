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

    string s; cin >> s;
    int f[4] = {};
    for (int i=0; i<4*n; ++i){
        if (s[i] != '?'){
            f[s[i]-'A']++;
        }
    }

    int ans = 0;
    for (int i=0; i<4; ++i){
        ans += min(n, f[i]);
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}