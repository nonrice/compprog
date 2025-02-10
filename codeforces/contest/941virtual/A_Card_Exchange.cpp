#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    map<int, int> f;
    for (int i=0; i<n; ++i){
        ++f[a[i]];
    }

    int t = 0;
    for (auto& [q, v] : f){
        t += v/k*(k-1);
        v %= k;
    }

    vector<int> g;
    for (auto& [k, v] : f){
        g.push_back(v);
    }
    sort(g.rbegin(), g.rend());

    for (auto& v : g){
        if (t-(k-v) >= 0){
            t -= (k-v);
            t += k-1;
            v = 0;
        }
    }

    cout << accumulate(g.begin(), g.end(), 0) + min(k-1, t) << '\n';



}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}