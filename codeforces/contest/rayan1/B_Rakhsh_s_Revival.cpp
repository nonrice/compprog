#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int l = 0;
    int r = 0;
    int ans = 0;
    for (int i=0; i<n; ++i){
        if (r != 0){
            --r;
            continue;
        }
        if (s[i] == '0'){
            ++l;
        } else {
            l = 0;
        }
        if (l == m){
            ++ans;
            r += k-1;
            l = 0;
        }
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