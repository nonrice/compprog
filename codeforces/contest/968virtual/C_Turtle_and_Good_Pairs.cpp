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

    int f[26] = {};
    for (int i=0; i<n; ++i){
        ++f[s[i]-'a'];
    }

    int p = 0;
    for (int i=0; i<n; ++i){
        while (f[p] == 0){
            p = (p+1) % 26;
        }
        --f[p];
        cout << (char('a'+p));
        p = (p+1) % 26;
    }

    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}