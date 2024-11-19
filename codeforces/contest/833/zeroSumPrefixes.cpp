#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    vector<int> p(n);
    p[0] = a[0];
    // cout << p[0] << ' ';
    for (int i=1; i<n; ++i){
        p[i] = p[i-1]+a[i];
        // cout << p[i] << ' ';
    }
    // cout << '\n';

    vector<int> z;
    for (int i=0; i<n; ++i){
        if (a[i] == 0) z.push_back(i);
    }
    z.push_back(n);

    int ans = count(p.begin(), p.begin() + z[0], 0);
    for (int i=0; i<int32_t(z.size())-1; ++i){
        map<int, int> f;
        for (int j=z[i]; j<z[i+1]; ++j){
            ++f[p[j]];
        }
        int mxf = 0;
        for (auto [k, v] : f) mxf = max(mxf, v);
        ans += mxf;
    }
    cout << ans << '\n';
}

signed main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
