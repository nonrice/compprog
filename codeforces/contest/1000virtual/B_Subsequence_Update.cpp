#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, l, r; cin >> n >> l >> r;
    --l, --r;
    vector<int> f, m, b;
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        if (i < l){
            f.push_back(x);
        } else if (i > r){
            b.push_back(x);
        } else {
            m.push_back(x);
        }
    }

    sort(f.begin(), f.end());
    sort(m.rbegin(), m.rend());
    sort(b.begin(), b.end());

    long long s = accumulate(m.begin(), m.end(), 0LL);
    long long cur = s;
    long long ans = cur;
    for (int i=0; i<min(f.size(), m.size()); ++i){
        cur += f[i] - m[i];
        ans = min(ans, cur);
    }

    cur = s;
    for (int i=0; i<min(b.size(), m.size()); ++i){
        cur += b[i] - m[i];
        ans = min(ans, cur);
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