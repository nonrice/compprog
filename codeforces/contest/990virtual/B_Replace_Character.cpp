#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int fs[11] = { 1 };

void solve(){

    int n; cin >> n;
    string s; cin >> s;

    int ans = INT_MAX;
    string ans_s = s;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            string t = s;
            t[i] = t[j];

            int ps = fs[n];
            map<char, int> f;
            for (int i=0; i<n; ++i){
                ++f[t[i]];
            }
            for (auto [k, v] : f){
                ps /= fs[v];
            }

            if (ps < ans){
                ans = ps;
                ans_s = t;
            }
        }
    }

    debug(ans);
    cout << ans_s << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    for (int i=1; i<=10; ++i){
        fs[i] = fs[i-1]*i;
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}