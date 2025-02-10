#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m; cin >> n >> m;

    vector<long long> a(n), b(m);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<m; ++i){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<long long> f({ 0 }), g({ 0 });
    for (int i=0; i<n-i-1; ++i){
        f.push_back(f.back() + a[n-i-1] - a[i]);
    }
    for (int i=0; i<m-i-1; ++i){
        g.push_back(g.back() + b[m-i-1] - b[i]);
    }

    vector<long long> ans;
    int t = 0;
    for (int k=1; k<=min(a.size()/2, b.size()); ++k){
        if (f[t] + g[k-t] )


    }

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}